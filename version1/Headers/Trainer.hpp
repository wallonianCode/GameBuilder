#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>

#include "Tile.hpp"
#include "Constants.hpp"

//TODO create a Character parent, then two children: Trainer & npc
// There is no need for pattern_ for example for a trainer.

enum class Direction {North, South, East, West};
enum class Foot {Right, Left};


struct TrainerState {
	Tile tile;
	SDL_Rect rectOnScreen;
	SDL_Rect rectOnSrc;
	bool isNPC;
	Foot foot;
	Direction dir;
	Position form;
	int speed;	
};


//TODO develop the logic for brendan
class Trainer {
public:
	Trainer(const Tile& frontTile = Tile::red);
	void move(const Direction&);
	sprite get_sprite() const;
	void stand_still();
	std::pair<sprite, SDL_Rect> get_trainer_infos() const;
	void set_pattern(std::vector<Direction>::iterator patternBegin,
	std::vector<Direction>::iterator patternEnd); //for npcs only
	//void set_running_mode(); for brendan only
	//void set_walking_mode(); for brendan only
	void set_state(const TrainerState&);
	void update(); 
	void set_position(const SDL_Rect&);
	friend std::ostream& operator<<(std::ostream& os, const Trainer& tr);
private:
	//void init_run_tiles(); 
	void update_src(const Direction& direction);
	
	void set_next_tile_south();
	void set_next_tile_east();
	void set_next_tile_north();
	void set_next_tile_west();

	SDL_Rect get_src();

	static std::string foot_to_str(const Foot& foot);
	static Foot str_to_foot(const std::string& sFoot);

	static std::string direction_to_str();
	static Direction str_to_direction(const std::string& sDir);
  
	std::vector<Direction> _pattern;	
	Position _form;
	sprite _sprite; // front tile, position on screen
	SDL_Rect _src; // src rectangle
	bool _isNPC;	
	int _speed;
	Foot _lastFoot; 
	Direction _currentDirection;
	unsigned _patternIndex;
};



#endif
