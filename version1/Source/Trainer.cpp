#include "../Headers/Trainer.hpp"

Trainer::Trainer(const Tile& frontTile) : 
_form(Position::Front),
_speed(12), _lastFoot(Foot::Right), 
_currentDirection(Direction::South) {
	SDL_Rect pos;
	_isNPC = frontTile != Tile::brendan;
	if (_isNPC) {
	  pos = TileManager::get_tile_at_mouse_pos();	
	}
	else {
		pos = TileManager::get_central_tile();
	}
  _sprite = std::make_pair(frontTile, pos);
	_src = TileManager::get_character_src_rect(_sprite.first, _form);	
	_patternIndex = 0;
	_pattern.push_back(Direction::North);
}


void Trainer::move(const Direction& direction) {
	switch (direction) {
		case Direction::North: 
			this->update_src(Direction::North);
			_currentDirection = Direction::North;
			break;
		case Direction::South:
			this->update_src(Direction::South);
			_currentDirection = Direction::South;
			break;
		case Direction::East:
			this->update_src(Direction::East);
			_currentDirection = Direction::East;
			break;
		case Direction::West:
			this->update_src(Direction::West);
			_currentDirection = Direction::West;
			break;
		default:
			break;
	}
	std::cout << "Trainer::move(): " << _src.x << std::endl;
}


sprite Trainer::get_sprite() const {
	return _sprite;	
}


void Trainer::stand_still() {
	/*switch (_currentDirection) {
		case Direction::North: {
			_sprite.first = Tile::trainerBack;
			break;
		}
		case Direction::South: {
			_sprite.first = Tile::trainerFront;
			break;
		}
		case Direction::East: {
			_sprite.first = Tile::trainerRightSide;
			break;
		}
		case Direction::West: {
			_sprite.first = Tile::trainerLeftSide;
			break;
		}
		default: {
			break;
		}
	}
	*/
}


std::pair<sprite, SDL_Rect> Trainer::get_trainer_infos() const 
{
	return std::make_pair(_sprite, _src);
}

void Trainer::set_pattern(std::vector<Direction>::iterator patternBegin,
std::vector<Direction>::iterator patternEnd) {
	_pattern.clear();
	while (patternBegin != patternEnd) {
		_pattern.push_back(*patternBegin);
		patternBegin++;
	}
	_patternIndex = 0;
}


void Trainer::set_state(const TrainerState& state) {
	_sprite.first = state.tile;
	_sprite.second = state.rectOnScreen;
	_src = state.rectOnSrc;
	_isNPC = state.isNPC;
	_lastFoot = state.foot;
	_currentDirection = state.dir;
	_form = state.form;
	_speed = state.speed;
}


void Trainer::update() {	
	if (_patternIndex >= _pattern.size()) {
		_patternIndex = 0;
	}	
	_currentDirection = _pattern.at(_patternIndex);
	this->update_src(_currentDirection);
	/*
	_src = TileManager::get_character_src_rect(_sprite.first, 
	Position::BackRightFoot); */
	switch (_currentDirection) {
		case Direction::East:
			_sprite.second.x += _speed;
			break;
		case Direction::West:
			_sprite.second.x -= _speed;
			break;
		case Direction::South:
			_sprite.second.y += _speed;
			break;
		case Direction::North:
			_sprite.second.y -= _speed;
			break;
		default:
			break;
	}
	_patternIndex++;
}


void Trainer::set_position(const SDL_Rect& pos) {
	_sprite.second = pos;
}


// ---------------------------PRIVATE---------------------------- 

void Trainer::update_src(const Direction& dir) {
	switch (dir) {
		case Direction::South:
			this->set_next_tile_south();
			break;
		case Direction::East:
			this->set_next_tile_east();
			break;
		case Direction::North:
			this->set_next_tile_north();
			break;
		case Direction::West:
			this->set_next_tile_west();
			break;
		default:
			break;
	}
}



void Trainer::set_next_tile_south() {
	switch (_form) {
		case Position::Front:
			if (_lastFoot == Foot::Left) {
				_form = Position::FrontRightFoot;
				_lastFoot = Foot::Right;
			}
			else {
				_form = Position::FrontLeftFoot;	
				_lastFoot = Foot::Left;
			}
			break;
		default:
			_form = Position::Front;
			break;
	}
	_src = this->get_src();
}


void Trainer::set_next_tile_east() {
	switch (_form) {
		case Position::RightSide:
			if (_lastFoot == Foot::Right) {
				_form = Position::RightSideLeftFoot;	
				_lastFoot = Foot::Left;
		  }
			else {
			  _form = Position::RightSideRightFoot;
				_lastFoot = Foot::Right;
			}
			break;
		default:
			_form = Position::RightSide;
			break;
	}
	_src = this->get_src();
}


void Trainer::set_next_tile_north() {
	switch (_form) {
		case Position::Back:
			if (_lastFoot == Foot::Right) {
				_form = Position::BackLeftFoot;
				_lastFoot = Foot::Left;
			}
			else {
				_form = Position::BackRightFoot;
				_lastFoot = Foot::Right;
			}
			break;
		default:
			_form = Position::Back;
			break;
	}
	_src = this->get_src();
}


void Trainer::set_next_tile_west() {
	switch (_form) {
		case Position::LeftSide:
			if (_lastFoot == Foot::Right) {
				_form = Position::LeftSideLeftFoot;
				_lastFoot = Foot::Left;
			}
			else {
				_form = Position::LeftSideRightFoot;
				_lastFoot = Foot::Right;
			}
			break;
		default:
			_form = Position::LeftSide;
			break;
	}
  _src = this->get_src();
}


SDL_Rect Trainer::get_src() {
	std::cout << "Trainer::get_src(): " << 
	static_cast<int>(_form) << std::endl;
	SDL_Rect rect;
	rect = _isNPC ? 
	TileManager::get_character_src_rect(_sprite.first, _form) :
	TileManager::get_brendan_src_rect(_form);
	return rect;
}


std::string Trainer::foot_to_str(const Foot& foot) {
	std::string str = "";
	switch (foot) {
		case (Foot::Left): {
			str = "Left";
			break;
		}
		case (Foot::Right): {
			str = "Right";
			break;
		}
		default:
			break;
	}
	return str;
}


Foot Trainer::str_to_foot(const std::string& sFoot) {
	if (sFoot == "Left") {
		return Foot::Left;
	}
	else if (sFoot == "Right") {
		return Foot::Right;
	}
	else {
		throw std::runtime_error("Foot neither left nor right: " + sFoot);
	}
}


//-------------------- FRIEND FUNCTIONS --------------------------
std::ostream& operator<<(std::ostream& os, const Trainer& tr)
{
	//TODO check if necessary
	/*
	int lastFoot = static_cast<int>(tr._lastFoot);
	int dir = static_cast<int>(tr._currentDirection);
	int form = static_cast<int>(tr._form);
	*/
	Tile tile = tr._sprite.first;
	SDL_Rect rectOnScreen = tr._sprite.second;
	std::string sFoot = Trainer::foot_to_str(tr._lastFoot);
	//std::string sDir = Trainer::direction_to_str(tr._currentDirection);
	std::string d = ",";
	os << TileManager::to_string(tile) << d; 
	os << rectOnScreen.x << d << rectOnScreen.y << d <<
	rectOnScreen.w << d << rectOnScreen.h << d; 
	os << tr._src.x << d << tr._src.y << d <<
	tr._src.w << d << tr._src.h << d;
	os << tr._isNPC << d;
	os << static_cast<int>(tr._lastFoot) << d;
	os << static_cast<int>(tr._currentDirection) << d;
	os << static_cast<int>(tr._form) << d;
	os << tr._speed << d; 
	for (auto itPattern = tr._pattern.begin(); 
	itPattern != tr._pattern.end(); itPattern++) {
		if (itPattern == tr._pattern.begin()) {
			os << static_cast<int>(*itPattern);
		}
		else {
			os << d << static_cast<int>(*itPattern);
		}
	}
	return os;
}

