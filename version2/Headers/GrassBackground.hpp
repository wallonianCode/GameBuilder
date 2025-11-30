#ifndef GRASSBACKGROUND_H
#define GRASSBACKGROUND_H

#include <vector>


#include "Drawable.hpp"
#include "TextureFactory.hpp"



class GrassBackground : public Drawable {
public:
	GrassBackground(const float, const float );
	void draw() override;
private:
	std::vector<SimpleTexture*> vGrass_;

};

#endif
