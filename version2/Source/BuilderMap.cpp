#include "../Headers/BuilderMap.hpp"


void BuilderMap::draw() {
	greenBackground_->draw();
	Map::draw(); //draw textures
	selector_->draw();
	separator_->draw();
	if (!separator_->is_mouse_in()) {
		this->draw_frame();
	}
}


void BuilderMap::handle_event(SDL_Event& event) {
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
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button) {	
					case SDL_BUTTON_LEFT:
						/*
						if (selector_->get_selected_texture() != nullptr) {
							Map::add_texture_at_mouse_pos(
							selector_->get_selected_texture());	
						}
						*/
						if (selector_->get_selected_textures().size() != 0) {
							Map::add_textures_at_mouse_pos(
							selector_->get_selected_textures());
						}
						else {
							std::cout << "No selected texture as for now" << 
							std::endl;
						}
						break;
					case SDL_BUTTON_RIGHT:
						Map::remove_texture_at_mouse_pos();
						break;
					default:
						break;
				}
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_l:
						std::cout << "L case pressed" << std::endl;
						selector_->switch_layer();
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


void BuilderMap::handle_mouse_motion_events(SDL_Event& event) {
	switch(event.type) {
	  case SDL_MOUSEMOTION: {
			int x, y, xTile, yTile;
			SDL_GetMouseState(&x, &y);
			xTile = x - (x % TILE_DIM);
			yTile = y - (y % TILE_DIM);
			this->set_frame_pos({xTile, yTile});	
			break;	
		}
		default:
			break;
	}
}




BuilderMap::BuilderMap() {
	selector_ = std::make_shared<Selector>(SELECTOR_WIDTH);
	separator_ = std::make_shared<Separator>();
	greenBackground_ = std::make_shared<GreenBackground>();
}
