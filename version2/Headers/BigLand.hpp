#ifndef BIGLAND_H
#define BIGLAND_H

#include <array>
#include <algorithm>
#include "LeafGreenTexture.hpp"


class BigLand : public TextureCloneable<LeafGreenTexture, BigLand> {
public:	
	class Name {
	public:
		enum class Type {hugeTreeUpLeft, hugeTreeUpCtr, hugeTreeUpRight,
		hugeTreeCtrLeft1, hugeTreeCtrCtr1, hugeTreeCtrRight1,
		hugeTreeCtrLeft2, hugeTreeCtrCtr2, hugeTreeCtrRight2,
		hugeTreeDownLeft, hugeTreeDownCtr, hugeTreeDownRight,
		pinTreeUpLeft, pinTreeUpRight, pinTreeCtrLeft, pinTreeCtrRight,
		pinTreeDownLeft, pinTreeDownRight, 
		slenderPinTreeUp, slenderPinTreeCtr, slenderPinTreeDown};
		Name(const Type& type);
		static Name to_name(const std::string&);
		void save(std::ostream& os) const;
		SDL_Rect get_src();	
		SDL_Point get_next_pos(const SDL_Point&) const;
	private:
		std::string to_str() const;
		static std::array<SDL_Rect, 21> arSources; 
		static std::array<std::string, 21> arString;	
		Name::Type type_;
	};

	void update();
	void save(std::ostream&) const override;
	
	SDL_Point get_next_pos() const override;
 	 

	BigLand(const SDL_Point&);
	BigLand(const SDL_Point&, const BigLand::Name&);
	BigLand(const SDL_Point&, const std::string&);	
private:
	void init_src();
	void init_src(BigLand::Name&);
	Name name_ = Name(BigLand::Name::Type::hugeTreeUpLeft);
};

#endif
