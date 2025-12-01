#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "TextButton.hpp"
#include "Window.hpp"

class GameState;


class MenuButton : public TextButton {
public:
	GameState* handle_event(SDL_Event& event);	

	
	MenuButton(const SDL_FPoint& posOnScreen, const float& width, 
			   const float& height, const int& frameThickness, 
			   const SDL_Color& frameColor, const SDL_Color& fillColor, 
			   const SDL_Color& clickedFillColor, const std::string& text);

	MenuButton(const SDL_FPoint& posOnScreen, const float& width, 
			   const float& height, const int& frameThickness, 
			   const SDL_Color& frameColor, const SDL_Color& fillColor, 
			   const SDL_Color& clickedFillColor, const std::string& text, 
			   const SDL_Color& textColor);

protected:
	virtual GameState* get_next_state() = 0;

	//TODO put definition into cpp file
	struct DefaultSettings {
		static float x; 
		static float yJump;// = Window::get_instance()->get_height()/6;
		static float w;// = Window::get_instance()->get_width()/6;
		static float h;// = Window::get_instance()->get_height()/8;
		static float frameThickness; //= Window::get_instance()->get_width()/24; 
		static SDL_Color frameColor;
		static SDL_Color fillColor;// = Color::brown4;
		static SDL_Color clickedFillColor;
		static SDL_Color textColor; //= Color::brown3;
	};
};

#endif
