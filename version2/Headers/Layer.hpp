#ifndef LAYER_H
#define LAYER_H

#include <exception>
#include <vector>
#include <array>

#include "Drawable.hpp"
#include "Texture.hpp"
#include "Renderer.hpp"
#include "Frame.hpp"
#include "MapUtils.hpp"



class Layer : public Drawable {
public:
	Layer(const int width);
	void handle_event(SDL_Event& event);
	Texture* get_texture_copy_at_coord(const SDL_Point& coord);
private:	
	int width_;
	std::vector<Texture*> vTextures_;
};

#endif
