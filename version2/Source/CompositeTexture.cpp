#include "../Headers/CompositeTexture.hpp"

CompositeTexture::CompositeTexture() : Texture() {}

CompositeTexture::CompositeTexture(
	const std::string& tileset, 
	std::vector<SDL_FRect>::iterator itSrcBegin,
	std::vector<SDL_FRect>::iterator itSrcEnd,
	std::vector<SDL_FRect>::iterator itDestBegin,
	std::vector<SDL_FRect>::iterator itDestEnd) : 
	Texture(tileset) 
{
	std::pair<SDL_FRect, SDL_FRect> newSrcDest;
	
	if ((itSrcEnd - itSrcBegin) != (itDestEnd-itDestBegin))
	{
		throw new std::runtime_error("Source and destination vectors\
		of different lengths");
	}

	while (itSrcBegin != itSrcEnd && itDestBegin != itDestEnd)
	{
		newSrcDest.first = *itSrcBegin;
		newSrcDest.second = *itDestBegin;
		vSrcDest_.push_back(newSrcDest);
		itSrcBegin++;
		itDestBegin++;
	}
}


CompositeTexture::CompositeTexture(const CompositeTexture& other) : 
Texture(other) {
	vSrcDest_ = other.vSrcDest_;
}


void CompositeTexture::draw() {
	Renderer* renderer;
	SDL_Texture* texture;
	std::vector<std::pair<SDL_FRect, SDL_FRect>>::iterator itSrcDest;

	renderer = Renderer::get_instance();
  texture = 
	TextureLoader::load_texture(renderer->get_sdl_renderer(), 
	this->get_tileset());
	for (itSrcDest = vSrcDest_.begin();
			 itSrcDest != vSrcDest_.end(); itSrcDest++)
	{
		SDL_RenderTexture(renderer->get_sdl_renderer(), texture, 
									 &itSrcDest->first, &itSrcDest->second);
  } 
}


void CompositeTexture::update() {}


SDL_FPoint CompositeTexture::get_upper_left_corner() const {
	SDL_FRect upperLeftCornerRect, temp;
	std::vector<std::pair<SDL_FRect, SDL_FRect>>::const_iterator itSrcDest;
	
	itSrcDest = vSrcDest_.begin();
	upperLeftCornerRect = itSrcDest->second;

	for (itSrcDest = vSrcDest_.begin(); 
		 itSrcDest != vSrcDest_.end();
		 ++itSrcDest) {
		temp = itSrcDest->second;
		if ((temp.x <= upperLeftCornerRect.x) && (temp.y <= upperLeftCornerRect.y)) {
			upperLeftCornerRect = itSrcDest->second;
		}
	}
	return {upperLeftCornerRect.x, upperLeftCornerRect.y};
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


bool CompositeTexture::is_coord_in_texture(const SDL_FPoint& coord) const {
	bool success;
	SDL_FRect dest;
	std::vector<std::pair<SDL_FRect, SDL_FRect>>::const_iterator itSrcDest;

	success = false;
	for (itSrcDest = vSrcDest_.begin(); itSrcDest != vSrcDest_.end(); itSrcDest++) {
		dest = itSrcDest->second;
		if (dest.x == coord.x && dest.y == coord.y) {
			success = true;
			break;
		}
	}
	return success;
}
