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

	void set_pos_on_screen(const SDL_FPoint&);

	void set_color(const SDL_Color&);

	Rectangle();
	Rectangle(const SDL_FRect& areaOnScreen, const SDL_Color& color);
	Rectangle(const SDL_FPoint& posOnScreen, const float& width, 
	const float& height, const SDL_Color& color);
protected:
	SDL_Color color_;
	SDL_FRect* areaOnScreen_;
};

#endif
