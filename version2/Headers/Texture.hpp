#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>

#include "Drawable.hpp"
#include "TextureLoader.hpp"


const std::string leafGreenTextureFileName = "pkmnLeafGreenTileset2";
const int TILE_WIDTH = TILE_DIM;
const int TILE_HEIGHT = TILE_DIM;

class Texture;

// normally not necessary to overload
struct TexturePosComparator {
	bool operator()(const Texture& texture);
	bool operator()(Texture*);
	TexturePosComparator(const SDL_Point& pos);
	SDL_Point posOnScreen_;
};


class Texture : public Drawable {
public:
	virtual void draw() = 0; 
	virtual void update()	= 0;
	virtual void save(std::ostream&) const = 0;
	virtual Texture* clone() const = 0;
	virtual SDL_Point get_upper_left_corner() const = 0;
	virtual void set_pos_on_screen(const SDL_Point&) = 0;
	//TODO implement
	virtual void get_width() const = 0;
	virtual void get_height() const = 0;
private:
	std::string tileset_;		
};

#endif
