#ifndef FONTLOADER_H
#define FONTLOADER_H

#include <iostream>
#include <string>
#include <unordered_map>


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


class FontLoader {
public:
	static TTF_Font* load_font(const char* path);
	static std::unordered_map<const char*, TTF_Font*> mFonts;
};


#endif
