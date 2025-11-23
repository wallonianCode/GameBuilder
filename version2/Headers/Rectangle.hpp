#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Drawable.hpp"

//TODO rewrite as coord concept
class Rectangle : public Drawable  {
public:
	void draw();
	void draw_outline();
	
	int get_height() const;
	int get_width() const;
	int get_x() const;
	int get_y() const;

	void set_width(const int);
	void set_height(const int);

	SDL_Point get_position() const;
	SDL_Point get_coord() const;

	void set_pos_on_screen(const SDL_Point&);

	void set_color(const SDL_Color&);

	Rectangle();
	Rectangle(const SDL_Rect& areaOnScreen, const SDL_Color& color);
	Rectangle(const SDL_Point& posOnScreen, const int& width, 
	const int& height, const SDL_Color& color);
protected:
	SDL_Color color_;
	SDL_Rect* areaOnScreen_;
};

#endif
