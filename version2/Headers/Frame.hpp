#ifndef	FRAME_H
#define FRAME_H

#include "Rectangle.hpp"
#include "Window.hpp"


class Frame : public Rectangle {
public:
	void draw() override;
	void draw_outline();
	void follow_mouse_motion();
	void immobilize();
	void free();
	
	Frame();
	Frame(const SDL_Rect& areaOnScreen, const SDL_Color& color);
	Frame(const SDL_Point& posOnScreen, const int& width, 
	const int& height, const SDL_Color& color);

private:
	bool isImmobilized_;

};

#endif
