#ifndef BUILD_H
#define BUILD_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <tuple>
#include <algorithm>
#include <fstream>
#include "FormDrawer.hpp"

enum class Layer {layer1, layer2, layer3};


class Build : public FormDrawer {
public:
	Build(SDL_Renderer*, SDL_Window*, const int&);
  void draw(SDL_Window*) override;
	std::vector<sprite>::iterator get_sprite_at(const SDL_Rect& pos); 
	std::vector<Trainer>::iterator get_npc_at(const SDL_Rect&);
	std::vector<sprite> get_sprites_at(const SDL_Rect& pos);
		
	Tile get_build_selector_tile_at_mouse_pos();
	std::vector<Tile> get_build_selector_tiles_at_mouse_pos();
	Trainer get_build_selector_npc_at_mouse_pos();
	std::vector<frame>::iterator get_frame_at(const SDL_Rect& pos);

	void add_sprite_at_mouse_pos(const Tile&);
	void add_sprites_at_mouse_pos(const std::vector<Tile>&);
	//TODO add pattern as argument
	void add_npc_at_mouse_pos(Trainer); 
	//TODO add layer check

	void remove_sprite_at_mouse_pos();
	void remove_npc_at_mouse_pos();
	void add_frame_at_mouse_pos();
	void remove_frame_at_mouse_pos();
  bool is_mouse_in_build_selector();
	void set_next_build_selector_layer();
 	void erase_sprite_set(std::vector<sprite>::iterator itSprite);
	SDL_Rect get_outline_rect_in_selector_at_mouse_pos();
	static int get_left_boundary();
	static int get_separator_right_boundary();
	static bool is_mouse_in_selector();
	static bool is_mouse_in_separator();
	void save();
private:
	void init_build_selector();
	void free_rect(const SDL_Rect&);
	void free_rect_from_npc(const SDL_Rect&);
  bool is_tile_taken(const SDL_Rect&);
	std::vector<sprite> _spritesBuildSelectorLayer1;
	std::vector<sprite> _spritesBuildSelectorHugeTree;
	std::vector<sprite> _spritesBuildSelectorPinTree;
	std::vector<sprite> _spritesBuildSelectorSlenderPinTree;
  std::vector<Trainer> _npcsBuildSelector;	
	std::vector<sprite> _spritesBuildSeparator;
	const int _leftBoundary;
	Layer _layer;
};

#endif
