#ifndef BUILDER_MAP_H
#define BUILDER_MAP_H

#include <memory>

#include "Map.hpp"
#include "GrassBackground.hpp"
#include "Selector.hpp"
#include "Separator.hpp"


const int SELECTOR_WIDTH = 5*TILE_DIM;


class BuilderMap : public Map {
public:
	void draw();
	void handle_event(SDL_Event* event) override;
	
	// ------ Constructors ----------------------------
	BuilderMap();

protected:
	bool was_out_of_selector();
	void set_out_of_selector(const bool);
private:
	void handle_mouse_motion_events(SDL_Event* event);
	std::shared_ptr<Selector> selector_;
	std::shared_ptr<Separator> separator_;
	std::shared_ptr<GrassBackground> grassBackground_;
	bool outOfSelector_;

};

#endif
