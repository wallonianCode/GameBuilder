#include "../Headers/Water.hpp"


Water::Water(const SDL_Point& posOnScreen) : 
LeafGreenTexture(posOnScreen) {}

Water::Water(const SDL_Point& posOnScreen, 
const LeafGreenTexture::Side& side) : 
LeafGreenTexture(posOnScreen, side) {}


void Water::update() {}
