#include "../Headers/Map.hpp"


void Map::draw() {
	for (std::vector<Texture*>::iterator itTexture = vTextures_.begin() ;
	itTexture != vTextures_.end(); itTexture++) {
		(*itTexture)->draw();
	}
}


void Map::add_texture(Texture* texture) {
	vTextures_.push_back(texture);
}


void Map::add_texture_at_mouse_pos(Texture* texture) {	
	float x, y;
	Texture* tCopy = texture->clone();

	SDL_GetMouseState(&x, &y);
  tCopy->set_upper_left_corner({x-((int)x % TILE_DIM), 
	y-((int)y % TILE_DIM)});	
	vTextures_.push_back(tCopy);
}


void Map::remove_texture(const SDL_FPoint& pos) {
	std::vector<Texture*>::iterator found =
	std::find_if(vTextures_.begin(), vTextures_.end(), 
	[pos](Texture* texture){return texture->get_upper_left_corner().x == pos.x &&
	texture->get_upper_left_corner().y == pos.y;});
	if (found != vTextures_.end()) 
		vTextures_.erase(found);	
}


void Map::remove_texture_at_mouse_pos() {
	float x, y;
	SDL_GetMouseState(&x, &y);
	this->remove_texture({x, y});
}


void Map::update() {}


void Map::set_frame_pos(const SDL_FPoint& newPos) {
	frame_.set_pos_on_screen(newPos);
}


void Map::draw_frame() {
	frame_.draw();
}


Map::Map() {}


Map::Map(const std::string& filename) {
	//this->load(filename);
}


Map::Map(std::vector<Texture*>::iterator itLandBegin,
				 std::vector<Texture*>::iterator itLandEnd) {
	vTextures_ = std::vector<Texture*>(itLandBegin, itLandEnd);
}


//-------------------------- PRIVATE -------------------------------

std::vector<std::string> Map::split(std::string s, 
const std::string& delimiter) {
  std::vector<std::string> tokens;
  size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
  	token = s.substr(0, pos);
	  tokens.push_back(token);
		s.erase(0, pos + delimiter.length());
  }
	tokens.push_back(s);

return tokens;
}
