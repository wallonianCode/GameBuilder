#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

#include "Rectangle.hpp"
#include "Texture.hpp"
#include "Frame.hpp"


class Map : public Drawable {
public:
	virtual void draw() override;
	virtual void handle_event(SDL_Event& event) = 0;

	// write textures and characters to a save file
	//void save(const std::string& fileName);
	// load the textures from a saved file
	//void load(const std::string& fileName);
	
	// add a texture (tile or character) to map
	void add_texture(std::shared_ptr<Texture>);

	void add_texture_at_mouse_pos(std::shared_ptr<Texture>);

	// remove a texture (tile or character) from map
	//TODO return a boolean
	void remove_texture(const SDL_FPoint& posOnScreen);

	void remove_texture_at_mouse_pos();

  // update all the textures of the map
	void update();

	void set_frame_pos(const SDL_FPoint&);
	void draw_frame();

	//	------- CONSTRUCTORS -----------------------
	
	// create an empty map
	Map();	
	Map(const std::string& filename);

	Map(std::vector<std::shared_ptr<Texture>>::iterator itLandBegin,
		  std::vector<std::shared_ptr<Texture>>::iterator itLandEnd);
	
private:
	std::vector<std::string> split(std::string, const std::string&);
	std::vector<std::shared_ptr<Texture>> vTextures_;
	// shows the cursor, can be moved with keyboard keys
	Frame frame_;	
};

#endif
