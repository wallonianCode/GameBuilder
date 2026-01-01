#ifndef BUILDERSTATE_H
#define BUILDERSTATE_H

#include "GameState.hpp"
#include "Map.hpp"
#include "BuilderMap.hpp"


class BuilderState : public GameState {
public:
	GameState* process_event(bool&, SDL_Event*) override;
	void update() override;
	void draw() override;
	BuilderState();
private:
	BuilderMap* map_;
};

#endif
