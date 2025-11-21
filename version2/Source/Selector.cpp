#include "../Headers/Selector.hpp"

void Selector::draw() {
	//aLayers_[layerId_]->draw();
	if (selectedTextureCopy_ != nullptr) {
		selectedTextureCopy_ -> draw_shadow();
	}
	if (layerManager_ != nullptr) {
		layerManager_ -> draw();
	}
	else {
		//TODO error management
	}
}

//TODO handle event in the selector, not in the layer!
// The layer is only there for presentation purposes
void Selector::handle_event(SDL_Event& event) {
//	aLayers_[layerId_]->handle_event(event);
/*
	switch (event.type) {  			
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT) {
				//this->select_texture();			
			  frame_->immobilize();	
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
			  frame_->free();	
			}
			break;
		case SDL_MOUSEMOTION: 
			frame_->follow_mouse_motion();
			this->redimension_frame();
			break;
		default:
			break;
	}
*/
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
				selectedTextureCopy_ = layerManager_->get_selected_texture();
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				selectedTextureCopy_ = nullptr;
			}
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


bool Selector::get_layer_id() {
	return layerId_;
}


Texture* Selector::get_selected_texture() {
	return layerManager_->get_selected_texture();
	/*
	Texture* selectedTile = nullptr;
	try {
		selectedTile = 
		aLayers_[layerId_]->get_texture_at_coord(frame_->get_position());
	}
	catch (std::runtime_error& error){
		std::cout << error.what() << std::endl;
		return nullptr;
	}
	return selectedTile;
	*/
	
}





Selector::Selector(const int width) : width_(width) {
	layerManager_ = new LayerManager(width);
}

/*
void Selector::init() {
	aLayers_ = { new LandLayer(width_),
				 new BigLandLayer(width_),
				 new CharacterLayer(width_)};
	layerId_ = 0;
}
*/

void Selector::switch_layer_forward() {
	/*
	if (layerId_ >= aLayers_.size()-1) 
		layerId_ = 0;
	else 
		layerId_++;
	std::cout << "Layer id: " << layerId_ << std::endl;
	*/
	layerManager_++;
}

void Selector::switch_layer_backward() {
	layerManager_--;
}


//TODO call this in the game loop
/*
void Selector::redimension_frame() {
  frame_.set_width(aLayers_[layerId_]->get_texture_width());
  frame_.set_height(aLayers_[layerId_]->get_texture_height());
  frame_.set_position_on_screen(aLayers_[layerId_])->
	get_texture_coordinates();
}
	*/