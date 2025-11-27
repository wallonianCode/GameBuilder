#ifndef COMPOSED_TEXTURE
#define COMPOSED_TEXTURE

#include <vector>
#include <utility>

#include "Texture.hpp"
#include "TextureCloneable.hpp"


class CompositeTexture : 
public TextureCloneable<Texture, CompositeTexture> {
public:
	CompositeTexture(const std::string& tileset, 
  								 std::vector<SDL_Rect>::iterator itSrcBegin,
									 std::vector<SDL_Rect>::iterator itSrcEnd,
									 std::vector<SDL_Rect>::iterator itDestBegin,
									 std::vector<SDL_Rect> ::iterator itDestEnd);

	void draw() override;
  	void update() override;
	
	SDL_Point get_upper_left_corner() const override;
private:
  	std::vector<std::pair<SDL_Rect, SDL_Rect>> vSrcDest_;

};

#endif
