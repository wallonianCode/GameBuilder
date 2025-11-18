#include "../Headers/Character.hpp"


//---------------------- PUBLIC METHODS --------------------------


void Character::rotate(const Direction& dir) {
	side_.rotate(dir, this);
}


// if there is a change in direction, only a rotation is carried on
void Character::move(const Direction& dir) {
	side_.move(dir, this);	
	this->increment_position(dir);
}


void Character::move_along_pattern() {
	if (patternIndex_ == pattern_.size()) 
		patternIndex_ = 0;
	this->move(pattern_.at(patternIndex_++));
}


void Character::move_along_reversed_pattern() {
	if (patternIndex_ == 0) 
		patternIndex_ = (pattern_.size() - 1);
	this->move(pattern_.at(patternIndex_--));	
}


void Character::move_back_and_forth_along_pattern() {
	if (isPatternReversed) {
		this->move(pattern_.at(patternIndex_--));
		if (patternIndex_ == 0) isPatternReversed = false;
	}
	else {
		this->move(pattern_.at(patternIndex_++));
		if (patternIndex_ == pattern_.size()) isPatternReversed = true;
	}
}


void Character::set_pattern(std::vector<Direction>::iterator begin,
std::vector<Direction>::iterator end) {
	if (! pattern_.empty()) pattern_.clear();
	while(begin != end) {
		pattern_.push_back(*begin++);
	}
	patternIndex_ = 0;
}


void Character::update() {}


void Character::save(std::ostream& os) const {
	os << "Character" << " ";
	name_.save(os);
	Texture::save(os);
//	side_.save(os); forces map to know about the character class
}


Character::Character(const SDL_Point& posOnScreen, 
const Character::Name::Type& type, const std::string& tileset) : 
Texture(tileset, posOnScreen), name_(type, this) {
	pattern_ = {Direction::East, Direction::East, Direction::East, 
	Direction::East, Direction::East, Direction::East, 
	Direction::South, Direction::South, Direction::South, 
	Direction::South, Direction::South, Direction::South};
	side_ = Character::Side(Character::Side::Shape::Front);
	speed_ = 15;
}


Character::Character(const SDL_Point& posOnScreen, 
const std::string& sType) : Character(posOnScreen, 
Name::to_name_type(sType)) {}


//-------------------------- 	PRIVATE METHOD -----------------------------
void Character::init_src() {}


void Character::init_src(const Name::Type& type) {
	name_ = Character::Name(type, this); 
}


void Character::increment_position(const Direction& dir) {
	SDL_Point posOnScreen = this->get_pos_on_screen();
	switch (dir) {
		case Direction::North:
			posOnScreen.y -= speed_;
			break;
		case Direction::South:
			posOnScreen.y += speed_;
			break;
		case Direction::East:
			posOnScreen.x += speed_;
			break;
		case Direction::West:
			posOnScreen.x -= speed_;
			break;
		default:
			break;
	}
	this->set_pos_on_screen(posOnScreen);
}
