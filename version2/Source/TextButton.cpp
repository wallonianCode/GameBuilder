#include "../Headers/TextButton.hpp"


void TextButton::draw() {
	Button::draw();
	text_->draw();
}


TextButton::TextButton(const SDL_FPoint& pos, const float& width, 
					   const float& height, const float& frameThickness, 
					   const SDL_Color& frameColor, const SDL_Color& fillColor, 
					   const SDL_Color& clickedFillColor, const std::string& text) : 
Button(pos, width, height, frameThickness, frameColor, fillColor, clickedFillColor) {
	Window* window = Window::get_instance();
	SDL_FPoint textPos =  {pos.x + window->get_width()/12, pos.y + window->get_height()/12};
	float textWidth = width-2*window->get_width()/12;
	float textHeight = height-2*window->get_height()/12;
	text_ = std::make_shared<Text>(text, textPos, textWidth, textHeight);
}


TextButton::TextButton(const SDL_FPoint& pos, const float& width, 
					   const float& height, const float& frameThickness, 
					   const SDL_Color& frameColor, const SDL_Color& fillColor, 
					   const SDL_Color& clickedFillColor, const std::string& text, 
					   const SDL_Color& textColor) : 
Button(pos, width, height, frameThickness, frameColor, fillColor, clickedFillColor) {
	SDL_FPoint textPos = {pos.x + width/10, pos.y + height/10};
	float textWidth = width-0.2*width;
	float textHeight = height-0.2*height;	
	text_ = std::make_shared<Text>(text, textPos, textWidth, textHeight, textColor);
}
