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
	Texture(const std::string&);
	Texture();
protected:
	std::string tileset_;		
};
	
#endif
