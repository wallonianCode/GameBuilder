#ifndef PLAYER_MAP_H
#define PLAYER_MAP_H

#include "Window.hpp"
#include "Map.hpp"
#include "Red.hpp"

class PlayerMap : public Map {
public:
	void draw() override;
	void handle_event(SDL_Event& event) override;

	// ------ CONSTRUCTORS ----------------------------
	PlayerMap();
	
	PlayerMap(std::vector<Texture*>::iterator itLandBegin,
						std::vector<Texture*>::iterator itLandEnd, 
						std::vector<Character*>::iterator itCharBegin, 
						std::vector<Character*>::iterator itCharEnd);

	PlayerMap(const std::string& filename);
private:
	Red red_ = Red({Window::get_instance()->get_width()/2, 
					  			Window::get_instance()->get_height()/2});
};
#endif
