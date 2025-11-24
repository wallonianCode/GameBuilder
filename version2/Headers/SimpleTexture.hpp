#ifndef SIMPLETEXTURE_H
#define SIMPLETEXTURE_H

#include "Texture.hpp"


class SimpleTexture : public Texture {
public:
	SimpleTexture();
	//TODO implement
	SimpleTexture(const SDL_Point& );
	SimpleTexture(const std::string& tileset);
	SimpleTexture(const std::string& tileset, const SDL_Point& posOnScreen);
	// to override in case of bigger tiles (iterate over the src vector)
	virtual void draw(); 
	// to override in case of bigger tiles (the src may be a vector)
	void set_pos_on_screen(const SDL_Point&) override;
	SDL_Point get_upper_left_corner() const override;
	void set_dimensions_on_screen(const int& width, const int& height);
	
	virtual void update() override;	
	virtual void save(std::ostream&) const override;

	virtual void set_pos_on_tileset(const SDL_Point& pos);
	virtual void set_dim_on_tileset(const int, const int);
	
	virtual void save_dest(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream&, const Texture&);
	
	virtual SimpleTexture* clone() const = 0;

private:
	std::string tileset_;		
	SDL_Rect src_;
	SDL_Rect dest_;




};


#endif
