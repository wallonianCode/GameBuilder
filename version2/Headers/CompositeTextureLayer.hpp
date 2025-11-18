#ifndef COMPOSITETEXTURELAYER_H
#define COMPOSITETEXTURELAYER_H

#include "Layer.hpp"
#include "CompositeTexture.hpp"


class CompositeTextureLayer : public Layer {
public:
	CompositeTextureLayer(const int& width);

	void handle_event(SDL_Event&) override;
	Texture* get_texture_at_mouse_pos() const override;

private:
	std::vector<ComposedTexture*> vTextures_;
};

#endif
