#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stack>
#include <exception>
#include "State.hpp"
#include "MenuState.hpp"
#include "BuildState.hpp"
#include "PlayState.hpp"
#include "StateMachine.hpp"
#include "VideoPlayer.hpp"
#include "TextureLoader.hpp"


//TODO state machine: soliton
/*
  Create a three-color view for the menu
	Add buttons to the menu
	Notice a click on the buttons
  Maybe refactor by creating a Button class
	Implement the behavior of the buttons: once clicked, you switch to a 
	different class
	Improve the version-control system
*/
class Game {
public:
	static Game* get_instance();
	void initialize();
	void run();

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	~Game();
private:
	Game();
	static Game* _instance;
  StateMachine* _stateMachine;
	VideoPlayer* _videoPlayer;
};

#endif
