#include "../Headers/Character.hpp"


//-------------------- PUBLIC ---------------------------
void Character::Side::rotate(const Direction& dir, Character* character) {
	switch (dir) {
		case Direction::North:
			shape_ = Shape::Back; 
			break;
		case Direction::South:
			shape_ = Shape::Front;
			break;
		case Direction::East:
			shape_ = Shape::Right;
			break;
		case Direction::West:
			shape_ = Shape::Left;
			break;
		default:
			break;
	}
	update_src(character);
}


//TODO change the body of this function; too much parenthesis
void Character::Side::move(const Direction& dir, Character* character) {
	if (dir != this->get_dir()) {
		this->rotate(dir, character);
	}
	else { // same dir, move forward 
		switch (dir) {
			case Direction::North:
				if (shape_ != Shape::Back) { 
					precedentFoot_ = shape_;
					shape_ = Shape::Back;
				}
				else if (precedentFoot_ == Shape::BackLeftFoot) 
					shape_ = Shape::BackRightFoot;
				else
					shape_ = Shape::BackLeftFoot;
				break;
			case Direction::South:
				if (shape_ != Shape::Front) {
					precedentFoot_ = shape_;
					shape_ = Shape::Front;
				}
				else if (shape_ == Shape::FrontLeftFoot) 
					shape_ = Shape::FrontRightFoot;
				else 
					shape_ = Shape::FrontLeftFoot;
				break;
			case Direction::East:
				if (shape_ != Shape::Right) {
					precedentFoot_ = shape_;
					shape_ = Shape::Right;
				}
				else if (precedentFoot_ == Shape::RightSideLeftFoot) 
					shape_ = Shape::RightSideRightFoot;
				else
					shape_ = Shape::RightSideLeftFoot;
			case Direction::West: {
				if (shape_ != Shape::Left) {
					precedentFoot_ = shape_;
					shape_ = Shape::Left;
				}
				else if (precedentFoot_ == Shape::LeftSideLeftFoot) 
					shape_ = Shape::LeftSideRightFoot;
				else
					shape_ = Shape::LeftSideLeftFoot;
			}
			default:
				break;
		}}
		this->update_src(character);
}


Direction Character::Side::get_dir() {
	switch (shape_) {
		case Character::Side::Shape::Front:
		case Character::Side::Shape::FrontLeftFoot:
		case Character::Side::Shape::FrontRightFoot:
			return Direction::South;
		case Character::Side::Shape::Back:
		case Character::Side::Shape::BackLeftFoot:
		case Character::Side::Shape::BackRightFoot:
			return Direction::North;
		case Character::Side::Shape::Left:
		case Character::Side::Shape::LeftSideLeftFoot:
		case Character::Side::Shape::LeftSideRightFoot:
			return Direction::West;
		case Character::Side::Shape::Right:
		case Character::Side::Shape::RightSideLeftFoot:
		case Character::Side::Shape::RightSideRightFoot:
			return Direction::East;
		default: {
			std::cout << "Character::Side::get_dir() " << std::endl;
			return Direction::South;
		}
	}
}


Character::Side::Side(const Character::Side::Shape& shape) : 
shape_(shape) {}

//------------------------ PRIVATE --------------------------

void Character::Side::update_src(Character* character) {
	character->set_x_pos_on_tileset(Constants::WIDTH*to_int());
}


void Character::Side::save(std::ostream& os) {
	os << to_str(shape_) << " ";
	os << to_str(precedentFoot_) << " ";
}

//------------- Helpers -----------
int Character::Side::to_int() {
	return static_cast<int>(shape_);
}


std::string Character::Side::to_str(const Shape& shape) {
	std::string strShape;
	switch (shape) {
		case Shape::FrontLeftFoot:
			strShape = "FrontLeftFoot";
			break;
		case Shape::Front:
			strShape = "Front";
			break;
		case Shape::FrontRightFoot:
			strShape = "FrontRightFoot";
			break;
		case Shape::BackRightFoot:
			strShape = "BackRightFoot";
			break;
		case Shape::Back:
			strShape = "Back";
			break;
		case Shape::BackLeftFoot:
			strShape = "BackLeftFoot";
			break;
		case Shape::LeftSideRightFoot:
			strShape = "LeftSideRightFoot";
			break;
		case Shape::Left:
			strShape = "RightSideRightFoot";
			break;
		case Shape::LeftSideLeftFoot:
			strShape = "LeftSideLeftFoot";
			break;
		case Shape::RightSideRightFoot:
			strShape = "RightSideRightFoot";
			break;
		case Shape::Right:
			strShape = "Right";
			break;
		case Shape::RightSideLeftFoot:
			strShape = "RightSideLeftFoot";
			break;
		default:
			break;
	}
	return strShape;	
}
