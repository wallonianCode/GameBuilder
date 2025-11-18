#include "../Headers/Character.hpp"


Character::Name::Name(const Type& type, Character* character) : 
type_(type) {
	init_src(character);
}


Character::Name::Type Character::Name::to_name_type(
const std::string& str) {
	Character::Name::Type type;
	if (str == "Red")
		type = Character::Name::Type::Red;
	else if (str == "Flora")
		type = Character::Name::Type::Flora;
	else if (str == "Blue")
		type = Character::Name::Type::Blue;
	else if (str == "Chen")
		type = Character::Name::Type::Chen;
	else if (str == "Mama")
		type = Character::Name::Type::Mama;
	else // default case, type unrecognized
		type = Character::Name::Type::Red;
	return type;
}


void Character::Name::save(std::ostream& os) const {
	os << to_str() << " ";
}

void Character::Name::init_src(Character* character) {
	switch(type_) {
		case Type::Red: 
			character->set_pos_on_tileset({Constants::X_BASE, 
			Constants::Y_BASE});
			break;
		case Type::Flora:
			character->set_pos_on_tileset({Constants::X_BASE, 
			Constants::Y_BASE + Constants::Y});
			break;
		case Type::Blue:
			character->set_pos_on_tileset({Constants::X_BASE, 
			Constants::Y_BASE + 2*Constants::Y});
			break;
		case Type::Chen:
			character->set_pos_on_tileset({Constants::X_BASE, 
			Constants::Y_BASE + 3*Constants::Y});
			break;
		case Type::Mama:
			character->set_pos_on_tileset({Constants::X_BASE, 
			Constants::Y_BASE + 4*Constants::Y});
			break;
		default:
			break;
	}
	character->set_dim_on_tileset(Constants::WIDTH, Constants::HEIGHT);
}


std::string Character::Name::to_str() const {
	std::string str;
	switch(type_) {
		case Type::Red:
			str = "Red";
			break;
		case Type::Flora:
			str = "Flora";
			break;
		case Type::Blue:
			str = "Blue";
			break;
		case Type::Chen:
			str = "Chen";
			break;
		case Type::Mama:
			str = "Mama";
			break;
		default:
			break;
	}
	return str;
}
