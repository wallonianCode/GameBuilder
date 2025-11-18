#ifndef BUILD_STATE_H
#define BUILD_STATE_H


#include <iostream>
#include <SDL2/SDL.h>
#include <map>
#include "State.hpp"
#include "Tile.hpp"
#include "VideoPlayer.hpp"
#include "Trainer.hpp"

class BuildState : public State {
public:
	void process_events(bool&, StateMachine*, VideoPlayer*) override;
	void update(VideoPlayer*) override;
	void draw(VideoPlayer*) override;
private:
	void add_sprite(VideoPlayer*);
	void add_sprites(VideoPlayer*);
	void add_npc(VideoPlayer*);
	void add_registered_sprite(VideoPlayer*);
	void remove_sprite(VideoPlayer*);
	void remove_npc(VideoPlayer*);
	void add_frame(VideoPlayer*);

	Tile _registeredTile = Tile::grass1;
	std::vector<Tile> _registeredTiles;
	Trainer _registeredNpc;
	bool _addSpritesContinuously = false;
};


#endif
