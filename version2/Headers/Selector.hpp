#ifndef SELECTOR_H
#define SELECTOR_H

#include "Drawable.hpp"
#include "Layer.hpp"
#include "LandLayer.hpp"
#include "BigLandLayer.hpp"
#include "CharacterLayer.hpp"
#include "Window.hpp"
#include "Texture.hpp"


class Selector : public Drawable {
public:
	void draw();
	void handle_event(SDL_Event& event);
	bool is_mouse_in();
	// bool get_layer_id();
	Texture* get_selected_texture();
	Selector(const int width);
//	void init();
	void switch_layer();
	/**
		* @brief  adapt the dimensions of the frame to the texture
		*				  the mouse is currently hovering over.
		*/
	//void redimension_frame();
private:	
//TODO clean this up
	LayerManager* layerManager_;
	Texture* selectedTextureCopy_;
/*
	unsigned width_, layerId_;
	std::array<Layer*, 3> aLayers_;
	Frame frame_;
	enum class LayerName {Land, BigLand, Character};
	LayerName currentLayerName_;
	*/
};

#endif
