#include "../Headers/BigLandLayer.hpp"


BigLandLayer::BigLandLayer(const int& width) : Layer(width) {
	//TODO add the composite textures
	init();
	//frame_ = new Frame({0, 0, 3*TILE_DIM, 4*TILE_DIM}, Color::red);
}


void BigLandLayer::handle_event(SDL_Event& event) {
	switch (event.type)	{
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT) {
				this->set_textures();				
			}
			break;
		default:
			break;
	}
}

void BigLandLayer::init() {
	//TODO
	this->add_big_texture(new HugeTree(0, 0));
	this->add_big_texture(new PinTree(HugeTree::get_width() + TILE_DIM, 0));
	this->add_big_texture(new SlenderPinTree(0, 
	HugeTree::get_height() + TILE_DIM));
}


//TODO useful? Should the layer know by heart where the textures are?
//     not with the new system.
SDL_Point BigLandLayer::get_composite_texture_pos() const {
	SDL_Point tileCoord = MapUtils::get_tile_coord_at_mouse_pos(),
						composedTexturePos;
	if (tileCoord.x <= HugeTree::get_width()/TILE_DIM && 
			tileCoord.y <= HugeTree::get_height()/TILE_DIM) {
		composedTexturePos = { 0, 0 };
	}
	else if (tileCoord.x > HugeTree::get_width()/TILE_DIM &&
					 tileCoord.x <= HugeTree::get_width()/TILE_DIM +
					 PinTree::get_width() &&
					 tileCoord.y <= PinTree::get_height()) {
		composedTexturePos = { HugeTree::get_width() + TILE_DIM, 0 };
	}
	else if (tileCoord.x <= SlenderPinTree::get_width()/TILE_DIM &&
					 tileCoord.y > HugeTree::get_width()/TILE_DIM && 
					 tileCoord.y <= SlenderPinTree::get_height()/TILE_DIM +
					 								SlenderPinTree::get_height()/TILE_DIM) {
		composedTexturePos = { 0, HugeTree::get_height() + 
															SlenderPinTree::get_height() };
	}
	else {
		//TODO error
		std::cout << "BigLandLayer::get_composed_texture_pos() found no \
		corresponding texture" << std::endl;
	}
}

//TODO refactor
Texture* get_texture_at_mouse_pos() const {
	return this->get_texture_at_pos(get_composed_texture_pos());
}

