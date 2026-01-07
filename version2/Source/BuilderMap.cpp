#include "../Headers/BuilderMap.hpp"


void BuilderMap::draw() {
	Renderer *renderer;
	renderer = Renderer::get_instance();
	SDL_SetRenderDrawColor(renderer->get_sdl_renderer(), 0, 0, 0, 255);
	SDL_RenderClear(renderer->get_sdl_renderer());
	grassBackground_->draw();
	Map::draw(); //draw textures
	selector_->draw();
	separator_->draw();
	if (!separator_->is_mouse_in()) {
		this->draw_frame();
	}
}


void BuilderMap::handle_event(SDL_Event* event) {
	if (selector_->is_mouse_in()) {
		selector_->handle_event(event);
		switch(event->type) { //frame
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				break;
			/*
				if (event->button.button == SDL_BUTTON_LEFT) {
					frame_ -> immobilize();
				}
				else if (event->button.button == SDL_BUTTON_RIGHT) {
					frame_ -> free();
				}
				break;
			}
			*/
			case SDL_EVENT_MOUSE_MOTION: {
				frame_ -> follow_mouse_motion();
				break;
			}
			default:
				break;
		}
		//this->handle_mouse_motion_events(event);
	}
	else if (separator_->is_mouse_in()) {
		separator_->handle_event(event);
	}
	else { //mouse in the map
		switch(event->type) {
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				switch (event->button.button) {	
					case SDL_BUTTON_LEFT:
						if (selector_->get_selected_texture() != nullptr) {
							Map::add_texture_at_mouse_pos(
							selector_->get_selected_texture());	
						}		
						break;
					case SDL_BUTTON_RIGHT:
						Map::remove_texture_at_mouse_pos();
						break;
					default:
						break;
				}
			case SDL_EVENT_KEY_DOWN:
				switch (event->key.scancode) {
					case SDL_SCANCODE_L:
						std::cout << "L case pressed" << std::endl;
						selector_->switch_layer_forward();
						break;
					case SDL_SCANCODE_K:
						selector_->switch_layer_backward();
						break;
					default:
						break;
				}
				break;
			default: 
				break;
		}
	}
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
	SDL_WarpMouseInWindow(window->get_sdl_window(), 0.0f, 0.0f);
	selector_ = std::make_shared<Selector>(SELECTOR_WIDTH);
	separator_ = std::make_shared<Separator>();
	grassBackground_ = std::make_shared<GrassBackground>(window->get_width(), window->get_height());
}
