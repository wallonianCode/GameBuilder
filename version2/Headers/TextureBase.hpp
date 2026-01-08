#ifndef TEXTUREBASE_H
#define TEXTUREBASE_H

#include <string>
#include "Drawable.hpp"

//TODO solve the problem with texture cloneable that demands non pure virtual class
const std::string leafGreenTextureFileName = "pkmnLeafGreenTileset2";
const int TILE_WIDTH = TILE_DIM;
const int TILE_HEIGHT = TILE_DIM;

/*
class Texture;

// normally not necessary to overload
struct TexturePosComparator {
	bool operator()(const Texture& texture);
	bool operator()(Texture*);
	TexturePosComparator(const SDL_Point& pos);
	SDL_Point posOnScreen_;
};
*/


class TextureBase : public Drawable {
public:
	virtual void draw() = 0; 
	virtual void draw_shadow() = 0;
	virtual void update() = 0;
	virtual SDL_FPoint get_upper_left_corner() const = 0;
	virtual void set_upper_left_corner(const SDL_FPoint&) = 0;
	virtual void set_pos_on_tileset(const SDL_FPoint&) = 0;
	virtual void set_dim_on_tileset(const int, const int) = 0;
	virtual float get_width() const = 0;
	virtual float get_height() const = 0;
	virtual bool is_coord_in_texture(const SDL_FPoint&) const = 0;
};

#endif
