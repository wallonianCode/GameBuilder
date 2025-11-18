#include "../Headers/LandLayer.hpp"


LandLayer::LandLayer(const int& width) : Layer(width) {
	init();
	this->set_selected_tile(new Grass(get_pos_on_grid(1),
	Grass::Format::Type::GreenWhite));
}


//TODO make use of the factory
//TODO replace this get_pos_on_grid function if necessary,
// maybe by a structure(layerWidth) or a static structure that 
// recomputes the grid as a function of the width given as param
// Any given layer necessarily has to hold a grid, which is a separate
// thing
void LandLayer::init() {
	Layer::add_texture(
	TextureFactory::createSimpleTexture(get_pos_on_grid(0), 
																			SimpleTextureEnum::Sand));
	Layer::add_texture(new Grass(get_pos_on_grid(1), 
	Grass::Format::Type::GreenWhite));
	Layer::add_texture(new Grass(get_pos_on_grid(2), 
										 Grass::Format::Type::GreenWhiteGreen));
	Layer::add_texture(new Grass(get_pos_on_grid(3), 
	Grass::Format::Type::Green));
	Layer::add_texture(new Grass(get_pos_on_grid(4), 
	Grass::Format::Type::White));

	for (int i = 0; i < 8; i++) {
		Layer::add_texture(new SandRoad(get_pos_on_grid(i+5),
											 static_cast<LeafGreenTexture::Side::Type>(i)));
		Layer::add_texture(new MoosRoad(get_pos_on_grid(i+13),
											 static_cast<LeafGreenTexture::Side::Type>(i)));
		Layer::add_texture(new RockRoad(get_pos_on_grid(i+21),
											 static_cast<LeafGreenTexture::Side::Type>(i)));
		Layer::add_texture(new ShallowWater(get_pos_on_grid(i+29),
											 static_cast<LeafGreenTexture::Side::Type>(i)));
		Layer::add_texture(new DeepWater(get_pos_on_grid(i+37),
											 static_cast<LeafGreenTexture::Side::Type>(i)));
	}
	Layer::add_texture(new TallGrass(get_pos_on_grid(45)));
	Layer::add_texture(new SmallTree(get_pos_on_grid(46)));
	Layer::add_texture(new Flowers(get_pos_on_grid(47)));
	for (int i = 0; i < 9; i++)
	{
		Layer::add_texture(new GreenBorder(get_pos_on_grid(i+48),
										   static_cast<Border::Side::Type>(i)));
		Layer::add_texture(new GreyBorder(get_pos_on_grid(i+57),
											 static_cast<Border::Side::Type>(i)));
	}	
}
