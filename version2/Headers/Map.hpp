#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Rectangle.hpp"
#include "Texture.hpp"
#include "TextureCreator.hpp"
#include "Character.hpp"
#include "Frame.hpp"
#include "TexturePositionComparator.hpp"


class Map : public Drawable {
public:
	virtual void draw() override;
	virtual void handle_event(SDL_Event& event) = 0;

	// write textures and characters to a save file
	void save(const std::string& fileName);
	// load the textures from a saved file
	void load(const std::string& fileName);
	
	// add a texture (tile or character) to map
	void add_texture(Texture*);

	void add_texture_at_mouse_pos(Texture*);

	void add_textures_at_mouse_pos(std::vector<Texture*>);

	// remove a texture (tile or character) from map
	//TODO return a boolean
	void remove_texture(const SDL_Point& posOnScreen);

	void remove_texture_at_mouse_pos();

  // update all the textures of the map
	void update();

	void set_frame_pos(const SDL_Point&);
	void draw_frame();

	//	------- CONSTRUCTORS -----------------------
	
	// create an empty map
	Map();	
	Map(const std::string& filename);

	Map(std::vector<Texture*>::iterator itLandBegin,
		  std::vector<Texture*>::iterator itLandEnd,
			std::vector<Character*>::iterator itCharacterBegin,
			std::vector<Character*>::iterator itCharacterEnd);
	
private:
	std::vector<std::string> split(std::string, const std::string&);
	std::vector<Texture*> vTextures_;
	std::vector<Character*> vCharacters_;	
	// shows the cursor, can be moved with keyboard keys
	Frame frame_;	
};

#endif
