#include "../Headers/Build.hpp"



Build::Build(SDL_Renderer* renderer, SDL_Window* window, 
const int& leftBoundary): 
FormDrawer(renderer, window), _leftBoundary(leftBoundary) {
	_layer = Layer::layer1;
	this->init_build_selector();
}


void Build::draw(SDL_Window*) {
	this->draw_background(Color::green3);
	if (_layer == Layer::layer1) {
		for (auto sprite: _spritesBuildSelectorLayer1) {
			this->draw_sprite(sprite);
		}
	}
	else if (_layer == Layer::layer2) {
		for (auto sprite: _spritesBuildSelectorHugeTree) {
			this->draw_sprite(sprite); 
		}
		for (auto sprite: _spritesBuildSelectorPinTree) {
			this->draw_sprite(sprite); 
		}
		for (auto sprite: _spritesBuildSelectorSlenderPinTree) {
			this->draw_sprite(sprite); 
		}
	}
	else if (_layer == Layer::layer3) {
		for (auto npc : _npcsBuildSelector) {
			this->draw_npc(npc);
		}
	}
	for (auto sprite : _spritesBuildSeparator) {
		this->draw_sprite(sprite);
	}
  for (auto sprite : _sprites) {
		if (sprite.second.x >= get_separator_right_boundary()) {
			this->draw_sprite(sprite);
		}
	}	
	for (auto npc: _npcs) {
		std::pair<sprite, SDL_Rect> npcInfos = npc.get_trainer_infos();
		sprite npcSprite = npcInfos.first;
		if (npcSprite.second.x >= get_separator_right_boundary()) {
			this->draw_npc(npc);
		}
	}
  if (Build::is_mouse_in_build_selector()) {	
		if (_layer == Layer::layer2) {
			this->draw_rectangle_outline(
			get_outline_rect_in_selector_at_mouse_pos(), Color::red);
		}
		else {
			this->draw_rectangle_outline(
			TileManager::get_tile_at_mouse_pos(), Color::red);
		}
	}
	SDL_RenderPresent(_renderer);
}


std::vector<sprite>::iterator Build::get_sprite_at(const SDL_Rect& pos) {
	SpriteComparator comp = SpriteComparator(&pos);
	std::vector<sprite>::iterator retour;
	if (pos.x >= get_separator_right_boundary()) {
		retour = std::find_if(_sprites.begin(), _sprites.end(), comp);
	}
	else {
		retour = std::find_if(_spritesBuildSelectorLayer1.begin(), 
		_spritesBuildSelectorLayer1.end(), comp);
	}
	return retour;
}


std::vector<Trainer>::iterator Build::get_npc_at(const SDL_Rect& pos) {
	TrainerComparator comp = TrainerComparator(&pos);
	std::vector<Trainer>::iterator itRetour;
	if (pos.x >= get_separator_right_boundary()) {
		itRetour = std::find_if(_npcs.begin(), _npcs.end(), comp);
	}
	else {
		itRetour = std::find_if(_npcsBuildSelector.begin(),
		_npcsBuildSelector.end(), comp);
	}
	return itRetour;
}


std::vector<sprite> Build::get_sprites_at(const SDL_Rect& pos) {
	SpriteComparator comp = SpriteComparator(&pos);
	
	std::vector<sprite>::iterator itSpritesHugeTree =
	std::find_if(_spritesBuildSelectorHugeTree.begin(),
	_spritesBuildSelectorHugeTree.end(), comp);

	std::vector<sprite>::iterator itSpritesPinTree =
	std::find_if(_spritesBuildSelectorPinTree.begin(),
	_spritesBuildSelectorPinTree.end(), comp);

	std::vector<sprite>::iterator itSpritesSlenderPinTree =
	std::find_if(_spritesBuildSelectorSlenderPinTree.begin(),
	_spritesBuildSelectorSlenderPinTree.end(), comp);

	std::vector<sprite> retour;
	if (itSpritesHugeTree != _spritesBuildSelectorHugeTree.end()) {
		retour = _spritesBuildSelectorHugeTree;
	}
	else if (itSpritesPinTree != _spritesBuildSelectorPinTree.end()) {
		retour = _spritesBuildSelectorPinTree;
	}
	else if (itSpritesSlenderPinTree != 
	_spritesBuildSelectorSlenderPinTree.end()) {
		retour = _spritesBuildSelectorSlenderPinTree;
	}
	return retour;
}


Tile Build::get_build_selector_tile_at_mouse_pos() {
	std::vector<sprite>::iterator itSprite = 
	get_sprite_at(TileManager::get_tile_at_mouse_pos());
	Tile tile = itSprite != _sprites.end() ? itSprite->first : Tile::sand;
	return tile;
}


std::vector<Tile> Build::get_build_selector_tiles_at_mouse_pos() {
	std::vector<sprite> sprites =
	get_sprites_at(TileManager::get_tile_at_mouse_pos());
	std::vector<Tile> tiles;
	if (sprites.size() != 0) {
		for (sprite s : sprites) {
			tiles.push_back(s.first);
		}
	}
	else {
		std::cout << "No tiles selected" << std::endl;
	}
	return tiles;
}


Trainer Build::get_build_selector_npc_at_mouse_pos() {
	Trainer trRetour;
	std::vector<Trainer>::iterator itNpc =
	get_npc_at(TileManager::get_tile_at_mouse_pos());	
	if (itNpc != _npcsBuildSelector.end()) {
		trRetour = *itNpc;
	}	
	return trRetour;
}


std::vector<sprite>::iterator
Build::get_frame_at(const SDL_Rect& pos) {
	FrameComparator comp = FrameComparator(&pos);
	return std::find_if(_frames.begin(), _frames.end(), comp);
}


void Build::add_sprite_at_mouse_pos(const Tile& tile) {
	if (_layer == Layer::layer1) {
		SDL_Rect dest = TileManager::get_tile_at_mouse_pos();
		this->free_rect(dest);
		_sprites.push_back(std::make_pair(tile, dest));
	}
}


void Build::add_sprites_at_mouse_pos(const std::vector<Tile>& tiles) {
	if (_layer == Layer::layer2) {
		SDL_Rect dest = TileManager::get_tile_at_mouse_pos();
		if (tiles.size() == 3) {
			for (Tile tile : tiles) {
				this->free_rect(dest);
				_sprites.push_back(std::make_pair(tile, dest));
				dest = TileManager::get_down_tile(dest);
			}	
		}
		else if (tiles.size() == 6) {
			int j = 0;
			while (j < 6) {
				this->free_rect(dest);
				_sprites.push_back(std::make_pair(tiles.at(j), dest));
				if ((j % 2) == 0) {
					dest = TileManager::get_right_tile(dest);		
				}
				else {
					dest = TileManager::get_left_tile(dest);
					dest = TileManager::get_down_tile(dest);
				}
				j++;
			}
		}
		else if (tiles.size() == 12) {
			int j = 0;
			while (j < 12) {
				this->free_rect(dest);
				_sprites.push_back(std::make_pair(tiles.at(j), dest));
				if ((j % 3) == 0 || (j % 3) == 1) {
					dest = TileManager::get_right_tile(dest);
				}
				else {
					dest = TileManager::get_left_tile(dest);
					dest = TileManager::get_left_tile(dest);
					dest = TileManager::get_down_tile(dest);
				}
				j++;
			}
		}
	}
}


void Build::add_npc_at_mouse_pos(Trainer npc) {
	if (_layer == Layer::layer3) {
		SDL_Rect dest = TileManager::get_tile_at_mouse_pos();
		this->free_rect(dest);
		npc.set_position(dest);
		sprite npcSprite = npc.get_sprite();
		std::cout << "Build::add_npc_at_mouse_pos: " << 
		TileManager::to_string(npcSprite.first) << std::endl;
		_npcs.push_back(npc);	
	}
}

			
void Build::remove_sprite_at_mouse_pos() {
	SDL_Rect dest = TileManager::get_tile_at_mouse_pos();
	this->free_rect(dest);
}


void Build::remove_npc_at_mouse_pos() {
	SDL_Rect dest = TileManager::get_tile_at_mouse_pos();
	this->free_rect_from_npc(dest);
}


void Build::add_frame_at_mouse_pos() {}


void Build::remove_frame_at_mouse_pos() {
	_frames.erase(this->get_frame_at(TileManager::get_tile_at_mouse_pos()));
}


bool Build::is_mouse_in_build_selector() {
	int x, y;
	SDL_GetMouseState(&x, &y);
  return x < _leftBoundary;
}


void Build::set_next_build_selector_layer() {
	switch (_layer) {
		case Layer::layer1 : 
			_layer = Layer::layer2;
			break;
		case Layer::layer2 :
			_layer = Layer::layer3;
			break;
		case Layer::layer3 :
			_layer = Layer::layer1;
			break;
		default:
			break;
	}
}

void Build::erase_sprite_set(std::vector<sprite>::iterator itSprite) {
	std::pair<std::vector<sprite>::iterator, 
	std::vector<sprite>::iterator> bounds;
	std::array<Tile, 12> tilesHugeTree = TileManager::get_tiles_huge_tree();
	std::array<Tile, 6> tilesPinTree = TileManager::get_tiles_pin_tree();
	std::array<Tile, 3> tilesSlenderPinTree = 
	TileManager::get_tiles_slender_pin_tree();

	int i = 0;
	for (Tile t : tilesHugeTree) {
		if (itSprite->first == t) {
			bounds = std::make_pair(itSprite-i, itSprite+12-i);
		}
		i++;
	}
	i = 0;
	for (Tile t : tilesPinTree) {
		if (itSprite->first == t) {
			bounds = std::make_pair(itSprite-i, itSprite+6-i);
		}
		i++;
	}
	i = 0;
	for (Tile t : tilesSlenderPinTree) {
		if (itSprite->first == t) {
			bounds = std::make_pair(itSprite-i, itSprite+3-i);
		}
		i++;
	}		
	_sprites.erase(bounds.first, bounds.second);
}


SDL_Rect Build::get_outline_rect_in_selector_at_mouse_pos() {
	SDL_Rect pos = TileManager::get_tile_at_mouse_pos();
	SDL_Rect outline = pos;
	SpriteComparator comp = SpriteComparator(&pos);	
	
	std::vector<sprite>::iterator itHugeTree = 
	std::find_if(_spritesBuildSelectorHugeTree.begin(), 
	_spritesBuildSelectorHugeTree.end(), comp);

	std::vector<sprite>::iterator itPinTree = 
	std::find_if(_spritesBuildSelectorPinTree.begin(), 
	_spritesBuildSelectorPinTree.end(), comp);

	std::vector<sprite>::iterator itSlenderPinTree = 
	std::find_if(_spritesBuildSelectorSlenderPinTree.begin(), 
	_spritesBuildSelectorSlenderPinTree.end(), comp);

	if (itHugeTree != _spritesBuildSelectorHugeTree.end()) {	
		outline = {_spritesBuildSelectorHugeTree.begin()->second.x, 
		_spritesBuildSelectorHugeTree.begin()->second.y, 3*4*S, 4*4*S};
	}
	else if (itPinTree != _spritesBuildSelectorPinTree.end()) {
		outline = {_spritesBuildSelectorPinTree.begin()->second.x, 
		_spritesBuildSelectorPinTree.begin()->second.y, 2*4*S, 3*4*S};
	}
	else if (itSlenderPinTree != 
	_spritesBuildSelectorSlenderPinTree.end()) {
		outline = {_spritesBuildSelectorSlenderPinTree.begin()->second.x, 
		_spritesBuildSelectorSlenderPinTree.begin()->second.y, 4*S, 3*4*S};
	}
	return outline;
}


int Build::get_left_boundary() {
	return BUILD_LEFT_BOUNDARY - (BUILD_LEFT_BOUNDARY % (4*S));
}


int Build::get_separator_right_boundary() {
	return BUILD_SEPARATOR_RIGHT_BOUNDARY - 
	(BUILD_SEPARATOR_RIGHT_BOUNDARY % (4*S));
}


bool Build::is_mouse_in_selector() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	return x < get_left_boundary();
}


bool Build::is_mouse_in_separator() {
	int x, y;
	SDL_GetMouseState(&x, &y);
  return (x > get_left_boundary()) && 
	(x < get_separator_right_boundary());	
}


void Build::save() {
	std::cout << "Saving the build!" << std::endl;
	const char* pathSprites = SAVE_FILE_SPRITES.c_str();
	const char* pathTrainers = SAVE_FILE_NPCS.c_str();

	std::ofstream saveFileSprites(pathSprites);
	std::ofstream saveFileTrainers(pathTrainers);
	
	//std::string data("1st line\n2nd line\n");
	char delim = ',';
	for (sprite s : _sprites) {
		saveFileSprites << TileManager::to_string(s.first) << delim 
										<< s.second.x << delim 
						 				<< s.second.y << delim
						 				<< s.second.w << delim
						 				<< s.second.h << "\n";
	}
	saveFileSprites.close();

	for(Trainer t : _npcs) {
		saveFileTrainers << t << "\n";
	}

	saveFileTrainers.close();
}


/* -------------------------------------------------------------------
												PRIVATE METHODS
   --------------------------------------------------------------------
*/
void Build::init_build_selector() {
	Tile tileAr[81] = {Tile::sand, Tile::grass1, Tile::grass2, 
	Tile::grass3, 
	Tile::grass4, Tile::wildgrass1, Tile::flowers1, Tile::cuttree1, 
	Tile::waterUpLeft1, Tile::waterUpCtr1, Tile::waterUpRight1, 
	Tile::waterCtrLeft1, 
	Tile::waterCtrCtr1, Tile::waterCtrRight1, Tile::waterDownLeft1, 
	Tile::waterDownCtr1, Tile::waterDownRight1, Tile::sandRoadNSLeftBorder,
	Tile::sandRoadNSRightBorder, Tile::sandRoadWEUpperBorder,
	Tile::sandRoadWELowerBorder, Tile::sandRoadUpperLeftCorner, 
	Tile::sandRoadUpperRightCorner, Tile::sandUpperLeft, 
	Tile::sandUpperRight, Tile::sandLowerLeft, Tile::sandLowerRight, 
	Tile::moos, 
	Tile::moosRoadNSLeftBorder, Tile::moosRoadNSRightBorder, 
	Tile::moosRoadWEUpperBorder, Tile::moosRoadWELowerBorder, 
	Tile::moosRoadLowerLeftCorner, Tile::moosRoadLowerRightCorner, 
	Tile::moosRoadUpperLeftCorner, Tile::moosRoadUpperRightCorner,
	Tile::moosUpperRight, Tile::moosUpperLeft, Tile::moosLowerRight, 
	Tile::moosLowerLeft, Tile::mud, Tile::mudRoadNSLeftBorder, 
	Tile::mudRoadNSRightBorder, Tile::mudRoadWEUpperBorder, 
	Tile::mudRoadWELowerBorder,
	Tile::mudRoadLowerLeftCorner, Tile::mudRoadLowerRightCorner, 
	Tile::mudRoadUpperLeftCorner, Tile::mudRoadUpperRightCorner, 
	Tile::mudUpperRight, 
	Tile::mudUpperLeft, Tile::mudLowerRight, Tile::mudLowerLeft,
	Tile::borderGrassDownLeft, Tile::borderGrassDownCtr, 
	Tile::borderGrassDownRight, 
	Tile::borderGrassLowerRightCorner, Tile::borderGrassRightCtr, 
	Tile::borderGrassRightUp, Tile::borderGrassLowerLeftCorner, 
	Tile::borderGrassLeftCtr, Tile::borderUpperRightCorner, 
	Tile::borderGrassUpperRightCorner, Tile::borderLowerLeftCorner, 
	Tile::borderLeftCtr, Tile::borderDownLeft, Tile::borderDownCtr, 
  Tile::borderDownRight, Tile::borderLowerRightCorner, 
	Tile::borderRightCtr, 
	Tile::borderRightUp, Tile::deepWaterUpLeft, Tile::deepWaterUpCtr, 
	Tile::deepWaterUpRight, Tile::deepWaterCtrLeft, Tile::deepWaterCtrCtr, 
	Tile::deepWaterCtrRight, Tile::deepWaterDownLeft, 
	Tile::deepWaterDownCtr, 
	Tile::deepWaterDownRight, Tile::bush};
 
  int x = 0; 
	int y = 0;
	for (Tile tile : tileAr) {
		SDL_Rect dest = {x*4*S, y*4*S, 4*S, 4*S};
		_spritesBuildSelectorLayer1.push_back(std::make_pair(tile, dest));
		if ((x % 6) == 5) {
			x = 0;
			y++;
		}
		else {
			x++;
		}
	}
	
	y = 0;
  while (y*4*S < WINDOW_HEIGHT) {
		SDL_Rect destLeftColumn = {6*4*S, y*4*S, 4*S, 4*S};
		SDL_Rect destRightColumn = {7*4*S, (y++)*4*S, 4*S, 4*S};
		_spritesBuildSeparator.push_back(std::make_pair(Tile::bush, 
		destLeftColumn));
		_spritesBuildSeparator.push_back(std::make_pair(Tile::bush, 
		destRightColumn));
	}


	Tile tilesHugeTree[12] = 
	{ Tile::hugeTreeUpLeft, Tile::hugeTreeUpCtr, Tile::hugeTreeUpRight, 
	Tile::hugeTreeCtrLeft1, Tile::hugeTreeCtrCtr1, Tile::hugeTreeCtrRight1, 
	Tile::hugeTreeCtrLeft2, Tile::hugeTreeCtrCtr2, Tile::hugeTreeCtrRight2,
	Tile::hugeTreeDownLeft, Tile::hugeTreeDownCtr, Tile::hugeTreeDownRight
	};

	Tile tilesPinTree[6] = 
	{ Tile::pinTreeUpLeft, Tile::pinTreeUpRight, Tile::pinTreeCtrLeft, 
	Tile::pinTreeCtrRight, Tile::pinTreeDownLeft, Tile::pinTreeDownRight };

	Tile tilesSlenderPinTree[3] =
	{ Tile::slenderPinTreeUp, Tile::slenderPinTreeCtr, 
	Tile::slenderPinTreeDown };
	
	x = 0;
	y = 0;
  for (Tile t : tilesHugeTree) {
		SDL_Rect dest = {x*4*S, y*4*S, 4*S, 4*S};	
		if ((x % 3) == 2) {
			x = 0;
			y++;
		}
		else {
			x++;
		}
		_spritesBuildSelectorHugeTree.push_back(std::make_pair(t, dest));
	}

	x = 3;
	y = 0;
	for (Tile t : tilesPinTree) {
		SDL_Rect dest = {x*4*S, y*4*S, 4*S, 4*S};	
		if ((x % 2) == 0) {
			x = 3;
			y++;
		}
		else {
			x++;	
		}
		_spritesBuildSelectorPinTree.push_back(std::make_pair(t, dest));
	}

	x = 5;
	y = 0;
	for (Tile t : tilesSlenderPinTree) {
		SDL_Rect dest = {x*4*S, (y++)*4*S, 4*S, 4*S};
		_spritesBuildSelectorSlenderPinTree.push_back(
		std::make_pair(t, dest));
	}


	Tile tilesNpcs[22] = 
	{Tile::red, Tile::flora, Tile::blue, Tile::chen,
	Tile::mama, Tile::littleGreenGirl, Tile::littlePurpleBoy,
	Tile::oldAdventurer, Tile::nurse2, 
	Tile::littleVioletGirl, Tile::womanRedDressBrownHairs, 
	Tile::manRedSweatBlueArms, Tile::manWhiteCollet, 
	Tile::oldManBartBald, Tile::oldLady,
	Tile::scout, Tile::parcEmployeeMale, Tile::parcEmployeeFemale,
	Tile::mountainer, Tile::karateka, Tile::rocketMale, 
	Tile::rocketFemale};

	x = 0;
	y = 0;
	for (Tile t : tilesNpcs) {
		SDL_Rect dest = {x*4*S, y*4*S, 4*S, 4*S};
		Trainer trainer = Trainer(t);
		trainer.set_position(dest);
		_npcsBuildSelector.push_back(trainer);

		if ((x % 6) == 5) {
			x = 0;
			y++;
		}
		else {
			x++;
		}
	}


}	


void Build::free_rect(const SDL_Rect& dest) {
	auto spriteIt = this->get_sprite_at(dest);
	if (spriteIt != _sprites.end()) {
		if (TileManager::is_part_of_set(spriteIt->first)) {
			erase_sprite_set(spriteIt);	
		}
		 else {
			_sprites.erase(spriteIt);	
		}
	}
}


void Build::free_rect_from_npc(const SDL_Rect& dest) {
	auto npcIt = this->get_npc_at(dest);
	if (npcIt != _npcs.end()) {
		_npcs.erase(npcIt);
	}
}


bool Build::is_tile_taken(const SDL_Rect& pos) {
	bool isTileTaken = false;
	for (auto& sprite : _sprites) {
		if (sprite.second.x == pos.x && sprite.second.y == pos.y) {
			isTileTaken = true;	
		}
	}
	return isTileTaken;
}
