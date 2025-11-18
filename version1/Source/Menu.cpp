#include "../Headers/Menu.hpp"
#include "../Headers/FormDrawer.hpp"


Menu::Menu(SDL_Renderer* renderer, SDL_Window* window) : 
FormDrawer(renderer, window) {
  int windowWidth, windowHeight;
  SDL_GetWindowSize(window, &windowWidth, &windowHeight);
  _buildBtnFrame = { windowWidth/3 + 35, 175, windowWidth/3 - 60, 125};
  _playBtnFrame = { windowWidth/3 + 35, 375, windowWidth/3 - 60, 125};
	_saveBtnFrame = { windowWidth/3 + 35, 575, windowWidth/3 -60, 125};
  _exitBtnFrame = { windowWidth/3 + 35, windowHeight - 200, 
	windowWidth/3 - 60, 125 };	
	_isBuildBtnHighlighted = false;
	_isPlayBtnHighlighted = false;
	_isSaveBtnHighlighted = false;
	_isExitBtnHighlighted = false;
	_clickedBtn = MENU_BTN::none;
}


void Menu::draw(SDL_Window* window) {
	int windowWidth, windowHeight;
  SDL_GetWindowSize(window, &windowWidth, &windowHeight);
	this->draw_background(Color::brown2);	
	this->add_title(window);
  this->add_borders(window);
  this->add_button(_buildBtnFrame, "BUILD", _isBuildBtnHighlighted);
	this->add_button(_playBtnFrame, "PLAY", _isPlayBtnHighlighted);
	this->add_button(_saveBtnFrame, "SAVE", _isSaveBtnHighlighted);
  this->add_button(_exitBtnFrame, "EXIT", _isExitBtnHighlighted);	
	SDL_RenderPresent(this->_renderer);
}


void Menu::highlight_btn(const SDL_MouseMotionEvent& motion) {
	_isBuildBtnHighlighted = Collider::is_mouse_inside_frame(motion, 
	_buildBtnFrame);
	_isPlayBtnHighlighted = Collider::is_mouse_inside_frame(motion, 
	_playBtnFrame);
	_isSaveBtnHighlighted = Collider::is_mouse_inside_frame(motion,
	_saveBtnFrame);
	_isExitBtnHighlighted = Collider::is_mouse_inside_frame(motion, 
	_exitBtnFrame);
}


void Menu::set_btn_clicked(const SDL_MouseButtonEvent& e) {
	if (Collider::is_click_inside_frame(e, _buildBtnFrame)) {
		_clickedBtn = MENU_BTN::build;
	}
	else if (Collider::is_click_inside_frame(e, _playBtnFrame)) {
		_clickedBtn = MENU_BTN::play;
	}
	else if (Collider::is_click_inside_frame(e, _saveBtnFrame)) {
		_clickedBtn = MENU_BTN::save;
	}
	else if (Collider::is_click_inside_frame(e, _exitBtnFrame)) {
		_clickedBtn = MENU_BTN::exit;
	}
	else {
		_clickedBtn = MENU_BTN::none;
	}
}


const MENU_BTN Menu::get_btn_clicked() const {
	return _clickedBtn;
}


void Menu::add_title(SDL_Window* window) {
	int windowWidth, windowHeight;
  SDL_GetWindowSize(window, &windowWidth, &windowHeight);
	std::cout << "Menu::add_title: loading font" << std::endl;
  TTF_Font* sans = 
	FontLoader::load_font("../Fonts/open-sans.regular.ttf");  
	std::cout << "Menu::add_title: font was loaded" << std::endl;
	SDL_Rect titleRect = {windowWidth/3+25, 25, windowWidth/3 - 50, 75};
	this->draw_text("MENU", sans, titleRect, Color::brown6);
}


void Menu::add_borders(SDL_Window* window) {
	int windowWidth, windowHeight;
  SDL_GetWindowSize(window, &windowWidth, &windowHeight);

	SDL_Rect leftBorder = {0, 0, windowWidth/3, windowHeight};
	SDL_Rect rightBorder = {windowWidth*2/3, 0, 
	windowWidth/3, windowHeight};

	this->draw_rectangle(leftBorder, Color::brown1);
  this->draw_rectangle(rightBorder, Color::brown1);	
}


void Menu::add_button(SDL_Rect& frame, const char* text, 
const bool& highlighted) {
  TTF_Font* sans = 
	FontLoader::load_font("../Fonts/open-sans.regular.ttf"); 
  SDL_Color textColor = highlighted ? Color::white : Color::brown5;

  const int btnFrameHorizontalThickness = 30;
	const int btnFrameVerticalThickness = 10;
	SDL_Rect buildBtnInsideLayer = {frame.x + btnFrameHorizontalThickness,
	frame.y + btnFrameVerticalThickness, 
	frame.w - 2*btnFrameHorizontalThickness, 
	frame.h - 2*btnFrameVerticalThickness};

	const int textBtnHorizontalFrameGap = 50;
  const int textBtnVerticalFrameGap = 20;

	SDL_Rect buildBtnTextRect = {
	buildBtnInsideLayer.x + textBtnHorizontalFrameGap,
	buildBtnInsideLayer.y + textBtnVerticalFrameGap, 
	buildBtnInsideLayer.w - 2*textBtnHorizontalFrameGap,
	buildBtnInsideLayer.h - 2*textBtnVerticalFrameGap};

  this->draw_rectangle_outline(frame, Color::brown4);	
	this->draw_rectangle_outline(buildBtnInsideLayer, Color::brown4);
	this->draw_frame(frame, buildBtnInsideLayer, Color::brown4);
	this->draw_rectangle(buildBtnInsideLayer, Color::yellow);
  
	this->draw_text(text, sans, buildBtnTextRect, textColor);	
}
