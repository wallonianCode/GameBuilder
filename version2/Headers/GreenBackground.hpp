#ifndef GREENBACKGROUND_H
#define GREENBACKGROUND_H

#include "Grass.hpp"
#include "Background.hpp"
#include "Window.hpp"
#include <vector>

class GreenBackground : public Background {
public:
	void draw() override;
	GreenBackground();

private:
	std::vector<Grass> vGrass;
};


#endif
