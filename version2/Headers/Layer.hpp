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


#include "Sand.hpp"
#include "Grass.hpp"
#include "SandRoad.hpp"
#include "MoosRoad.hpp"
#include "RockRoad.hpp"
#include "ShallowWater.hpp"
#include "DeepWater.hpp"
#include "TallGrass.hpp"
#include "SmallTree.hpp"
#include "Flowers.hpp"
#include "GreenBorder.hpp"
#include "GreyBorder.hpp"


/* 
class Layer : public Drawable {
public:
	Layer(const int& width);
	void draw();
	virtual void handle_event(SDL_Event& e);
	/* param: the upper left coord of a texture
	
	Texture* get_texture_at_coord(const SDL_Point&);
	//	Texture* get_selected_tile();
	/* gives upper left coordinates of texture
	 * param: some coord that belongs or not belongs to a texture
	 * return: if does not belong, argument returned left unchanged.
	           if param belong to a texture, return upper left coord of it
	 * details: in case of simple textures, always return the param 
	          in case of composite textures, upper left corner may differ
						This function is used in selector for dimensioning the frame
						dynamically.
   					
	virtual SDL_Point get_texture_coordinates(const SDL_Point&) = 0;
	
	/**
		* returns the width of the texture the mouse is currently hovering
		* 		    over.
		
	virtual int get_texture_width() = 0;
	
	/**
		* returns the height of the texture the mouse is currently hovering
		* over.
		
	virtual int get_texture_height() = 0;

//	virtual std::vector<Texture*> get_selected_textures();
	SDL_Point get_pos_on_grid(const int index);
protected:
	void add_texture(Texture*);
//	void set_selected_tile(Texture*);
//	void set_selected_textures(std::vector<Texture*>);
	
	Texture* get_texture_at_pos(const SDL_Point&);
private:
  
	void select_texture();
	void init_grid();
	int width_;
	Texture* selectedTexture_;
	//std::vector<Texture*> selectedTextures_;
	std::array<SDL_Point, 64> arPos_;
	std::vector<Texture*> vTiles_;
};
*/

class Layer : public Drawable {
public:
	Layer(const int width);
	void handle_event(SDL_Event& event);
private:
	const SDL_Point get_current_texture_pos() const;
	const int get_current_texture_width() const;
	const int get_current_texture_height() const;
	// every layer has to manage its own frame in order not to have to give back the
	// dimension of the current texture at any moment.
	Frame_* frame;
	int width_;
	std::vector<Texture*> vTextures_;

};

#endif
