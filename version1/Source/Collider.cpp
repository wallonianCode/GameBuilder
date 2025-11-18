#include "../Headers/Collider.hpp"


Collider::Collider() {}


bool Collider::is_mouse_inside_frame(const SDL_MouseMotionEvent& motion,
const SDL_Rect& frame) {
	return ((motion.x > frame.x && motion.x < frame.x + frame.w)	&& 
	(motion.y > frame.y && motion.y < frame.y + frame.h));
}


bool Collider::is_click_inside_frame(const SDL_MouseButtonEvent& e,
const SDL_Rect& frame) {
	return (e.x > frame.x && e.x < frame.x + frame.w)	&& 
	(e.y > frame.y && e.y < frame.y + frame.h);
}
