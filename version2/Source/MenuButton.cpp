#include "../Headers/MenuButton.hpp"


GameState* MenuButton::handle_event(SDL_Event& event) {
	GameState* nextState = nullptr;
	switch(event.type) {
		case SDL_MOUSEMOTION:
			if (Collider::is_mouse_inside_frame(event.motion, outRect_)) {
				activate();
			}
			else {
				deactivate();
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (Collider::is_click_inside_frame(event.button, outRect_)) {
				std::cout << 
				"MenuButton::handle_event(). Click is inside frame " << std::endl;
				//nextState = Button::click();
				nextState = this->get_next_state();
			}
			break;
		default:
			break;
	}
	return nextState;
}


MenuButton::MenuButton(const SDL_Point& posOnScreen, const int& width, 
const int& height, const int& frameThickness, 
const SDL_Color& frameColor, const SDL_Color& fillColor, 
const SDL_Color& clickedFillColor, const std::string& text) : 
TextButton(posOnScreen, width, height,
frameThickness, frameColor, fillColor, clickedFillColor, text) {}


MenuButton::MenuButton(const SDL_Point& posOnScreen, const int& width, 
const int& height, const int& frameThickness, 
const SDL_Color& frameColor, const SDL_Color& fillColor, 
const SDL_Color& clickedFillColor, const std::string& text, 
const SDL_Color& textColor) : 
TextButton(posOnScreen, width, height, frameThickness, frameColor, 
fillColor, clickedFillColor, text, textColor) {}


//------------------------- PROTECTED ------------------------------

int MenuButton::DefaultSettings::x = 
Window::get_instance()->get_width()/3 + 
Window::get_instance()->get_width()/12;


int MenuButton::DefaultSettings::yJump =
Window::get_instance()->get_height()/6;


int MenuButton::DefaultSettings::w =
Window::get_instance()->get_width()/6;


int MenuButton::DefaultSettings::h =
Window::get_instance()->get_height()/8;


int MenuButton::DefaultSettings::frameThickness =
Window::get_instance()->get_width()/64;


SDL_Color MenuButton::DefaultSettings::frameColor = Color::brown5;


SDL_Color MenuButton::DefaultSettings::fillColor = Color::brown4;

SDL_Color MenuButton::DefaultSettings::clickedFillColor = Color::brown2;

SDL_Color MenuButton::DefaultSettings::textColor = Color::black;
