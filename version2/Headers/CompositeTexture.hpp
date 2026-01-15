#ifndef COMPOSED_TEXTURE
#define COMPOSED_TEXTURE

#include <vector>
#include <utility>

#include "Texture.hpp"
#include "TextureCloneable.hpp"


class CompositeTexture : 
public TextureCloneable<Texture, CompositeTexture> {
public:
	CompositeTexture();
	CompositeTexture(const std::string& tileset, 
					 std::vector<SDL_FRect>::iterator itSrcBegin,
					 std::vector<SDL_FRect>::iterator itSrcEnd,
					 std::vector<SDL_FRect>::iterator itDestBegin,
					 std::vector<SDL_FRect> ::iterator itDestEnd);
	CompositeTexture(const CompositeTexture&);

	void draw() override;
  void update() override;
	
	SDL_FPoint get_upper_left_corner() const override;
/*
	float get_width() const override;
	float get_height() const override;
	*/
	void move(const SDL_FPoint&);
	virtual bool is_coord_in_texture(const SDL_FPoint&) const override;
private:
  std::vector<std::pair<SDL_FRect, SDL_FRect>> vSrcDest_;

};

#endif
