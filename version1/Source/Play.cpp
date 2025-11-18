#include "../Headers/Play.hpp"


Play::Play(SDL_Renderer* renderer, SDL_Window* window) : 
FormDrawer(renderer, window) {
	this->initialize();
}


void Play::draw(SDL_Window* window) {
	this->draw_background(Color::white);
	for (sprite spr : _sprites) {
		this->draw_sprite(spr);
	}
	for (Trainer npc : _npcs) {
		this->draw_npc(npc);
	}
	this->draw_trainer(_brendan);
	SDL_RenderPresent(_renderer);
}


void Play::read_save_file() {
	std::string line;
	std::ifstream saveFileSprites, saveFileNpcs;
	saveFileSprites.open(SAVE_FILE_SPRITES);
	while (getline(saveFileSprites, line)) {
		std::vector<std::string> tokens = split(line, ",");
		sprite spr;
		spr.first = (TileManager::to_tile(tokens.at(0)));
		spr.second = {std::stoi(tokens.at(1)), std::stoi(tokens.at(2)), 
		std::stoi(tokens.at(3)), std::stoi(tokens.at(4))};
		_sprites.push_back(spr);
	}
	saveFileSprites.close();

	saveFileNpcs.open(SAVE_FILE_NPCS);
	
	while(getline(saveFileNpcs, line)) {
		std::vector<std::string> tokens = split(line, ",");
		std::vector<Direction> pattern;
		Trainer t;
		TrainerState ts;
		std::cout << "Play::read_file: first token: " + tokens.at(0) 
		<< std::endl;
		ts.tile = TileManager::to_tile(tokens.at(0));
		ts.rectOnScreen = {std::stoi(tokens.at(1)), std::stoi(tokens.at(2)), 
		std::stoi(tokens.at(3)), std::stoi(tokens.at(4))};
		ts.rectOnSrc = {std::stoi(tokens.at(5)), std::stoi(tokens.at(6)), 
		std::stoi(tokens.at(7)), std::stoi(tokens.at(8))};
		ts.isNPC = std::stoi(tokens.at(9));
		
		ts.foot = static_cast<Foot>(std::stoi(tokens.at(10)));
		ts.dir = static_cast<Direction>(std::stoi(tokens.at(11)));
		ts.form = static_cast<Position>(std::stoi(tokens.at(12)));
		ts.speed = std::stoi(tokens.at(13));
		t.set_state(ts);
		unsigned i = 14;
		while (i < tokens.size()) {
			std::cout << "Play::read_file:" << tokens.at(i) << " : " <<
			std::stoi(tokens.at(i)) << std::endl;
			pattern.push_back(static_cast<Direction>(std::stoi(tokens.at(i))));
			i++;
		}
		t.set_pattern(pattern.begin(), pattern.end());
		_npcs.push_back(t);
	}
	saveFileNpcs.close();
}



void Play::move_trainer_south() {
	_brendan.move(Direction::South);
}

void Play::move_trainer_east() {
	_brendan.move(Direction::East);
}

void Play::move_trainer_north() {
	_brendan.move(Direction::North);
}

void Play::move_trainer_west() {
	_brendan.move(Direction::West);
}

void Play::set_trainer_still() {
	_brendan.stand_still();
}

void Play::update_npcs() {
	for (std::vector<Trainer>::iterator itNpc = _npcs.begin();
	itNpc != _npcs.end(); itNpc++) {
		itNpc->update();
	}
}

void Play::initialize() {
	this->reload();
}

void Play::reload() {
	this->clear();
	this->read_save_file();
}

// ----------------------- PRIVATE ------------------------------
std::vector<std::string> Play::split(std::string s, 
const std::string& delimiter) {
  std::vector<std::string> tokens;
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
      token = s.substr(0, pos);
      tokens.push_back(token);
      s.erase(0, pos + delimiter.length());
  }
  tokens.push_back(s);
  return tokens;
}
