#ifndef MENUDRAWER_H
#define MENUDRAWER_H


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "FormDrawer.hpp"
#include "FontLoader.hpp"
#include "Collider.hpp"


enum class MENU_BTN {
	build,
	play,
	save,
	exit,
	none	
};


class Menu : public FormDrawer {
public:
	Menu(SDL_Renderer*, SDL_Window*);
  void draw(SDL_Window* window) override;
	void highlight_btn(const SDL_MouseMotionEvent&);
	const MENU_BTN get_btn_clicked() const;
	void set_btn_clicked(const SDL_MouseButtonEvent& e);
private:
  void add_title(SDL_Window* window);
  void add_borders(SDL_Window* window);
	void add_button(SDL_Rect&, const char*, const bool&);

  SDL_Rect _buildBtnFrame;
  SDL_Rect _playBtnFrame;
	SDL_Rect _saveBtnFrame;
  SDL_Rect _exitBtnFrame;

	bool _isBuildBtnHighlighted, _isPlayBtnHighlighted, 
	_isSaveBtnHighlighted, _isExitBtnHighlighted;
	MENU_BTN _clickedBtn;
	SDL_Window* _window;
};


#endif
