#ifndef BUTTON_H
#define BUTTON_H

#include "Rectangle.hpp"
#include "Collider.hpp"
#include "GameState.hpp"


class Button : public Drawable {
public:	
	virtual void draw();
	virtual GameState* handle_event(SDL_Event& event);

	void activate();
	void deactivate();
	virtual GameState* click();

	Button(const SDL_Point& posOnScreen, const int& width, 
	const int& height, const int& frameThickness, 
	const SDL_Color& frameColor, const SDL_Color& fillColor,
	const SDL_Color& clickedFillColor);

protected:
	Rectangle outRect_;
	Rectangle inRect_;

private:
	SDL_Color inColor_;

	SDL_Color inactiveColor_;
	SDL_Color activeColor_;
};

#endif
