#include "../Headers/BuilderMap.hpp"


void BuilderMap::draw() {
	std::cout << "BuilderMap::draw()" << std::endl;
	grassBackground_->draw();
	std::cout << "BuilderMap::draw(): grassBackground drawn" << std::endl;
	Map::draw(); //draw textures
	std::cout << "BuilderMap::draw(): textures drawn" << std::endl;
	selector_->draw();
	std::cout << "BuilderMap::draw(): selector drawn" << std::endl;
	separator_->draw();
	std::cout << "BuilderMap::draw(): separator drawn" << std::endl;
	if (!separator_->is_mouse_in()) {
		this->draw_frame();
	}
	std::cout << "BuilderMap::draw() end" << std::endl;
}


void BuilderMap::handle_event(SDL_Event& event) {
	std::cout << "BuilderMap::handle_event: begin" << std::endl;
	if (selector_->is_mouse_in()) {
		selector_->handle_event(event);
		//this->handle_mouse_motion_events(event);
	}
	else if (separator_->is_mouse_in()) {
		separator_->handle_event(event);
	}
	else {
		this->handle_mouse_motion_events(event);
		switch(event.type) {
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				switch (event.button.button) {	
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
				switch (event.key.scancode) {
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
	std::cout << "BuilderMap::handle_event end" << std::endl;
}


void BuilderMap::handle_mouse_motion_events(SDL_Event& event) {
	switch(event.type) {
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
	std::cout << "BuilderMap::BuilderMap" << std::endl;
	selector_ = std::make_shared<Selector>(SELECTOR_WIDTH);
	separator_ = std::make_shared<Separator>();
	grassBackground_ = std::make_shared<GrassBackground>();
	std::cout << "BuilderMap::BuilderMap end" << std::endl;
}
