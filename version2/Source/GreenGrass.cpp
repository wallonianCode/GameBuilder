#include  "../Headers/GreenGrass.hpp"


GreenGrass::GreenGrass(const SDL_FPoint& pos) : SimpleTexture(pos) {
    this->set_pos_on_tileset({7*S+2, S+2});
    this->set_dim_on_tileset(S-3, S-3);
}
