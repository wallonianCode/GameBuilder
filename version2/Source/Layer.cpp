#include "../Headers/Layer.hpp"


Layer::Layer(const int& width): width_(width) {
	std::cout << "Layer::Layer(): width: " << width_ << std::endl;
	init_grid();
}


void Layer::draw() {
	for (std::vector<Texture*>::iterator itTiles = vTiles_.begin();
	itTiles != vTiles_.end(); itTiles++) {
		(*itTiles)->draw();
	}	
}


void Layer::handle_event(SDL_Event& event) {}


Texture* get_texture_at_position(const SDL_Point& position) {
  // Declarations
  std::string errMsg;
  Texture* textureAtPos;
  TexturePosComparator comparator(position);

  // Body
  Texture* textureAtPos = 
  std::find_if(vTiles_.begin(), vTiles.end(), comparator);

	// Error management
	if ( textureAtPos == vTiles_.end() ) {
	 errMsg =  "Texture not found at pos: (" + position.x + ", " + 
	 position.y + ")"; 
	 throw new std::runtime_error(errMsg);
}

// Return statement
return textureAtPos;
}


/*
Texture* Layer::get_selected_tile() {
	return selectedTile_;
}


std::vector<Texture*> Layer::get_selected_textures() {
	return selectedTextures_;
}
 */


void Layer::add_texture(Texture* texture) {
	vTiles_.push_back(texture);
}


void Layer::set_selected_tile(Texture* texture) {
	std::cout << "Layer::set_selected_tile()" << std::endl;
	std::vector<Texture*> emptyVector;
	//TODO destroy the pointers
	selectedTextures_ = emptyVector;
	selectedTile_ = texture;
}


void Layer::set_selected_textures(std::vector<Texture*> vTextures) {
	selectedTile_ = nullptr;
	selectedTextures_ = vTextures;
}


SDL_Point Layer::get_pos_on_grid(const int index) {
	return arPos_[index];
}


Texture* Layer::get_texture_at_coord(const SDL_Point& coord) {
	// the texture to be returned
  Texture* foundTexture	= nullptr;
	// get the index in the array pos
	int columnNb = width_/TILE_DIM + 1;
	unsigned index = pos.y*columnNb + pos.x;
	std::cout << "Layer::handle_event(): selected tile at index: "
	<< index << " Nb of registered textures " << 
	vTiles_.size() << std::endl;
	if (index < arPos_.size()) {
		// get the tile corresponding to this pos	
		auto foundTextureIt = std::find_if(vTiles_.begin(),
		vTiles_.end(), TexturePosComparator(arPos_[index]));
		if (foundTextureIt != vTiles_.end()) {
			std::cout << "Texture was found at index: " << index <<
			std::endl;
			foundTexture = (*foundTextureIt)->clone();							
		}
	}
	std::cout << "Layer::get_texture_at_pos() is null: " <<
	(foundTexture == nullptr) << std::endl;
	return foundTexture;
}




void Layer::init_grid() {
	int x = 0, y = 0;
	int columnNb = width_ / TILE_DIM;
	std::cout << "Layer::init_grid(): columnNb: " << columnNb <<
	" width: " << width_ << " Tile dim: " << TILE_DIM << std::endl;
	for (unsigned i = 0; i != arPos_.size(); i++) {
		arPos_[i] = {x*TILE_DIM, y*TILE_DIM};	
		if (x >= columnNb) {
			x = 0;
			y++;
		}
		else {
			x++;
		}
	}
}


void Layer::select_texture() {	
	// get mouse position 
	SDL_Point tileCoord = MapUtils::get_tile_coord_at_mouse_pos();
	selectedTile_ = get_texture_at_pos(tileCoord);	
}
