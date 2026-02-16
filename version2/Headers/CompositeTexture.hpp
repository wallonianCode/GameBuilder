#ifndef COMPOSED_TEXTURE
#define COMPOSED_TEXTURE

#include <vector>
#include <utility>

#include "Texture.hpp"
#include "TextureCloneable.hpp"


class CompositeTexture : public Texture {
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
	void set_upper_left_corner(const SDL_FPoint&) override;

/*
	float get_width() const override;
	float get_height() const override;
	*/
	void move(const SDL_FPoint&);
	virtual bool is_coord_in_texture(const SDL_FPoint&) const override;
	// get all table entries for a composite texture diplayed on the map.
	void get_entries(
	std::vector<TextureTableEntry>::iterator itEntriesBegin,
	std::vector<TextureTableEntry>::iterator itEntriesEnd) const;
private:
  std::vector<std::pair<SDL_FRect, SDL_FRect>> vSrcDest_;

};

#endif
