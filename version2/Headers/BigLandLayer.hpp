#ifndef BIGLANDLAYER_H
#define BIGLANDLAYER_H

#include "Layer.hpp"
#include "BigLand.hpp"
#include "ComposedTexture.hpp"

//TODO rename to CompositeTextureLayer
//TODO review and recode the whole class
class BigLandLayer : public Layer {
public:
	BigLandLayer(const int& width); 
	void handle_event(SDL_Event&) override;
protected:
	//function that returns an array of selected textures
  //void set_textures();
	//void set_texture_selected() override;
	//Texture* get_texture_at_mouse_pos() override;
	SDL_Point get_composite_texture_pos() const;
	Texture* get_texture_at_mouse_pos() const override;
private:
	void init();
	std::vector<ComposedTexture*> vTextures_;

};


#endif
