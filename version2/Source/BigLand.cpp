#include "../Headers/BigLand.hpp"


void BigLand::update() {}


void BigLand::save(std::ostream& os) const {
	os << "BigLand" << " ";
	name_.save(os); //TODO check the order of the save function
	save_dest(os);
}


SDL_Point BigLand::get_next_pos() const {
	return name_.get_next_pos(this->get_pos_on_screen());
}


BigLand::BigLand(const SDL_Point& posOnScreen) : 
LeafGreenTexture(posOnScreen) {
	init_src();
}


BigLand::BigLand(const SDL_Point& posOnScreen, 
const BigLand::Name& name) : LeafGreenTexture(posOnScreen), name_(name) {
	init_src();
}


BigLand::BigLand(const SDL_Point& posOnScreen, 
const std::string& name) : 
BigLand(posOnScreen, BigLand::Name::to_name(name)) {}


std::array<SDL_Rect, 21> BigLand::Name::arSources =
{{ {14*S+2, 2, S-3, S-2}, {15*S+2, 2, S-3, S-2}, 
	 {16*S+2, 2, S-3, S-2}, {14*S+2, S+1, S-3, S-2},
	 {15*S+2, S+1, S-3, S-2}, {16*S+2, S+1, S-3, S-2},
	 {14*S+2, 2*S+1, S-3, S-2}, {15*S+2, 2*S+1, S-3, S-2}, 
	 {16*S+2, 2*S+1, S-3, S-2}, {14*S+2, 3*S+1, S-3, S-3}, 
	 {15*S+2, 3*S+1, S-3, S-3}, {16*S+2, 3*S+1, S-3, S-3}, 
	 {14*S+2, 17*S+2, S-3, S-3}, {15*S+2, 17*S+2, S-3, S-3}, 
	 {14*S+2, 18*S+2, S-3, S-3}, {15*S+2, 18*S+2, S-3, S-3}, 
   {14*S+2, 19*S+1, S-3, S-3}, {15*S+2, 19*S+1, S-3, S-3}, 
	 {17*S+1, 13*S+2, S-1, S-3}, {17*S+1, 14*S+2, S-1, S-3},
	 {17*S+1, 15*S+2, S-1, S-3} }};


std::array<std::string, 21> BigLand::Name::arString =
{ { "hugeTreeUpLeft", "hugeTreeUpCtr", "hugeTreeUpRight", 
		"hugeTreeCtrLeft1", "hugeTreeCtrCtr1", "hugeTreeCtrRight1",
		"hugeTreeCtrLeft2", "hugeTreeCtrCtr2", "hugeTreeCtrRight2",
		"hugeTreeDownLeft", "hugeTreeDownCtr", "hugeTreeDownRight",
		"pinTreeUpLeft", "pinTreeUpRight", "pinTreeCtrLeft", 
		"pinTreeCtrRight", "pinTreeDownLeft", "pinTreeDownRight", 
		"slenderPinTreeUp", "slenderPinTreeCtr", "slenderPinTreeDown"} };

//--------------------- PRIVATE ------------------------------
void BigLand::init_src() {
	SDL_Rect src = name_.get_src();
	set_pos_on_tileset({src.x, src.y});
	set_dim_on_tileset(src.w, src.h);
}
