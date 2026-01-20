#include "../Headers/MenuButton.hpp"


GameState* MenuButton::handle_event(SDL_Event* event) {
	GameState* nextState = nullptr;
	switch(event->type) {
		case SDL_EVENT_MOUSE_MOTION:
			if (Collider::is_mouse_inside_frame(event->motion, outRect_)) {
				activate();
			}
			else {
				deactivate();
			}
			break;
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			if (Collider::is_click_inside_frame(event->button, outRect_)) {
				//nextState = Button::click();
				nextState = this->get_next_state();
			}
			break;
		default:
			break;
	}
	return nextState;
}


MenuButton::MenuButton( 
const SDL_FPoint& posOnScreen, const float& width, 
const float& height, const int& frameThickness, 
const SDL_Color& frameColor, const SDL_Color& fillColor, 
const SDL_Color& clickedFillColor, const std::string& text) : 
TextButton(posOnScreen, width, height,
frameThickness, frameColor, fillColor, clickedFillColor, text) {}


MenuButton::MenuButton(const SDL_FPoint& posOnScreen, const float& width, 
					   const float& height, const int& frameThickness, 
					   const SDL_Color& frameColor, const SDL_Color& fillColor, 
					   const SDL_Color& clickedFillColor, const std::string& text, 
					   const SDL_Color& textColor) : 
TextButton(posOnScreen, width, height, frameThickness, frameColor, 
fillColor, clickedFillColor, text, textColor) {}


//------------------------- PROTECTED ------------------------------

float MenuButton::DefaultSettings::x = 
Window::get_instance()->get_width()/3 + 
Window::get_instance()->get_width()/12;


float MenuButton::DefaultSettings::yJump =
Window::get_instance()->get_height()/6;


float MenuButton::DefaultSettings::w =
Window::get_instance()->get_width()/6;


float MenuButton::DefaultSettings::h =
Window::get_instance()->get_height()/8;


float MenuButton::DefaultSettings::frameThickness =
Window::get_instance()->get_width()/64;


SDL_Color MenuButton::DefaultSettings::frameColor = Color::brown5;


SDL_Color MenuButton::DefaultSettings::fillColor = Color::brown4;

SDL_Color MenuButton::DefaultSettings::clickedFillColor = Color::brown2;

SDL_Color MenuButton::DefaultSettings::textColor = Color::black;
