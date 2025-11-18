#include "../Headers/Border.hpp"

//--------------------- SIDE ---------------------------------
Border::Side::Side() : 
type_(Border::Side::Type::South) {}


Border::Side::Side(const Border::Side::Type& type) : 
type_(type) {}


std::string Border::Side::to_str() const {	
	return strSide[static_cast<int>(type_)];
}


int Border::Side::to_int() const {
	return static_cast<int>(type_);
}


Border::Side 
Border::Side::to_side(const std::string& str) {
	auto ptr = std::find(strSide.begin(), strSide.end(), str);
	int index = ptr - strSide.begin();
	return Side(static_cast<Side::Type>(index));
}


std::array<std::string, 10> Border::Side::strSide =
 {"SouthWest", "South", "SouthEast", "SouthEastCorner", "East", 
  "NorthEast", "SouthWestCorner", "West", "NorthEastCorner",
	"None"};


Border::Border(const SDL_Point& posOnScreen) :  
Texture(leafGreenTextureFileName, posOnScreen){}


void Border::update() {}
