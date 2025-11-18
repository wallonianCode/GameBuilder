#include "../Headers/Selector.hpp"

void Selector::draw() {
	aLayers_[layerId_]->draw();
}

//TODO handle event in the selector, not in the layer!
// The layer is only there for presentation purposes
void Selector::handle_event(SDL_Event& event) {
//	aLayers_[layerId_]->handle_event(event);
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
	Texture* selectedTile = nullptr;
	try {
		selectedTile = 
		aLayers_[layerId_]->get_texture_at_coord(frame_->get_position());
	}
	catch (std::runtime_error& error){
		std::cout << error.what() << std::endl;
		return nullptr;
	}
	std::cout << "Selector::get_selected_texture() is not null: " << 
	(selectedTile != nullptr) << std::endl;
	return selectedTile;
}


std::vector<Texture*> Selector::get_selected_textures() {
	std::vector<Texture*> vTextures;
	if (layerId_ == 1) {//big land
		try {
			vTextures = aLayers_[layerId_]->get_selected_textures();	
		}
		catch (std::runtime_error& error) {
			std::cout << error.what() << std::endl;
		}
	}
	return vTextures;
}


Selector::Selector() {
	init();
}


Selector::Selector(const int width) : width_(width) {
	init();
}


void Selector::init() {
	aLayers_ = { new LandLayer(width_),
							 new BigLandLayer(width_),
							 new CharacterLayer(width_)};
	layerId_ = 0;
}


void Selector::switch_layer() {
	if (layerId_ >= aLayers_.size()-1) 
		layerId_ = 0;
	else 
		layerId_++;
	std::cout << "Layer id: " << layerId_ << std::endl;
}


//TODO call this in the game loop
void Selector::redimension_frame() {
	frame_.set_width(aLayers_[layerId_]->get_texture_width());
	frame_.set_height(aLayers_[layerId_]->get_texture_height());
  frame_.set_position_on_screen(aLayers_[layerId_])->
	get_texture_coordinates();
}


/*
void Selector::switch_layer() {
	std::array<Layer*, 3>::iterator itCurrentLayer =
	std::find(aLayers_.begin(), aLayers_.end(), layer_);
//TODO clear the renderer 	
	if (itCurrentLayer == aLayers_.end()) {
		std::cout << "Current layer not in internal representation" <<
		std::endl;
  }
	else if ((itCurrentLayer + 1) == aLayers_.end()) {
		layer_->reset(aLayers_[0]); 	
	}
	else {
		layer_->reset(*(itCurrentLayer + 1));
	}
}
*/


/*
void Selector::switch_layer() {
	switch (currentLayerName_) {
		case LayerName::Land:
			layer_ = new BigLandLayer(width_);
			currentLayerName_ = LayerName::BigLand;
			break;
		case LayerName::BigLand:
			layer_ = new CharacterLayer(width_);
			currentLayerName_ = LayerName::Character;
			break;
		case LayerName::Character:
			layer_ = new LandLayer(width_);
			currentLayerName_ = LayerName::Land;
			break;
		default:
			break;
	}
*/
