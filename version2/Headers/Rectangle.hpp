#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Drawable.hpp"

//TODO rewrite as coord concept
class Rectangle : public Drawable  {
public:
	void draw();
	void draw_outline();
	
	float get_height() const;
	float get_width() const;
	float get_x() const;
	float get_y() const;

	void set_width(const float);
	void set_height(const float);

	SDL_FPoint get_position() const;
	SDL_FPoint get_coord() const;

	void set_upper_left_corner(const SDL_FPoint&);

	void set_color(const SDL_Color&);

	Rectangle();
	Rectangle(const SDL_Color&);
	Rectangle(const SDL_FRect&, const SDL_Color&);
	Rectangle(const SDL_FPoint&, const float&, 
			  const float&, const SDL_Color&);
protected:
	SDL_Color color_;
	SDL_FRect* areaOnScreen_;
};

#endif
