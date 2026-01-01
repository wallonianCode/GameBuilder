#ifndef SELECTOR_H
#define SELECTOR_H

#include "Drawable.hpp"
#include "Layer.hpp"
#include "LayerManager.hpp"
#include "Window.hpp"
#include "Texture.hpp"
#include "Frame.hpp"


class Selector : public Drawable {
public:
	void draw();
	void handle_event(SDL_Event* event);
	bool is_mouse_in();
	Texture* get_selected_texture();
	void switch_layer_forward();
	void switch_layer_backward();
	/**
		* @brief  adapt the dimensions of the frame to the texture
		*				  the mouse is currently hovering over.
		*/
	void redimension_frame();

	Selector(const int width);
	~Selector();
private:	
	LayerManager* layerManager_;
	Frame* frame_;
	int width_;
};

#endif
