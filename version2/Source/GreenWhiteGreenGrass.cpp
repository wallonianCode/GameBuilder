#include "../Headers/GreenWhiteGreenGrass.hpp"


GreenWhiteGreenGrass::GreenWhiteGreenGrass(const SDL_FPoint& pos) : SimpleTexture(pos) {
    this->set_pos_on_tileset({6*S+2, S+2});
    this->set_dim_on_tileset(S-3, S-3);
}
