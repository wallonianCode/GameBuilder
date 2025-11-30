#ifndef BLACKBACKGROUND_H
#define BLACKBACKGROUND_H


#include "Drawable.hpp"

//TODO find out how to paint a limited area in black
class BlackBackground : public Drawable {
public:
	BlackBackground(const float, const float);
	void draw() override;
private:
	float width_, height_;
};

#endif
