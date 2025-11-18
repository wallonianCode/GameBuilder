#include "../Headers/PlayerMap.hpp"


void PlayerMap::draw() {
	Map::draw();
	red_.draw();
}


void PlayerMap::handle_event(SDL_Event& event) {
	//TODO
	std::cout << "PlayerMap::handle_event()" << std::endl;
}


PlayerMap::PlayerMap() : Map() {}


PlayerMap::PlayerMap(std::vector<Texture*>::iterator itLandBegin,
std::vector<Texture*>::iterator itLandEnd, 
std::vector<Character*>::iterator itCharBegin, 
std::vector<Character*>::iterator itCharEnd) : 
Map(itLandBegin, itLandEnd, itCharBegin, itCharEnd) {}


PlayerMap::PlayerMap(const std::string& filename) : Map(filename) {}




