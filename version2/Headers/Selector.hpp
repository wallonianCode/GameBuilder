#ifndef SELECTOR_H
#define SELECTOR_H

#include "Drawable.hpp"
#include "Layer.hpp"
#include "LandLayer.hpp"
#include "BigLandLayer.hpp"
#include "CharacterLayer.hpp"
#include "Window.hpp"
#include "Texture.hpp"


class Selector : Drawable {
public:
	void draw();
	void handle_event(SDL_Event& event);
	bool is_mouse_in();
	bool get_layer_id();
	Texture* get_selected_texture();
	std::vector<Texture*> get_selected_textures();
	Selector();
	Selector(const int width);
	void init();
	void switch_layer();
	/**
		* @brief  adapt the dimensions of the frame to the texture
		*				  the mouse is currently hovering over.
		*/
	void redimension_frame();
private:	
	unsigned width_, layerId_;
	std::array<Layer*, 3> aLayers_;
	Frame frame_;
	enum class LayerName {Land, BigLand, Character};
	LayerName currentLayerName_;
};

#endif
