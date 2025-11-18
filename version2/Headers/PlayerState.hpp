#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H


#include "GameState.hpp"
#include "PlayerMap.hpp"


class PlayerState : public GameState {
public:
	GameState* process_events(bool&) override;
	void update() override;
	void draw() override;
	PlayerState();
private:
	std::shared_ptr<PlayerMap> map_;
	
};

#endif
