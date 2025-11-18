#ifndef BORDER_H
#define BORDER_H

#include <array>
#include <string>
#include <algorithm>

#include "TextureCloneable.hpp"


class Border : public Texture {
public:
	class Side {
	public:
	/*
		enum class Type {North, West, East, South,
		NorthWest, NorthEast, SouthWest, SouthEast, None};
		*/
		enum class Type {SouthWest, South, SouthEast, 
		SouthEastCorner, East, NorthEast, SouthWestCorner, 
		West, NorthEastCorner, None};
		std::string to_str() const;
		int to_int() const;
		static Side to_side(const std::string&);
		Side();
		Side(const Type&);
	private:
		static std::array<std::string, 10> strSide; 
		Type type_;		
	};

	Border(const SDL_Point& posOnScreen);
	virtual void update() override;
private:
	void init_src() = 0;
	virtual void init_src(const Border::Side&) = 0;
};


#endif
