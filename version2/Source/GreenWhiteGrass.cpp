#include  "../Headers/GreenWhiteGrass.hpp"

GreenWhiteGrass::GreenWhiteGrass(const SDL_Point& pos) : 
SimpleTexture(pos) {
    this->set_pos_on_tileset({6*S+2, 2});
    this->set_dim_on_tileset(S-3, S-3);
}