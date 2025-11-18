#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//TODO is this class really necessary?
class Player {
public:
	static Player* get_instance();

private:
	Player();
	void init();
	static Player* instance_ ;
};

#endif
