#include "../Headers/TextButton.hpp"


void TextButton::draw() {
	Button::draw();
	text_->draw();
}


TextButton::TextButton(const SDL_Point& posOnScreen, const int& width, 
const int& height, const int& frameThickness, 
const SDL_Color& frameColor, const SDL_Color& fillColor, 
const SDL_Color& clickedFillColor, const std::string& text) : 
Button(posOnScreen, width, height,
frameThickness, frameColor, fillColor, clickedFillColor) {
	Window* window = Window::get_instance();
	SDL_Point textPos = {posOnScreen.x + window->get_width()/12,
	posOnScreen.y + window->get_height()/12};
	int textWidth = width-2*window->get_width()/12;
	int textHeight = height-2*window->get_height()/12;
	text_ = std::make_shared<Text>(text, textPos, textWidth, textHeight);
}


TextButton::TextButton(const SDL_Point& posOnScreen, const int& width, 
const int& height, const int& frameThickness, 
const SDL_Color& frameColor, const SDL_Color& fillColor, 
const SDL_Color& clickedFillColor, const std::string& text, 
const SDL_Color& textColor) : 
Button(posOnScreen, width, height, frameThickness, frameColor,
fillColor, clickedFillColor) {
	SDL_Point textPos = {posOnScreen.x + width/10,
	posOnScreen.y + height/10};
	int textWidth = width-0.2*width;
	int textHeight = height-0.2*height;
	
	text_ = std::make_shared<Text>(text, textPos, textWidth, textHeight, 
	textColor);
}
