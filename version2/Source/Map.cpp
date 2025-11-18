#include "../Headers/Map.hpp"


void Map::draw() {
	for (std::vector<Texture*>::iterator itTexture = vTextures_.begin() ;
	itTexture != vTextures_.end(); itTexture++) {
		(*itTexture)->draw();
	}
}


void Map::save(const std::string& fileName) {
	const char* path = fileName.c_str();
	std::ofstream saveFile(path);
	for (Texture* t : vTextures_) {
		t->save(saveFile);
		saveFile << "\n";
	}
	//TODO save the characters
	saveFile.close();
}


void Map::load(const std::string& fileName) {
	vTextures_.clear();
	std::string line;
	std::ifstream textureFile;
	textureFile.open(fileName);
	while (getline(textureFile, line)) {
		std::vector<std::string> tokens = split(line, " ");
		// MoosRoad,NorthWest,dest.x,dest.y,dest.w,dest.h
		std::string type = tokens.at(0);
		std::string subType = tokens.at(1);
		std::string side = tokens.at(2); 
		std::string x = tokens.at(3);
		std::string y = tokens.at(4);
		std::string w = tokens.at(5);
		std::string h = tokens.at(6);
		Texture* texture = 
		TextureCreator::create_texture(type, subType, 
		{std::stoi(x), std::stoi(y), std::stoi(w), std::stoi(h)});
		vTextures_.push_back(texture);	
	}
}


void Map::add_texture(Texture* texture) {
	vTextures_.push_back(texture);
}


void Map::add_texture_at_mouse_pos(Texture* texture) {	
	int x, y;
	Texture* tCopy = texture->clone();

	SDL_GetMouseState(&x, &y);
  tCopy->set_pos_on_screen({x-(x % TILE_DIM), y-(y % TILE_DIM)});	
	vTextures_.push_back(tCopy);
}


void Map::add_textures_at_mouse_pos(std::vector<Texture*> vTextures) {
	int xMouse, yMouse;
	SDL_GetMouseState(&xMouse, &yMouse);
	xMouse = xMouse - (xMouse % TILE_DIM);
	yMouse = yMouse - (yMouse % TILE_DIM);

	SDL_Point posToDraw = {xMouse, yMouse};
	//TODO we have no guarantee that the vector is sorted
	for (std::vector<Texture*>::iterator textIt = vTextures.begin();
	textIt != vTextures.end(); textIt++) {
		Texture* blTexture = (*textIt)->clone();
		blTexture->set_pos_on_screen(posToDraw);
		//TODO maybe save all positions for all textures at once knowing one
		//     or develop a hugeTree class etc that draws itself fully
		//     last solution would be easier
		posToDraw = blTexture->get_next_pos();	
		vTextures_.push_back(blTexture);
	}
}


//TODO return a boolean
void Map::remove_texture(const SDL_Point& posOnScreen) {
	TexturePositionComparator comparator(posOnScreen);
	std::vector<Texture*>::iterator found =
	std::find_if(vTextures_.begin(), vTextures_.end(), comparator);
	if (found != vTextures_.end()) 
		vTextures_.erase(found);	
}


void Map::remove_texture_at_mouse_pos() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	this->remove_texture({x, y});
}


void Map::update() {}


void Map::set_frame_pos(const SDL_Point& newPos) {
	frame_.set_pos_on_screen(newPos);
}


void Map::draw_frame() {
	frame_.draw();
}


Map::Map() {}


Map::Map(const std::string& filename) {
	this->load(filename);
}


Map::Map(std::vector<Texture*>::iterator itLandBegin,
				 std::vector<Texture*>::iterator itLandEnd,
				 std::vector<Character*>::iterator itCharacterBegin,
				 std::vector<Character*>::iterator itCharacterEnd) {
	vTextures_ = std::vector(itLandBegin, itLandEnd);
	vCharacters_ = std::vector(itCharacterBegin, itCharacterEnd);
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
