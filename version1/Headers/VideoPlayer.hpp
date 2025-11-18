#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <exception>

#include "Color.hpp"
#include "FormDrawer.hpp"
#include "Menu.hpp"
#include "Build.hpp"
#include "Play.hpp"
#include "Exit.hpp"
#include "TextureLoader.hpp"
#include "Tile.hpp"
#include "Constants.hpp"

const std::string WINDOW_TITLE = "Build a Game";

const int MOUSE_START_X = 10;
const int MOUSE_START_Y = 10;


//TODO
/*
 * ---------------------------------------------------------------------
 * refactor
 * -> add all the necessary #includes (<vector>, parent classes, window)
 * -> verify the frame in the BuilderMap
 * -> have a look at the Collider
 * -> verify the handle_event methods of PlayerMap and BuilderMap
 * -> have a look at the TextureLoader
 * -> write the brendan class
 * -> write the tree class 
 * -> write the bigtree class, derived from bigSprite class
 * -> look at every class, hunt possible compilation faults. Introduce
 			the keyword "virtual" everywhere it was forgotten. Transform 
			pointers into shared_ptr where it makes sense.
 * -> save a whole character with his side_ without the map having to 
 			know about it. Maybe write load methods for textures, and
			character overwrites it
 * --------------------------------------------------------------------
 * finish GIT lesson -> save the whole on GitHub
 * learn UML Basics -> write a basic UML diagram of the game and upload it
 * --------------------------------------------------------------------
 * learn VIM enough to significantly improve user experience
 * --------------------------------------------------------------------
 * make the movements more fluid
 * build: don't set the trainer on a tile where he cannot be
 * trainer fishes.
 * trainer runs.
 * trainer on bicycle.
 * trainer surfes.
 * introduce houses: enter them. First blank state, then loaded-up maps. 
 * speed has to be adapted. 5 is not enough, the character throws one leg 
 * back.
 * introduce caves
 * collision management for trainers.
 * try to adapt the frame rate
 * increase the window size
 * introduce sound
 * introduce snow, rain (if possible)
 * introduce sand
 * By this time, the non interactive map should work as in pkmn games.
 * --------------------------------------------------------------------- 
 * save everything on GIT. 
 * move a bit forward (maybe a section or two) into the git course.
  * --------------------------------------------------------------------
 * add the possibility to define movement patterns for npcs
 * ---------------------------------------------------------------------
 * introduce pokemon encounter in grass: new blank state.
 * draw a generic fighting modus that appears every time the trainer lands  * in tall grasses.
 * make it possible to talk to other trainers
 * introduce a generic special effect for every attack
 * go deeper into combat mechanism (defeat, be defeated)
 * ---------------------------------------------------------------------- 
 * begin with CI/CD integration (Jenkins - first lessons)
 * ---------------------------------------------------------------------
 * introduce the game menu (Pkmn, Bag, Save, Exit)
 * print all the already built areas with reduced dimensions in the corner  * of the build state.
 * create a pokemon class. Store individual characteristics of Pkmn.
 * build a Pokedex
 * build the special effects for a range of attacks
 * --------------------------------------------------------------------
 * learn VIM (set auto-completion of code)
 * ---------------------------------------------------------------------
 * create a base save file for an already completed game with one village
 * and one road.
 * --------------------------------------------------------------------- 
 * buy the SDL book and try to improve all of that (eventually rebuild the
 * game from scratch).
 * ---------------------------------------------------------------------
 * add a video introduction as in real games. Begin the video.
 * ev. follow lessons about videos.
*/


class VideoPlayer {
public:
	static VideoPlayer* get_instance(); 
	void initialize(); 
	void draw();

	void draw_menu();
	void draw_play();
	void draw_build();
	void draw_exit();

	void resize_screen(const int& width, const int& height);
	void highlight_menu_btn(const SDL_MouseMotionEvent&);
	void set_menu_btn_clicked(const SDL_MouseButtonEvent&);
  const MENU_BTN get_menu_btn_clicked() const;
	void clear();

	void add_sprite_to_build_state(const Tile&);
  void add_sprites_to_build_state(const std::vector<Tile>& tile);
	void add_npc_to_build_state(const Trainer&);

	void remove_sprite_from_build_state();
	void remove_npc_from_build_state();
 
  static int get_build_left_boundary();
	static int get_build_separator_right_boundary();
	static bool is_mouse_in_build_selector();
	static bool is_mouse_in_build_separator();
	Tile get_build_selector_tile_at_mouse_pos();
	std::vector<Tile> get_build_selector_tiles_at_mouse_pos();
	Trainer get_build_selector_npc_at_mouse_pos();
	void set_next_build_selector_layer();

	void save_build();
	void increment_build_horizontal_shift();
	void increment_build_vertical_shift();
  void decrement_build_horizontal_shift();
	void decrement_build_vertical_shift();
	void reset_build_shift();

	void increment_play_horizontal_shift();
	void increment_play_vertical_shift();
  void decrement_play_horizontal_shift();
	void decrement_play_vertical_shift();

	void move_landscape_south();
  void move_landscape_east();
	void move_landscape_north();
	void move_landscape_west();
	
	void add_red();
	void add_npc(const Trainer& npc);

	void move_trainer_south();
	void move_trainer_east();
	void move_trainer_north();
	void move_trainer_west();

	void set_trainer_still();
	void update_npcs(); //TODO update npcs form
	
	VideoPlayer(const VideoPlayer&) = delete;
	VideoPlayer& operator=(const VideoPlayer&) = delete;

private:
	void init_renderer();
	void init_window();
	VideoPlayer();

	void draw_background(const SDL_Color&);
	void draw_black_screen();
	
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;

	TTF_Font* _titleFont;
	TTF_Font* _btnFont;	
	FormDrawer* _formDrawer;
	Menu* _menu;
	Build* _build;
	Play* _play;
	Exit* _exit;
	static VideoPlayer* _instance;
};

#endif
