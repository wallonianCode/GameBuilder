#include "../Headers/Selector.hpp"

void Selector::draw() {
	std::cout << "Selector::draw(): begin " << std::endl;
	Texture* selectedTextureCopy;
	selectedTextureCopy = 
	layerManager_->get_texture_copy_at_coord(frame_->get_coord());
	std::cout << "Selector::draw(): texture copy at coord got " << std::endl;
	if (selectedTextureCopy != nullptr) {
		selectedTextureCopy -> draw_shadow();
	}
	std::cout << "Selector::draw(): shadow drawn" << std::endl;
	layerManager_ -> draw();
	std::cout << "Selector::draw(): end " << std::endl;
}


void Selector::handle_event(SDL_Event* event) {
	switch (event->type) {
		case SDL_EVENT_KEY_DOWN:
			std::cout << "Selector::handle_event(SDL_Event* event) " << std::endl;
			switch (event->key.scancode) {
				case (SDL_SCANCODE_L) :
					this->switch_layer_forward();
					std::cout << "Selector::handle_event(SDL_Event* event): " << 
					"layer switched" << std::endl;
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
	std::cout << "Selector::handle_event(SDL_Event* event): end" << std::endl;
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
	++(*layerManager_);
}

void Selector::switch_layer_backward() {
	--(*layerManager_);
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
