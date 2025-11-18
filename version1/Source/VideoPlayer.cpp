#include "../Headers/VideoPlayer.hpp"

VideoPlayer* VideoPlayer::_instance = nullptr;


VideoPlayer* VideoPlayer::get_instance() {
	VideoPlayer* vp = _instance != nullptr ? _instance : new VideoPlayer();
	return vp;
}


void VideoPlayer::initialize() {
	this->init_window();
	this->init_renderer();
	if (TTF_Init() < 0) {
	  std::cout << TTF_GetError() << std::endl;
		throw std::runtime_error("VP::initialize: ttf could not start");
	} 

  this->_formDrawer = new FormDrawer(this->_renderer, this->_window);
	if (! this->_formDrawer) {
		throw std::runtime_error("VP::initialize: FormDrawer \
		could not be instantiated");
	}
	_menu = new Menu(this->_renderer, this->_window);
  if (! this->_menu) {
		throw std::runtime_error("VP::initialize: MenuDrawer \
		could not be instantiated");
	}
	_play = new Play(this->_renderer, this->_window);
	if (! _play) {
		throw std::runtime_error("VP::initialize(): play is null");
	}
  _build = new Build(this->_renderer, 
	this->_window, get_build_left_boundary());
	if (! _build) {
		throw std::runtime_error("VP::initialize(): build is null");
	}
	_exit = new Exit(this->_renderer, this->_window);
	if (! _exit) {
		throw std::runtime_error("VP::initialize(): exit is null");
	}
	SDL_WarpMouseInWindow(_window, MOUSE_START_X, MOUSE_START_Y);
	SDL_SetWindowGrab(_window, SDL_TRUE);
}


void VideoPlayer::draw_menu() {
	int windowWidth, windowHeight;
	SDL_GetWindowSize(_window, &windowWidth, &windowHeight);
	if (! _menu) throw std::runtime_error("VP::draw_menu(): menu is null");	
	_menu->draw(_window);	
}


void VideoPlayer::draw_play() {
	if (! _play) throw std::runtime_error("VP::draw_play(): play is null");
	_play->draw(_window);
}


void VideoPlayer::draw_build() {
	if (! _build) {
		throw std::runtime_error("VP::draw_build(): build is null");
	}
	_build->draw(_window);
}


void VideoPlayer::draw_exit() {
  if (! _exit) throw std::runtime_error("VP::draw_exit(): exit is null");
	_exit->draw(_window);
}


void VideoPlayer::resize_screen(const int& width, const int& height) {
	SDL_SetWindowSize(this->_window, width, height);
}


void VideoPlayer::highlight_menu_btn(const SDL_MouseMotionEvent& motion) {
  if (! _menu) {
		throw std::runtime_error("VP::highlight_menu_btn: menu is null");
	}
	_menu->highlight_btn(motion);
}


void VideoPlayer::set_menu_btn_clicked(const SDL_MouseButtonEvent& e) {
  if (! _menu) {
		throw std::runtime_error("VP::set_menu_btn_clicked: menu is null");
	}
	_menu->set_btn_clicked(e);
}


const MENU_BTN VideoPlayer::get_menu_btn_clicked() const {
  if (! _menu) {
		throw std::runtime_error("VP::get_menu_btn_clicked: menu is null");
	}
	return _menu->get_btn_clicked();
}


void VideoPlayer::clear() {
	this->draw_black_screen();
	SDL_RenderClear(_renderer);
}


void VideoPlayer::add_sprite_to_build_state(const Tile& tile) {
	_build->add_sprite_at_mouse_pos(tile);	
}


void VideoPlayer::add_sprites_to_build_state(
const std::vector<Tile>& tiles) {
	_build->add_sprites_at_mouse_pos(tiles);
}


void VideoPlayer::add_npc_to_build_state(const Trainer& npc) {
	_build->add_npc_at_mouse_pos(npc);
}



void VideoPlayer::remove_sprite_from_build_state() {
	_build->remove_sprite_at_mouse_pos();
}


void VideoPlayer::remove_npc_from_build_state() {
	_build->remove_npc_at_mouse_pos();
}


int VideoPlayer::get_build_left_boundary() {
	return Build::get_left_boundary();
}


int VideoPlayer::get_build_separator_right_boundary() {
	return Build::get_separator_right_boundary();
}


bool VideoPlayer::is_mouse_in_build_selector() {
	return Build::is_mouse_in_selector();
}


bool VideoPlayer::is_mouse_in_build_separator() {
	return Build::is_mouse_in_separator();
}


Tile VideoPlayer::get_build_selector_tile_at_mouse_pos() {
	return _build->get_build_selector_tile_at_mouse_pos();		
}


std::vector<Tile> VideoPlayer::get_build_selector_tiles_at_mouse_pos() {
	return _build->get_build_selector_tiles_at_mouse_pos();
}


Trainer VideoPlayer::get_build_selector_npc_at_mouse_pos() {
	return _build->get_build_selector_npc_at_mouse_pos();
}


void VideoPlayer::set_next_build_selector_layer() {
	_build->set_next_build_selector_layer();
}


void VideoPlayer::save_build() {
	_build->save();
	_play->reload();
}



void VideoPlayer::increment_build_horizontal_shift() {
	_build->increment_horizontal_shift();
}


void VideoPlayer::increment_build_vertical_shift() {
	_build->increment_vertical_shift();
}


void VideoPlayer::decrement_build_horizontal_shift() {
	_build->decrement_horizontal_shift();
}


void VideoPlayer::decrement_build_vertical_shift() {
	_build->decrement_vertical_shift();
}


void VideoPlayer::increment_play_horizontal_shift() {
	_play->increment_horizontal_shift();
}


void VideoPlayer::increment_play_vertical_shift() {
	_play->increment_vertical_shift();
}


void VideoPlayer::decrement_play_horizontal_shift() {
	_play->decrement_horizontal_shift();
}


void VideoPlayer::decrement_play_vertical_shift() {
	_play->decrement_vertical_shift();
}


void VideoPlayer::reset_build_shift() {
	_build->reset_shift();
}


void VideoPlayer::add_red() {
	_build->add_sprite_at_mouse_pos(Tile::red);
}

void VideoPlayer::add_npc(const Trainer& npc) {
	_build->add_npc_at_mouse_pos(npc);
}


void VideoPlayer::move_trainer_south() {
	_play->move_trainer_south();
}


void VideoPlayer::move_trainer_east() {
	_play->move_trainer_east();
}

void VideoPlayer::move_trainer_north() {
	_play->move_trainer_north();
}

void VideoPlayer::move_trainer_west() {
	_play->move_trainer_west();
}

void VideoPlayer::move_landscape_south() {
	_play->move_landscape_south(0.25);
}

void VideoPlayer::move_landscape_east() {
	_play->move_landscape_east(0.25);
}

void VideoPlayer::move_landscape_north() {
	_play->move_landscape_north(0.25);
}

void VideoPlayer::move_landscape_west() {
	_play->move_landscape_west(0.25);
}

void VideoPlayer::set_trainer_still() {
	_play->set_trainer_still();
}

void VideoPlayer::update_npcs() {
	_play->update_npcs();
}

/* ------------------------------------------------------------------
										PRIVATE METHODS
// ------------------------------------------------------------------
*/
void VideoPlayer::init_renderer() {
	this->_renderer = SDL_CreateRenderer(this->_window, -1, 
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | 
	SDL_RENDERER_TARGETTEXTURE);
	
	if (!this->_renderer) {
		throw std::runtime_error("VideoPlayer::init_renderer: \
		renderer not created\n");
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
  {
		std::printf( "SDL_image could not initialize! SDL_image\
		Error: %s\n", IMG_GetError() );
	}
	//SDL_SetRenderDrawBlendMode(this->_renderer, SDL_BLENDMODE_NONE);
}


void VideoPlayer::init_window() {
	this->_window = SDL_CreateWindow(WINDOW_TITLE.c_str(), 
	SDL_WINDOWPOS_CENTERED, 
	SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (! this->_window) {
		throw std::runtime_error("VideoPlayer::init_window: \
		windows not created");
	}
}


VideoPlayer::VideoPlayer() {
  if(SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
		throw std::runtime_error("VideoPlayer::VideoPlayer: \
		failed to initialize the SDL subsystem");
	}	
}


void VideoPlayer::draw_background(const SDL_Color& color) {
	SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, 
	color.b, 0xFF);
  SDL_RenderClear(this->_renderer);
}


void VideoPlayer::draw_black_screen() {
	this->draw_background(Color::black);
}
