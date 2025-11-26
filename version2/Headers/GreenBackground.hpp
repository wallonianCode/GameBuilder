#ifndef GREENBACKGROUND_H
#define GREENBACKGROUND_H

#include "Background.hpp"
#include "SimpleTexture.hpp"
#include "Window.hpp"
#include <vector>

class GreenBackground : public Background {
public:
	void draw() override;
	GreenBackground();

private:
	std::vector<SimpleTexture*> vGrass;
};


#endif
