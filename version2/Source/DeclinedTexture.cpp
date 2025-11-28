#include "../Headers/DeclinedTexture.hpp"

DeclinedTexture::DeclinedTexture() : SimpleTexture(leafGreenTextureFileName) {}

DeclinedTexture::DeclinedTexture(const SDL_FPoint& pos):
SimpleTexture(leafGreenTextureFileName, pos) {}
