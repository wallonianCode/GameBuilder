#ifndef LEAFGREENTEXTURE_H
#define LEAFGREENTEXTURE_H

#include <array>
#include <string>
#include <algorithm>

#include "TextureCloneable.hpp"


// Textures on the right side of the LeafGreenTileset .png file
// e.g roads etc
class LeafGreenTexture : public Texture {
public:
	class Side {
	public:
		enum class Type {North, West, East, South,
		NorthWest, NorthEast, SouthWest, SouthEast, None};
		std::string to_str() const;
		int to_int() const;
		static Side to_side(const std::string&);
		Side();
		Side(const Type&);
	private:
		static std::array<std::string, 9> strSide; 
		Type type_;		
	};
	// virtual void save(std::ostream&) const override;

	// not every leafGreenTexture has a side: for example BigLand
	LeafGreenTexture(const SDL_Point&);
	LeafGreenTexture(const SDL_Point&, 
	const LeafGreenTexture::Side&);
	void save(std::ostream& os) const;
protected:
	Side side_; 
};
#endif
