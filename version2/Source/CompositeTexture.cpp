#include "../Headers/CompositeTexture.hpp"


CompositeTexture::CompositeTexture(
	const std::string& tileset, 
	std::vector::iterator<SDL_Rect> itSrcBegin,
	std::vector::iterator<SDL_Rect> itSrcEnd,
	std::vector::iterator<SDL_Rect> itDestBegin,
	std::vector::iterator<SDL_Rect> itDestEnd) : 
	Texture(tileset) 
{
	std::pair<SDL_Rect, SDL_Rect> newSrcDest;

	if ((itSrcEnd - itSrcBegin) != (itDestEnd-itDestBegin))
	{
		//TODO error management throw exception
		throw new std::runtime_exception("Source and destination vectors\
		of different lengths");
	}

	while (itSrcBegin != itSrcEnd && itDestBegin != itDestEnd)
	{
		newSrcDest.first = *itSrcBegin;
		newSrcDest.second = *itDestBegin;
		itSrcBegin++;
		itDestBegin++;
	}
}


void CompositeTexture::draw() {
	Renderer* renderer = Renderer::get_instance();
	SDL_Texture* texture =
	TextureLoader::load_texture(renderer->get_sdl_renderer(), tileset_);
	for (std::vector<std::pair<SDL_Rect, SDL_Rect>>::iterator 
			 itSrcDest = vSrcDest_.begin();
			 itSrcDest != vSrcDest_.end(); itSrcDest++)
	{
		SDL_RenderCopy(renderer->get_sdl_renderer(), texture, 
									 itSrcDest->first, itSrcDest->second);
  } 
}


void CompositeTexture::update() {}

void CompositeTexture::save() override;

/* should be fixed once and for all in the constructors of derived classes
void CompositeTexture::set_pos_on_tileset(
std::vector::iterator<SDL_Point> itPosSrcBegin, 
std::vector::iterator<SDL_Point> itPosSrcEnd)  {
	int i = 0;
	while (itPosSrcBegin != itPosSrcEnd)
	{
		vSrcDest_[i].first.x = itPosSrcBegin->x;
		vSrcDest_[i].first.y = itPosSrcEnd->y;
		i++;
		itPosSrcBegin++;
		itPosSrcEnd++;
	}
}
*/


	
void CompositeTexture::save_dest(std::ostream& os) const {
	for (std::vector<std::pair<SDL_Rect, SDL_Rect>>::iterator 
			 itSrcDest = vSrcDest_.begin();
			 itSrcDest != vSrcDest_.end();
			 itSrcDest++) {
		os << itSrcDest->second.x << "," << itSrcDest->second.y << ","
			 << itSrcDest->second.w << "," << itSrcBegin->second.h << " ";
	}
}

/*
SDL_Point CompositeTexture::get_pos_on_screen() const {
	return { vSrcDest_[0].second.x, vSrcDest_[0].second.y };
}
*/

SDL_Point CompositeTexture::get_upper_left_corner() const {
	std::vector<std::pair<SDL_Rect, SDL_Rect>::iterator 
	itSrcDest;
	SDL_Rect upperLeftCornerRect = vSrcDest_[0].second;

	for (itSrcDest = vSrcDest_.begin(); itSrcDest != vSrcDest_.end();
			 ++itSrcDest) {
		if ((itSrcDest->first.x <= upperLeftCornerRect.x) &&	
				(itSrcDest->first.y <= upperLeftCornerRect.y)) {
			upperLeftCornerRect = itSrcDest->second;
		}
	}
	return {upperLeftCornerRect.x, upperLeftCornerRect.y};
}


void CompositeTexture::set_pos_on_screen(
	const SDL_Point& newUpperLeftCorner) {
 	SDL_Point currentUpperLeftCorner = {vSrcDest_[0].second.x, 
																			vSrcDest_[0].second.y};	
	int xMove = newUpperLeftCorner.x - currentUpperLeftCorner.x;
	int yMove = newUpperLeftCorner.y - currentUpperLeftCorner.y;
	for (std::vector<std::pair<SDL_Rect, SDL_Rect>>::iterator 
			 itSrcDest = vSrcDest_.begin();
			 itSrcDest != vSrcDest_.end();
			 itSrcDest++) {
		itSrcDest->second.x += xMove;
		itSrcDest->second.y += yMove;
	}
}
