#include "../Headers/Grass.hpp"


//-------------------------------------------------------------------
//														FORMAT
//-------------------------------------------------------------------

Grass::Format Grass::Format::to_format(const std::string& str) {
	auto ptr = std::find(strTypes_.begin(), strTypes_.end(), str);
	if (ptr == strTypes_.end()) {
		throw new std::runtime_error("Unknown type: " + str);	
	}
	int index = ptr - strTypes_.begin();
	return Format(static_cast<Type>(index));
}
	

std::string Grass::Format::to_str(const Type& type) {
	return strTypes_[static_cast<int>(type)];
}


SDL_Rect Grass::Format::get_rect() const {
	return srcRect_[static_cast<int>(type_)];
}


Grass::Format::Format(const Grass::Format::Type& type) : type_(type) {}


std::array<std::string, 4> Grass::Format::strTypes_ = 
{"GreenWhite", "GreenWhiteGreen", "Green", "White"};

//------------------------------------------------------------------
//														GRASS
//------------------------------------------------------------------
Grass::Grass(const SDL_Point& posOnScreen, const Format& format) : 
LeafGreenTexture(posOnScreen), format_(format) {
	this->init_src();	
}


Grass::Grass(const SDL_Point& posOnScreen, const std::string& strFormat) :
Grass(posOnScreen, Grass::Format::to_format(strFormat)) {}


void Grass::update() {}


void Grass::init_src() {
	SDL_Rect rect = format_.get_rect();
	this->set_pos_on_tileset({rect.x, rect.y});
	this->set_dim_on_tileset(rect.w, rect.h);
}

/*
void Grass::init_src(const Grass::Format& format) {
	SDL_Rect rect = format.get_rect();
	this->set_pos_on_tileset({rect.x, rect.y});
	this->set_dim_on_tileset(rect.w, rect.h);
}
*/
