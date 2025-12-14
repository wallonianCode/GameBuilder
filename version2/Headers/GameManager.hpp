#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include <cmath>
#include <SDL3/SDL_timer.h>
#include "Renderer.hpp"
#include "GameStateMachine.hpp"

class GameManager {
public:
	static GameManager* get_instance();
	void run();

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
private:
	GameManager();
	static GameManager* instance_;
};

#endif
