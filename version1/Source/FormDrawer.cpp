#include "../Headers/FormDrawer.hpp"

Comparator::Comparator(const SDL_Rect* dest) : _dest(dest) {}


SpriteComparator::SpriteComparator(const SDL_Rect* dest) : 
Comparator(dest) {}

FrameComparator::FrameComparator(const SDL_Rect* dest) : Comparator(dest) {}

TrainerComparator::TrainerComparator(const SDL_Rect* dest) : 
Comparator(dest) {}


bool SpriteComparator::operator()(const sprite& sprite)
{
  if (! _dest) { 
		throw std::runtime_error("SC::operator(): dest rect is null");
	}
	return (sprite.second.x == _dest->x) && (sprite.second.y == _dest->y);
}


bool FrameComparator::operator()(const frame& frame) {
  if (! _dest) {
		throw std::runtime_error("FC::operator(): dest rect is null");
	}
	return ((frame.second.x == _dest->x) && (frame.second.y == _dest->y));
}


bool TrainerComparator::operator()(const Trainer& trainer) {
	if (! _dest) {
		throw std::runtime_error("TC::operator(): dest rect is null");
	}
	sprite trSprite = trainer.get_sprite();
	return ((trSprite.second.x == _dest->x) && 
	(trSprite.second.y == _dest->y));
}


FormDrawer::FormDrawer(SDL_Renderer* renderer, SDL_Window* window): 
_renderer(renderer) {
	_hShift = 0;
	_vShift = 0;
	TextureLoader::load_texture(renderer, TILESET2);
}


void FormDrawer::draw_black_screen() {
	SDL_RenderClear(this->_renderer);
	SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
}	


void FormDrawer::draw_rectangle(const SDL_Rect& area, 
const SDL_Color& color) {
	SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, 
	color.a);
	SDL_RenderFillRect(this->_renderer, &area);
}


void FormDrawer::draw_rectangle_outline(const SDL_Rect& area, 
const SDL_Color& color) {
	SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, 
	color.a);
	SDL_RenderDrawRect(this->_renderer, &area);
}


void FormDrawer::draw_background(const SDL_Color& color) {
	SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, 255);
  SDL_RenderClear(this->_renderer);
}


void FormDrawer::draw_text(const char* text, TTF_Font* font, 
const SDL_Rect& area,	const SDL_Color& color) {
  if (! font) { 
	throw std::runtime_error("VP::draw_text: Font is not defined");
	}
	if (! text) {
	throw std::runtime_error("VP::draw_text: Text is not defined");
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
	if (! textSurface) {
	throw std::runtime_error("VP::draw_text: Could not create the surface"); 	}
	SDL_Texture* textTexture = 
	SDL_CreateTextureFromSurface(this->_renderer, textSurface);
	if (! textTexture) {
	throw std::runtime_error("VP::draw_text: Could not create the texture"); 	}
	SDL_RenderCopy(this->_renderer, textTexture, NULL, &area);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}


void FormDrawer::draw_frame(const SDL_Rect& outside, 
const SDL_Rect& inside, const SDL_Color& fillColor) {
	this->draw_rectangle(outside, fillColor);
	this->draw_rectangle(inside, Color::brown2);
}


void FormDrawer::draw_sprite(const sprite& sprite) {
  SDL_Rect src = TileManager::get_src(sprite.first);
	SDL_Rect dest = sprite.second;
	SDL_Texture* spriteTexture =
	TextureLoader::load_texture(_renderer, 
	TileManager::get_tileset(sprite.first));
	SDL_RenderCopy(_renderer, spriteTexture, &src, &dest);
}


void FormDrawer::draw_trainer(const Trainer& trainer) {
	this->draw_npc(trainer);
}


void FormDrawer::draw_frame(const frame& frame) {
}


void FormDrawer::draw(SDL_Window* window) {
	this->draw_background(Color::black);
	if (! _renderer) {
		throw std::runtime_error("FD::draw: renderer is null");
	}
	SDL_RenderPresent(_renderer);
}


void FormDrawer::draw_npc(const Trainer& trainer) {
	std::pair<sprite, SDL_Rect> trainerInfo = trainer.get_trainer_infos();
	sprite trainerSprite = trainerInfo.first;
	SDL_Rect src = trainerInfo.second;
  SDL_Rect dest = trainerSprite.second;
	Tile trainerOriginalTile = trainerSprite.first;

	SDL_Texture* trainerTexture =
	TextureLoader::load_texture(_renderer, 
	TileManager::get_tileset(trainerOriginalTile));
/*	
	std::cout << "Was trainer texture effectively loaded? " << 
	(trainerTexture != NULL) << std::endl;

	std::cout << "src: " << src.x << ", " << src.y << ", " << src.w <<
	", " << src.h << std::endl;

	std::cout << "dest: " << dest.x << ", " << dest.y << ", " <<
	dest.w << ", " << dest.h << std::endl;
*/	
	SDL_RenderCopy(_renderer, trainerTexture, &src, &dest);
}


void FormDrawer::clear() {
	_frames.clear();
	_sprites.clear();
	_npcs.clear();
}


void FormDrawer::increment_horizontal_shift() {
	this->add_to_horizontal_shift(4*S);
}


void FormDrawer::increment_vertical_shift() {
	this->add_to_vertical_shift(-4*S);
}


void FormDrawer::decrement_horizontal_shift() {
	this->add_to_horizontal_shift(-4*S);
}


void FormDrawer::decrement_vertical_shift() {
	this->add_to_vertical_shift(4*S);
}


void FormDrawer::reset_shift() {
	for (std::vector<sprite>::iterator itSprite = _sprites.begin();
	itSprite < _sprites.end(); itSprite++) {
		itSprite->second.x -= _hShift;
		itSprite->second.y -= _vShift;
	}
	_hShift = 0;
	_vShift = 0;
}


void FormDrawer::move_landscape_south(const float& speed) {
	this->add_to_vertical_shift(speed*4*S);
}


void FormDrawer::move_landscape_east(const float& speed) {
	this->add_to_horizontal_shift(speed*4*S);
}


void FormDrawer::move_landscape_north(const float& speed) {
	this->add_to_vertical_shift(-speed*4*S);
}


void FormDrawer::move_landscape_west(const float& speed) {
	this->add_to_horizontal_shift(-speed*4*S);
}


void FormDrawer::add_to_horizontal_shift(const int& quantity) {
	for (std::vector<sprite>::iterator itSprite = _sprites.begin(); 
	itSprite < _sprites.end(); itSprite++) {
		itSprite->second.x +=quantity;
	}
	_hShift += quantity;	
}


void FormDrawer::add_to_vertical_shift(const int& quantity) {
	_vShift += quantity;
	for (std::vector<sprite>::iterator itSprite = _sprites.begin();
	itSprite < _sprites.end(); itSprite++) {
		itSprite->second.y += quantity;
	}
}
