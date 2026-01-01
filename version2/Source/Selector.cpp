#include "../Headers/Selector.hpp"

void Selector::draw() {
	Texture* selectedTextureCopy;
	selectedTextureCopy = 
	layerManager_->get_texture_copy_at_coord(frame_->get_coord());
	if (selectedTextureCopy != nullptr) {
		selectedTextureCopy -> draw_shadow();
	}
	layerManager_ -> draw();
}


void Selector::handle_event(SDL_Event* event) {
	switch (event->type) {
		case SDL_EVENT_KEY_DOWN:
			if (event->key.scancode == SDLK_I) {
				this->switch_layer_forward();
			}
			else if (event->key.scancode == SDLK_P) {
				this->switch_layer_backward();
			}
			break;
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
			frame_ -> follow_mouse_motion();
			break;
		}

		default:
			break;
	}
}


bool Selector::is_mouse_in() {
	float x, y;
	SDL_GetMouseState(&x, &y);
	return x < width_;
}


Texture* Selector::get_selected_texture() {
	return layerManager_ -> get_texture_copy_at_coord(frame_->get_coord());
}

void Selector::switch_layer_forward() {
	++layerManager_;
}

void Selector::switch_layer_backward() {
	--layerManager_;
}

Selector::Selector(const int width) : width_(width) {
	layerManager_ = new LayerManager(width, {0.0f, 0.0f});
	frame_ = 
	new Frame({0.0f, 0.0f, TILE_DIM, TILE_DIM}, Color::red);
}


Selector::~Selector() {
	delete layerManager_;
	delete frame_;
}


void Selector::redimension_frame() {
	Texture* textureAtCoord;

	textureAtCoord = 
	layerManager_->get_texture_copy_at_coord(frame_->get_coord());

	frame_->set_width(textureAtCoord->get_width());
	frame_->set_height(textureAtCoord->get_height());
	frame_->set_upper_left_corner(textureAtCoord->get_upper_left_corner());
}
