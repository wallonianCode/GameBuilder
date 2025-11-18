#include  "../Headers/Anime.hpp"


// Constructor
Anime::Anime(const std::string& tileset) : tileset_(tileset) {}


friend std::ostream& operator<<(std::ostream& ostr, 
																const Anime& anime) {
	ostr << "Tileset: " << tileset_ << " ";
	return ostr;
}

