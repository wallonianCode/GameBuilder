#ifndef GRASS_H
#define GRASS_H

#include <string>
#include <array>
#include <algorithm>
#include "LeafGreenTexture.hpp"


class Grass : public TextureCloneable<LeafGreenTexture, Grass> {
public:
	class Format {
		public:
			enum class Type {GreenWhite, GreenWhiteGreen, Green, White}; 
			static Format to_format(const std::string&);
			static std::string to_str(const Type&);
			
			SDL_Rect get_rect() const;
			Format(const Type&);
			static std::array<std::string, 4> strTypes_;  
		private:
			const SDL_Rect srcRect_[4] = 
			{ {6*S+2, 2, S-3, S-3}, {6*S+2, S+2, S-3, S-3},
				{7*S+2, S+2, S-3, S-3}, {6*S+2, 2*S+2, S-3, S-3} };
			Type type_ = Type::GreenWhite;
	};
	
	Grass(const SDL_Point&, const Format&);
	Grass(const SDL_Point&, const std::string&);
	void update() override;
private:
	void init_src() override;
	//void init_src(const Format&);

	Format format_;
};


#endif
