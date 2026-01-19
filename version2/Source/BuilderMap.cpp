#include "../Headers/BuilderMap.hpp"


void BuilderMap::draw() {
	Renderer *renderer;
	renderer = Renderer::get_instance();
	SDL_SetRenderDrawColor(renderer->get_sdl_renderer(), 0, 0, 0, 255);
	SDL_RenderClear(renderer->get_sdl_renderer());
	grassBackground_->draw();
	Map::draw(); //draw textures
	selector_->draw(frame_);
	separator_->draw();
	this->draw_frame();
}


void BuilderMap::handle_event(SDL_Event* event) {
	selector_->handle_event(event);
	//selector_->redimension_frame(frame_);	
	if (selector_->is_mouse_in()) {
		switch(event->type) { //frame
			case SDL_EVENT_MOUSE_BUTTON_DOWN: {
				if (event->button.button == SDL_BUTTON_LEFT) {
					frame_ -> immobilize();
				}
				else if (event->button.button == SDL_BUTTON_RIGHT) {
					frame_ -> free();
				}
				break;
			}
			case SDL_EVENT_MOUSE_MOTION: {
				if (this->was_out_of_selector()) {
					frame_ -> free();		
					this->set_out_of_selector(false);
				}
				frame_ -> follow_mouse_motion();
				//selector_->adjust_frame_position(frame_);
				break;
			}
			default:
				break;
		}
	}
	else if (separator_->is_mouse_in()) {
		separator_->handle_event(event);
		this->set_out_of_selector(true);
	}
	else { //mouse in the map
		switch(event->type) {
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				switch (event->button.button) {	
					case SDL_BUTTON_LEFT:
					{
					  Texture* tCopy = selector_->get_selected_texture(frame_);
						std::cout << "BuilderMap::handle_event(): " <<
						(tCopy == nullptr) << " " << 
						tCopy->get_upper_left_corner().x << ":" <<
						tCopy->get_upper_left_corner().y << std::endl;
						if (selector_->get_selected_texture(frame_) != nullptr) {
							Map::add_texture_at_mouse_pos(
							selector_->get_selected_texture(frame_));	
						}		
						break;
					}
					case SDL_BUTTON_RIGHT:
						Map::remove_texture_at_mouse_pos();
						break;
					default:
						break;
				}	
			default: 
				break;
		
				
		}
	}
}


bool BuilderMap::was_out_of_selector() {
	return this->outOfSelector_;
}


void BuilderMap::set_out_of_selector(const bool out) {
	this->outOfSelector_ = out;
}


void BuilderMap::handle_mouse_motion_events(SDL_Event* event) {
	switch(event->type) {
	  case SDL_EVENT_MOUSE_MOTION: {
			float x, y, xTile, yTile;
			SDL_GetMouseState(&x, &y);
			xTile = x - ((int)x % TILE_DIM);
			yTile = y - ((int)y % TILE_DIM);
			this->set_frame_pos({xTile, yTile});	
			break;	
		}
		default:
			break;
	}
}




BuilderMap::BuilderMap() {
	Window* window;

	window = Window::get_instance();
	SDL_WarpMouseInWindow(window->get_sdl_window(), 
	MOUSE_STARTING_POSITION.x, MOUSE_STARTING_POSITION.y);
	selector_ = std::make_shared<Selector>(SELECTOR_WIDTH);
	separator_ = std::make_shared<Separator>();
	grassBackground_ = 
	std::make_shared<GrassBackground>(window->get_width(), 
	window->get_height());
	outOfSelector_ = false;
}
