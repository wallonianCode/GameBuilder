#include "../Headers/BuildState.hpp"


void BuildState::process_events(bool& running, StateMachine* stateMachine,
VideoPlayer* videoPlayer) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				std::cout << "Quitting the build state" << std::endl;
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button) {
					case SDL_BUTTON_RIGHT:
					  _addSpritesContinuously = false;	
						this->remove_sprite(videoPlayer);
						this->remove_npc(videoPlayer);
						break;
					case SDL_BUTTON_LEFT:
					  if (videoPlayer->is_mouse_in_build_selector()) {	
					  		_registeredTile = 
								videoPlayer->get_build_selector_tile_at_mouse_pos();		
								_registeredTiles =
								videoPlayer->get_build_selector_tiles_at_mouse_pos();
								_registeredNpc =
								videoPlayer->get_build_selector_npc_at_mouse_pos();
						}
						else if (VideoPlayer::is_mouse_in_build_separator()) {
							//do nothing
						}
						else {
					  	_addSpritesContinuously = true;	
							this->add_sprite(videoPlayer);
							this->add_sprites(videoPlayer);
							this->add_npc(videoPlayer);
						}
						break;
					default:
						break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				_addSpritesContinuously = false;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.scancode) {
					case SDL_SCANCODE_ESCAPE:
						_hasToBeRemoved = true;
						stateMachine->set_next_state(); 
						break;
					case SDL_SCANCODE_Q: 
						videoPlayer->set_next_build_selector_layer();
					  break;
					case SDL_SCANCODE_W:
						videoPlayer->increment_build_vertical_shift();
						break;
					case SDL_SCANCODE_E:
						videoPlayer->reset_build_shift();
						break;
					case SDL_SCANCODE_A:
						videoPlayer->decrement_build_horizontal_shift();	
						break;
					case SDL_SCANCODE_S:
						videoPlayer->decrement_build_vertical_shift();	
						break;
					case SDL_SCANCODE_D:
						videoPlayer->increment_build_horizontal_shift();	
						break;
					case SDL_SCANCODE_R:
						videoPlayer->add_red();
						break;
					case SDL_SCANCODE_T:
						{
							Trainer npc = Trainer(Tile::rocketFemale);
							std::vector<Direction> pattern =
							{Direction::South, Direction::South, Direction::South,
							Direction::East, Direction::East, Direction::East, 
							Direction::East, Direction::East, Direction::East, 
							Direction::East, Direction::East, Direction::North,
							Direction::North, Direction::North, Direction::North,
							Direction::North, Direction::West, Direction::West,
							Direction::West, Direction::West, Direction::West,
							Direction::West, Direction::West};
							npc.set_pattern(pattern.begin(), pattern.end());
							videoPlayer->add_npc(npc);
						}
					default:
						break;
			}
			default:
				if (_addSpritesContinuously) {
					if ((! videoPlayer->is_mouse_in_build_selector()) &&
					(! videoPlayer->is_mouse_in_build_separator())) {
						this->add_sprite(videoPlayer);
					}
				}
				break;
		}
	}
}


void BuildState::update(VideoPlayer* vp) {}


void BuildState::draw(VideoPlayer* vp) {
	if (!vp) throw std::runtime_error("BS::draw(): videoplayer is null!");
	vp->draw_build();	
}


void BuildState::add_sprite(VideoPlayer* vp) {
	vp->add_sprite_to_build_state(_registeredTile);
}


void BuildState::add_sprites(VideoPlayer* vp) {
	vp->add_sprites_to_build_state(_registeredTiles);
}


void BuildState::add_npc(VideoPlayer* vp) {
	vp->add_npc_to_build_state(_registeredNpc);
}


void BuildState::remove_sprite(VideoPlayer* vp) {
	vp->remove_sprite_from_build_state();
}


void BuildState::remove_npc(VideoPlayer* vp) {
	vp->remove_npc_from_build_state();
}


void BuildState::add_frame(VideoPlayer* vp) {}
