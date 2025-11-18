#include "../Headers/Collider.hpp"


Collider::Collider() {}


bool Collider::is_mouse_inside_frame(const SDL_MouseMotionEvent& motion,
const Rectangle& frame) {
	return ((motion.x > frame.get_x() && 
	motion.x < frame.get_x() + frame.get_width())	&& 
	(motion.y > frame.get_y() && motion.y < 
	frame.get_y() + frame.get_height()));
}


bool Collider::is_click_inside_frame(const SDL_MouseButtonEvent& e,
const Rectangle& frame) {
	return (e.x > frame.get_x() && 
	e.x < frame.get_x() + frame.get_width())	&& 
	(e.y > frame.get_y() && e.y < frame.get_y() + frame.get_height());
}
