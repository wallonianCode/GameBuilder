#include "../Headers/FontLoader.hpp"


std::unordered_map<const char*, TTF_Font*> FontLoader::mFonts;

TTF_Font* FontLoader::load_font(const char* path) {
  if (mFonts.find(path) == mFonts.end()) {
		TTF_Font* font = TTF_OpenFont(path, 24);
		if (! font) {
			std::cout << TTF_GetError() << std::endl;
			throw std::runtime_error("FL::load_font could not load: " + 
			std::string(path));
		}
		mFonts.insert({path, font});
	}
	return mFonts.find(path)->second;
}

