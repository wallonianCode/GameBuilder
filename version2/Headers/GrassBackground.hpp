#ifndef GRASSBACKGROUND_H
#define GRASSBACKGROUND_H

#include <vector>


#include "Drawable.hpp"
#include "TextureFactory.hpp"
#include "SimpleTexture.hpp"


class GrassBackground : public Drawable {
public:
	GrassBackground(const float, const float );
	GrassBackground();
	void draw() override;
private:
	std::vector<std::shared_ptr<SimpleTexture>> vGrass_;

};

#endif
