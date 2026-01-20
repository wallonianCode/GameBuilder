#ifndef TEXT_H
#define TEXT_H

#include "Drawable.hpp"
#include "FontLoader.hpp"


class Text : Drawable {
public:
	void draw() override;

	void highlight();
	void stop_highlighting();

	Text(const std::string&, const SDL_FPoint&, 
	const float& textWidth, const float& textHeight,
	const SDL_Color& defaultColor = Color::red, 
	const SDL_Color& highlightColor = Color::white,
	const char* fontPath = "Fonts/open-sans-regular.ttf");
private:
	std::string text_;
	TTF_Font* font_;
	SDL_FRect* areaOnScreen_;
	SDL_Color color_;
	SDL_Color defaultColor_;
	SDL_Color highlightColor_;
};

#endif
