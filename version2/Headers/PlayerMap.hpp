#ifndef PLAYER_MAP_H
#define PLAYER_MAP_H

#include "Window.hpp"
#include "Map.hpp"


class PlayerMap : public Map {
public:
	void draw() override;
	void handle_event(SDL_Event* event) override;

	// ------ CONSTRUCTORS ----------------------------
	PlayerMap();
	
	PlayerMap(std::vector<Texture*>::iterator itLandBegin,
						std::vector<Texture*>::iterator itLandEnd); 

	PlayerMap(const std::string& filename);
};
#endif
