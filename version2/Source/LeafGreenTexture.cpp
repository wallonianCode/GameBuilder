#include "../Headers/LeafGreenTexture.hpp"

//--------------------- SIDE ---------------------------------
LeafGreenTexture::Side::Side() : 
type_(LeafGreenTexture::Side::Type::North) {}

LeafGreenTexture::Side::Side(const LeafGreenTexture::Side::Type& type) : 
type_(type) {}


std::string LeafGreenTexture::Side::to_str() const {	
	return strSide[static_cast<int>(type_)];
}


int LeafGreenTexture::Side::to_int() const {
	return static_cast<int>(type_);
}


LeafGreenTexture::Side 
LeafGreenTexture::Side::to_side(const std::string& str) {
	auto ptr = std::find(strSide.begin(), strSide.end(), str);
	int index = ptr - strSide.begin();
	return Side(static_cast<Side::Type>(index));
}


std::array<std::string, 9> LeafGreenTexture::Side::strSide =
{"North", "West", "East", "South", "NorthWest", "NorthEast", 
"SouthWest", "SoutEast", "None" };


void LeafGreenTexture::save(std::ostream& os) const {
	os << side_.to_str() << " ";
	Texture::save(os);
}

//---------------------- LEAFGREEN TEXTURE ---------------------

LeafGreenTexture::LeafGreenTexture(const SDL_Point& posOnScreen,
const LeafGreenTexture::Side& side) :  
Texture(leafGreenTextureFileName, posOnScreen), side_(side) {}


LeafGreenTexture::LeafGreenTexture(const SDL_Point& posOnScreen):
LeafGreenTexture(posOnScreen, 
LeafGreenTexture::Side(LeafGreenTexture::Side::Type::None)) {}
