#include "../Headers/Selector.hpp"

void Selector::draw() {
	Texture* selectedTextureCopy;

	selectedTextureCopy = 
	layerManager_->get_texture_copy_at_coord(frame_->get_coord());
	if (selectedTextureCopy_ != nullptr) {
		selectedTextureCopy -> draw_shadow();
	}
	layerManager_ -> draw();
}


void Selector::handle_event(SDL_Event& event) {
	switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_I) {
				switch_layer_forward();
			}
			else if (event.key.keysym.sym == SDLK_P) {
				switch_layer_backward();
			}
			break;
		case SDL_MOUSEBUTTONEVENT: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				frame_ -> immobilize();
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				frame_ -> free();
			}
			break;
		}
		case SDL_MOUSEMOTION: {
			frame_ -> update(this->get_current_texture_rectangle());
			break;
		}

		default:
			break;
	}
	layerManager_->handle_event(event);
}


bool Selector::is_mouse_in() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	return x < (int)width_;
}




Texture* Selector::get_texture_copy_at_coord() {
	return layerManager_->get_texture_copy_at_coord(frame_->get_coord());	
}


Selector::Selector(const int width) : width_(width) {
	layerManager_ = new LayerManager(width);
}


void Selector::switch_layer_forward() {
	++layerManager_;
}

void Selector::switch_layer_backward() {
	--layerManager_;
}


void Selector::redimension_frame() {
	Texture* textureAtCoord;

	textureAtCoord = 
	layerManager_->get_texture_copy_at_coord(frame_->get_coord());

	frame_.set_width(textureAtCoord->get_width());
	frame_.set_heigth(textureAtCoord->get_height());
	frame_.set_upper_left_corner(textureAtCoord->get_upper_left_corner());
}
