#include "../Headers/BigLand.hpp"

BigLand::Name::Name(const Type& type) : type_(type) {}


BigLand::Name BigLand::Name::to_name(const std::string& strName) {
	int pos = -1;
	const auto strIt =
	std::find(arString.begin(), arString.end(), strName);
	if (strIt != arString.end())
		pos = strIt - arString.begin();	
	
	if (pos < 0)
		throw std::invalid_argument(
		(std::string)__FUNCTION__ + ": strName was not found: " + strName);
	
	BigLand::Name::Type type = static_cast<BigLand::Name::Type>(pos);
	return BigLand::Name(type);
}


void BigLand::Name::save(std::ostream& os) const {
	os << to_str() << " ";
}


SDL_Rect BigLand::Name::get_src() {
	int pos = static_cast<int>(type_);
	return arSources[pos];
}

//TODO do not compute the next tile in advance! you have no garantee
// that the tiles are stored in the right order.
SDL_Point BigLand::Name::get_next_pos(const SDL_Point& pos) const {
	SDL_Point nextPos = pos;
	switch ((int)type_) {
		case (int)BigLand::Name::Type::hugeTreeUpLeft: 
		case (int)BigLand::Name::Type::hugeTreeUpCtr: 
		case (int)BigLand::Name::Type::hugeTreeCtrLeft1:
		case (int)BigLand::Name::Type::hugeTreeCtrCtr1:
		case (int)BigLand::Name::Type::hugeTreeCtrLeft2:
		case (int)BigLand::Name::Type::hugeTreeCtrCtr2:
		case (int)BigLand::Name::Type::hugeTreeDownLeft:
		case (int)BigLand::Name::Type::hugeTreeDownCtr:
			nextPos.x += TILE_DIM;
			break;
		case (int)BigLand::Name::Type::hugeTreeUpRight:
		case (int)BigLand::Name::Type::hugeTreeCtrRight1:
		case (int)BigLand::Name::Type::hugeTreeCtrRight2: {
			nextPos.x -= 2*TILE_DIM; 
			nextPos.y += TILE_DIM;
			break;
		}
		case (int)BigLand::Name::Type::hugeTreeDownRight: 
			nextPos.x -= 2*TILE_DIM;
			nextPos.y -= 2*TILE_DIM;
		default:
			std::cout << "BigLandName::get_next_pos(): default case" <<
			std::endl;
			break;
	}
	std::cout << "BigLandName::get_next_pos(): " << nextPos.x/TILE_DIM 
	<< ", " << nextPos.y/TILE_DIM << std::endl;
	return nextPos;
}



//-------------------------- PRIVATE --------------------------------

std::string BigLand::Name::to_str() const {
	int pos = static_cast<int>(type_);
	return arString[pos];
}
