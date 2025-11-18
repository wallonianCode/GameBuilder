#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>

#include "Drawable.hpp"
#include "TextureLoader.hpp"
#include "TextureCloneable.hpp"


//TODO in order to develop composedTexture, make virtual the methods
// 	   you will need to overload.
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
	//virtual void save_dest(std::ostream&) const = 0;
	//friend std::ostream& operator<<
	//(std::ostream&, const Texture&) const = 0;	
	virtual Texture* clone() const = 0;
	virtual SDL_Point get_pos_on_screen() const = 0;
	virtual void set_pos_on_screen() = 0;
protected:
	virtual std::string to_str() const = 0;
private:
	std::string tileset_;		
};

#endif
