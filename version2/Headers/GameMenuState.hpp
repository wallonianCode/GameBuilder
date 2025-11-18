#ifndef GAMEMENUSTATE_H
#define GAMEMENUSTATE_H

#include "GameState.hpp"
#include "GameMenu.hpp"

class GameMenuState : public GameState {
public:
	GameState* process_events(bool&) override;
	void update() override;
	void draw() override;
	GameMenuState();
private:
	std::shared_ptr<GameMenu> menu_;
};

#endif
