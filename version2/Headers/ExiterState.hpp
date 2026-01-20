#ifndef EXITERSTATE_H
#define EXITERSTATE_H

#include <memory>
#include "GameState.hpp"
#include "Color.hpp"
#include "BlackBackground.hpp"


class ExiterState : public GameState {
public:
	GameState* process_event(bool& running, SDL_Event* event) override;
	void update() override;
	void draw() override;
	ExiterState();
private:
	std::shared_ptr<BlackBackground> background_;
};

#endif
