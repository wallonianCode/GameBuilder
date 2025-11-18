#ifndef FORMDRAWER_H
#define FORMDRAWER_H


#include <iostream>
#include <exception>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Color.hpp"
#include "TextureLoader.hpp"
#include "Tile.hpp"
#include "Constants.hpp"
#include "Trainer.hpp"

//TODO remove the window param

using frame = std::pair<Tile, SDL_Rect>;


struct Comparator {
public:
	Comparator(const SDL_Rect* dest);
protected:
	const SDL_Rect* _dest;
};


struct SpriteComparator : public Comparator {
public:
	SpriteComparator(const SDL_Rect* dest);
	bool operator()(const sprite& sprite);
};


struct FrameComparator : public Comparator {
public:
	FrameComparator(const SDL_Rect* dest);
	bool operator()(const frame& frame);
};


struct TrainerComparator: public Comparator {
public:
	TrainerComparator(const SDL_Rect* dest);
	bool operator()(const Trainer& trainer);
};


class FormDrawer {
public:
  FormDrawer(SDL_Renderer*, SDL_Window*);
	void draw_black_screen();	
	void draw_rectangle(const SDL_Rect&, const SDL_Color&);
	void draw_rectangle_outline(const SDL_Rect&, const SDL_Color& color);	
	void draw_background(const SDL_Color&);
	void draw_text(const char*, TTF_Font*, 
	const SDL_Rect&,	const SDL_Color&);
	void draw_frame(const SDL_Rect& outside, const SDL_Rect& inside,
	const SDL_Color& fillColor);
	void draw_frame(const frame& frame); 
	void draw_sprite(const sprite& sprite);
	void draw_trainer(const Trainer& trainer);
	virtual void draw(SDL_Window* window);
	void draw_npc(const Trainer&);
	void clear();

	void increment_horizontal_shift(); 
	void increment_vertical_shift();
	void decrement_horizontal_shift();
	void decrement_vertical_shift();
	void reset_shift(); 

	void move_landscape_south(const float& speed);
	void move_landscape_east(const float& speed);
	void move_landscape_north(const float& speed);
	void move_landscape_west(const float& speed);
protected:
	SDL_Renderer* _renderer;
	std::vector<sprite> _frames;
	std::vector<sprite> _sprites;
	std::vector<Trainer> _npcs;
private:
	int _hShift; //memorize the total shift since the beginning 
	int _vShift;
  void add_to_horizontal_shift(const int&);
	void add_to_vertical_shift(const int&);
};

#endif
