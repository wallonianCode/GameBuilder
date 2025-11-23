#ifndef COMPOSED_TEXTURE
#define COMPOSED_TEXTURE

#include <vector>
#include <pair>

#include "Texture.hpp"

//TODO replace inner classes with factory methods


/// This class is a placeholder for the source and destination rectangles.
/// These rectangles are necessary parameters for the renderer.


//TODO develop a SimpleTexture class to take on the methods that only
//     make sense for SimpleTextures.

class CompositeTexture : 
public TextureCloneable<Texture, CompositeTexture> {
public:
	CompositeTexture(const std::string& tileset, 
  								 std::vector::iterator<SDL_Rect> itSrcBegin,
									 std::vector::iterator<SDL_Rect> itSrcEnd,
									 std::vector::iterator<SDL_Rect> itDestBegin,
									 std::vector::iterator<SDL_Rect> itDestEnd);

  void draw() override;
  void update() override;
	void save() override;
	
	//TODO save in a database
	void save_dest(std::ostream&) const override;
	SDL_Point get_upper_left_corner() const override;
	void set_pos_on_screen(const SDL_Point&) const override;
private:
  std::vector<std::pair<SDL_Rect, SDL_Rect>> vSrcDest_;

};

#endif
