#ifndef PLAY_H
#define PLAY_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "Trainer.hpp"
#include "FormDrawer.hpp"


class Play : public FormDrawer {
public:
	Play(SDL_Renderer*, SDL_Window*);
	void draw(SDL_Window*) override;
	void read_save_file();
	void add_trainer_test();
	void move_trainer_south();
	void move_trainer_east();
	void move_trainer_north();
	void move_trainer_west();
	void set_trainer_still();
	void update_npcs();
	void initialize();
	void reload();
private:
	std::vector<std::string> split(std::string, const std::string&);
	Trainer _brendan = Trainer(Tile::brendan);
};

#endif
