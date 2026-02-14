#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>

#include "TextureBase.hpp"

#include "TextureLoader.hpp"
#include "TextureCloneable.hpp"


// dummy class to make the CRTP work
class Texture : public TextureBase {
public:
	virtual void draw() override; 
	virtual void draw_shadow() override;
	virtual void update() override;
	virtual SDL_FPoint get_upper_left_corner() const override;
	virtual void set_upper_left_corner(const SDL_FPoint&) override;
	virtual void set_pos_on_tileset(const SDL_FPoint&) override;
	virtual void set_dim_on_tileset(const int, const int) override;
	virtual Texture* clone() const ;
	virtual float get_width() const;
	virtual float get_height() const;
	virtual	bool is_coord_in_texture(const SDL_FPoint&) const override;
	// Get tile coordinates (upper left corner for textures) out of pos
	static SDL_FPoint get_tile_coord(const SDL_FPoint&);
	// Set texture position to tile coord corresponding to pos
	void set_upper_left_corner_to_tile_coord(const SDL_FPoint&);
	virtual TextureTableEntry get_entry() const override;
	Texture(const Texture&);
	Texture(const std::string&);
	Texture();
protected:
	std::string get_tileset();
private:
	std::string tileset_;		
};
	
#endif
