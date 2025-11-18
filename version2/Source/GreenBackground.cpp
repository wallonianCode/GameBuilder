#include "../Headers/GreenBackground.hpp"


void GreenBackground::draw() {
	for(std::vector<Grass>::iterator itTexture = 
	vGrass.begin(); itTexture != vGrass.end();
	itTexture++) {
		itTexture->draw();
	}
}


GreenBackground::GreenBackground() : Background(Color::green) {
	Window* window = Window::get_instance();
	int x = 0, y = 0;
	
	// Muster format arrays
	Grass::Format formats1[4] = 
	{Grass::Format::Type::GreenWhite, 
	Grass::Format::Type::GreenWhiteGreen,
	Grass::Format::Type::Green, 
	Grass::Format::Type::White};

	Grass::Format formats2[4] = {
	Grass::Format::Type::Green, 
	Grass::Format::Type::White,
	Grass::Format::Type::GreenWhite,
	Grass::Format::Type::GreenWhiteGreen};

	// the current format order being drawn
	Grass::Format *formats = formats1;
	while (x != window->get_width()) {
		int i = 0;
		while (y != window->get_height()) {
			vGrass.push_back(Grass({x, y}, formats[i]));
			i++;
			if (i >= 4) {
				if (formats == formats1) formats = formats2;
				else formats = formats1;
				i = 0;
			}
			y += TILE_DIM;
		}
		y = 0;
		x += TILE_DIM;
	}
}
