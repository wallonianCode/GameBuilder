#include "../Headers/GrassBackground.hpp"


GrassBackground::GrassBackground(const float width, const float height) {
	std::vector<SimpleTextureEnum> line1, line2;
	std::vector<SimpleTextureEnum>::iterator lineItBegin, 
											 lineItEnd, 
											 lineIt;
	int x, y;

	line1 = {SimpleTextureEnum::GreenWhiteGreenGrass,
	 		 SimpleTextureEnum::GreenWhiteGrass,
	         SimpleTextureEnum::GreenGrass,
	         SimpleTextureEnum::WhiteGrass};

	line2 = {SimpleTextureEnum::GreenGrass,
			 SimpleTextureEnum::WhiteGrass,
			 SimpleTextureEnum::GreenWhiteGreenGrass,
			 SimpleTextureEnum::WhiteGrass};

	
	for (y = 0; y < height - TILE_DIM; ++y) {
		lineItBegin = y % 2 == 0 ? line1.begin() : line2.begin();
		lineItEnd = y % 2 == 0 ? line1.end() : line2.end();
		lineIt = lineItBegin;
		for (x = 0; x < width - TILE_DIM; ++x) {
			 vGrass_.push_back(
			 TextureFactory::create_simple_texture({x, y}, *lineIt++));
			 if (lineIt == lineItEnd) {
				 lineIt = lineItBegin;
			 }
		}
	}
}


GrassBackground::GrassBackground() {
	Window* window = Window::get_instance();
	GrassBackground(window->get_width(), window->get_height());
}


void GrassBackground::draw() {
	std::vector<SimpleTexture*>::iterator itGrass;
	for (itGrass = vGrass_.begin(); itGrass != vGrass_.end(); ++itGrass) {
		(*itGrass)->draw();
	}
}
