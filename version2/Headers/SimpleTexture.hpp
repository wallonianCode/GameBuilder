#ifndef SIMPLETEXTURE_H
#define SIMPLETEXTURE_H

#include "Texture.hpp"
#include "TextureCloneable.hpp"


class SimpleTexture : public Texture {
public:
	SimpleTexture();
	SimpleTexture(const SDL_FPoint&);
	SimpleTexture(const std::string& tileset);
	SimpleTexture(const std::string& tileset, const SDL_FPoint& posOnScreen);
	// to override in case of bigger tiles (iterate over the src vector)
	virtual void draw() override; 
	// to override in case of bigger tiles (the src may be a vector)
	void set_upper_left_corner(const SDL_FPoint&) override;
	SDL_FPoint get_upper_left_corner() const override;
	void set_dimensions_on_screen(const int& width, const int& height);
	
	virtual void update() override;	
	//virtual void save(std::ostream&) const override;

	virtual void set_pos_on_tileset(const SDL_FPoint& pos);
	virtual void set_dim_on_tileset(const int, const int);

	
	//virtual SimpleTexture* clone() const = 0;

	static float get_width();
	static float get_height();

private:
	std::string tileset_;		
	SDL_FRect src_;
	SDL_FRect dest_;
};


#endif
