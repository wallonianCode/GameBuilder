#ifndef CHARACTER_LAYER
#define CHARACTER_LAYER

#include "Layer.hpp"
#include "Character.hpp"


class CharacterLayer : public Layer {
public:
	CharacterLayer(const int& width);
private:
	void init();
};

#endif
