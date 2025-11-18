#ifndef ANIME_H
#define ANIME_H

#include <iostream>
#include <string>

#include "Drawable.hpp"


class Anime : public Drawable {
public:
	// Constructor
	Anime(const std::string& tileset, const SDL_Point& posOnScreen); 

	// Dimensions and position 
	virtual void set_pos_on_screen(const SDL_Point&) = 0;
	virtual void set_dim on_screen(const int&, const int&) = 0;


	// Updating 
	virtual void update() = 0;
	
	// Saving
	virtual void save_dest(std::ostream&) const = 0;
	friend std::ostream& operator<<(std::ostream&, const Texture&);

	// Cloning
	virtual Texture* clone() const = 0;

private:
	// Initialization
	virtual void init_src() = 0;

	// Members
	std::string tileset_;
};


#endif
