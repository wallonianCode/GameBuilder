#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include <string>
#include <memory>
#include "Text.hpp"
#include "Button.hpp"

class TextButton : public Button {
public:
	void draw() override;
	
	TextButton(const SDL_FPoint&, const float& width, 
	const float& height, const float& frameThickness, 
	const SDL_Color& frameColor, const SDL_Color& fillColor, 
	const SDL_Color& clickedFillColor, const std::string& text);


	TextButton(const SDL_FPoint&, const float& width, 
	const float& height, const float& frameThickness, 
	const SDL_Color& frameColor, const SDL_Color& fillColor, 
	const SDL_Color& clickedFillColor, const std::string& text, 
	const SDL_Color& textColor);

private:
	std::shared_ptr<Text> text_ = nullptr;
};

#endif
