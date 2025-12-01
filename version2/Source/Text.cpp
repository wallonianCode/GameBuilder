#include "../Headers/Text.hpp"


void Text::draw() {
	Renderer* renderer = Renderer::get_instance();
	// Surface creation
	SDL_Surface* textSurface = 
	TTF_RenderText_Solid(font_, text_.c_str(), 0, color_);
	if (!textSurface)
		throw std::runtime_error("Text::draw(): surface not created");

	// Texture creation
	SDL_Texture* textTexture = 
	SDL_CreateTextureFromSurface(renderer->get_sdl_renderer(), textSurface);
	if (! textTexture)
		throw std::runtime_error("Text::draw(): texture not created");


	// Texture rendering 
	SDL_RenderTexture(renderer->get_sdl_renderer(), textTexture, 
	NULL, areaOnScreen_);
  
	SDL_DestroySurface(textSurface);
	SDL_DestroyTexture(textTexture);
}


void Text::highlight() {
	color_ = highlightColor_;
}


void Text::stop_highlighting() {
	color_ = defaultColor_;
}


Text::Text(const std::string& text, const SDL_FPoint& textPos,
const float& textWidth, const float& textHeight, 
const SDL_Color& defaultColor, const SDL_Color& highlightColor, 
const char* fontPath) : 
text_(text), color_(defaultColor),
defaultColor_(defaultColor), highlightColor_(highlightColor) {
	font_ = FontLoader::load_font(fontPath);
	areaOnScreen_ = 
	new SDL_FRect{textPos.x, textPos.y, textWidth, textHeight};
}
