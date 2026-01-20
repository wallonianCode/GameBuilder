#include "../Headers/PlayerMap.hpp"


void PlayerMap::draw() {
	Map::draw();
	//red_.draw();
}


void PlayerMap::handle_event(SDL_Event& event) {
	//TODO
	std::cout << "PlayerMap::handle_event()" << std::endl;
}


PlayerMap::PlayerMap() : Map() {}


PlayerMap::PlayerMap(
std::vector<std::shared_ptr<Texture>>::iterator itLandBegin,
std::vector<std::shared_ptr<Texture>>::iterator itLandEnd) : 
Map(itLandBegin, itLandEnd) {}


PlayerMap::PlayerMap(const std::string& filename) : Map(filename) {}




