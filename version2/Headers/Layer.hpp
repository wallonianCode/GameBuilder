#ifndef LAYER_H
#define LAYER_H

#include <exception>
#include <vector>
#include <array>

#include "Drawable.hpp"
#include "Texture.hpp"
#include "Renderer.hpp"
#include "MapUtils.hpp"



class Layer : public Drawable {
public:
	Layer(const int width, const SDL_Point&);
	Texture* get_texture_copy_at_coord(const SDL_Point& coord);
	void add_texture(Texture*);
	void draw() override;
protected:
	SDL_Point get_upper_left_corner() const;
private:	
	int width_;
	SDL_Point upperLeftCorner_;
	std::vector<Texture*> vTextures_;
};

#endif
