#include "../Headers/Selector.hpp"

void Selector::draw() {}

void Selector::draw(Frame* frame) {
	Texture* selectedTextureCopy;
	selectedTextureCopy = 
	layerManager_->get_texture_copy_at_coord(frame->get_coord());
	if (selectedTextureCopy != nullptr) {
		selectedTextureCopy -> draw_shadow();
	}
	layerManager_ -> draw();
}


void Selector::handle_event(SDL_Event* event) {
	switch (event->type) {
		case SDL_EVENT_KEY_DOWN:
			switch (event->key.scancode) {
				case (SDL_SCANCODE_L) :
					this->switch_layer_forward();
					break;
				case (SDL_SCANCODE_K) :
					this->switch_layer_backward();
					break;
				default:
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


Texture* Selector::get_selected_texture(Frame* frame) {
	return layerManager_ -> get_texture_copy_at_coord(frame->get_coord());
}

void Selector::switch_layer_forward() {
	++(*layerManager_);
}

void Selector::switch_layer_backward() {
	--(*layerManager_);
}

Selector::Selector(const int width) : width_(width) {
	layerManager_ = new LayerManager(width, {0.0f, 0.0f});
}


Selector::~Selector() {
	delete layerManager_;
}


void Selector::redimension_frame(Frame* frame) {
	Texture* textureAtCoord;
	textureAtCoord = 
	layerManager_->get_texture_copy_at_coord(frame->get_coord());
	if (textureAtCoord == nullptr) {
		frame->set_width(TILE_DIM);
		frame->set_height(TILE_DIM);
	}
	else {
		frame->set_width(textureAtCoord->get_width());
		frame->set_height(textureAtCoord->get_height());
		frame->set_upper_left_corner(textureAtCoord->get_upper_left_corner());
	}
}


void Selector::adjust_frame_position(Frame* frame) {
	Texture* textureAtCoord;

	textureAtCoord = 
	layerManager_->get_texture_copy_at_coord(frame->get_coord());
	if (textureAtCoord != nullptr) {
		frame->set_upper_left_corner(textureAtCoord->get_upper_left_corner());
	}
}
