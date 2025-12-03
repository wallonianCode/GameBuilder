#include "../Headers/CompositeTexture.hpp"

CompositeTexture::CompositeTexture() : Texture() {}

CompositeTexture::CompositeTexture(
	const std::string& tileset, 
	std::vector<SDL_FRect> ::iterator itSrcBegin,
	std::vector<SDL_FRect>::iterator itSrcEnd,
	std::vector<SDL_FRect> ::iterator itDestBegin,
	std::vector<SDL_FRect>::iterator itDestEnd) : 
	Texture(tileset) 
{
	std::pair<SDL_FRect, SDL_FRect> newSrcDest;

	if ((itSrcEnd - itSrcBegin) != (itDestEnd-itDestBegin))
	{
		//TODO error management throw exception
		throw new std::runtime_error("Source and destination vectors\
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
	Renderer* renderer;
	SDL_Texture* texture;
	std::vector<std::pair<SDL_FRect, SDL_FRect>>::iterator itSrcDest;

	renderer = Renderer::get_instance();
    texture = TextureLoader::load_texture(renderer->get_sdl_renderer(), tileset_);
	for (itSrcDest = vSrcDest_.begin();
			 itSrcDest != vSrcDest_.end(); itSrcDest++)
	{
		SDL_RenderTexture(renderer->get_sdl_renderer(), texture, 
									 &itSrcDest->first, &itSrcDest->second);
  } 
}


void CompositeTexture::update() {}


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


/*	
void CompositeTexture::save_dest(std::ostream& os) const {
	for (std::vector<std::pair<SDL_Rect, SDL_Rect>>::iterator 
			 itSrcDest = vSrcDest_.begin();
			 itSrcDest != vSrcDest_.end();
			 itSrcDest++) {
		os << itSrcDest->second.x << "," << itSrcDest->second.y << ","
			 << itSrcDest->second.w << "," << itSrcBegin->second.h << " ";
	}
}
*/

/*
SDL_Point CompositeTexture::get_pos_on_screen() const {
	return { vSrcDest_[0].second.x, vSrcDest_[0].second.y };
}
*/

SDL_FPoint CompositeTexture::get_upper_left_corner() const {
	std::vector<std::pair<SDL_FRect, SDL_FRect>>::const_iterator itSrcDest;
	SDL_FRect upperLeftCornerRect = vSrcDest_[0].second;

	for (itSrcDest = vSrcDest_.begin(); 
		 itSrcDest != vSrcDest_.end();
		 ++itSrcDest) {
		if ((itSrcDest->first.x <= upperLeftCornerRect.x) &&	
				(itSrcDest->first.y <= upperLeftCornerRect.y)) {
			upperLeftCornerRect = itSrcDest->second;
		}
	}
	return {upperLeftCornerRect.x, upperLeftCornerRect.y};
}


float CompositeTexture::get_width() const {
	return vSrcDest_[0].second.w;
}


float CompositeTexture::get_height() const {
	return vSrcDest_[0].second.h;
}


void CompositeTexture::move(const SDL_FPoint& newUpperLeftCorner) {
	float xMove, yMove;
	SDL_FPoint currentUpperLeftCorner;
	std::vector<std::pair<SDL_FRect, SDL_FRect>>::iterator itSrcDest;

 	currentUpperLeftCorner = {vSrcDest_[0].second.x, 
							  vSrcDest_[0].second.y};	
	xMove = newUpperLeftCorner.x - currentUpperLeftCorner.x;
	yMove = newUpperLeftCorner.y - currentUpperLeftCorner.y;
	for ( itSrcDest = vSrcDest_.begin(); itSrcDest != vSrcDest_.end(); itSrcDest++) {
		itSrcDest->second.x += xMove;
		itSrcDest->second.y += yMove;
	}
}
