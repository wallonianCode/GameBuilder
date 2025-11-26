#ifndef SELECTOR_H
#define SELECTOR_H

#include "Drawable.hpp"
#include "Layer.hpp"
#include "LayerManager.hpp"
#include "Window.hpp"
#include "Texture.hpp"


class Selector : public Drawable {
public:
	void draw();
	void handle_event(SDL_Event& event);
	bool is_mouse_in();
	Texture* get_selected_texture();
	Selector(const int width);
	void switch_layer_forward();
	void switch_layer_backward();
	/**
		* @brief  adapt the dimensions of the frame to the texture
		*				  the mouse is currently hovering over.
		*/
	void redimension_frame();
private:	
	LayerManager* layerManager_;
};

#endif
