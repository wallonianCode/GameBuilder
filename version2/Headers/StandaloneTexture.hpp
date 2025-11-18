#ifndef STANDALONETEXTURE_H
#define STANDALONETEXTURE_H


#include  "Anime.hpp"


class StandaloneTexture : public Anime {
public:
	// Constructor
	StandaloneTexture(const std::string& tileset, 
										const SDL_Point& posOnScreen);

	friend std::ostream operator<<(std::ostream&, 
																 const StandaloneTexture&);

};

#endif
