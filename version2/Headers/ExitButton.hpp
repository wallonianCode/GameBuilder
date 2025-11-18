#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include "MenuButton.hpp"
#include "ExiterState.hpp"

class ExitButton : public MenuButton {
public:
	GameState* get_next_state();
	ExitButton();
};

#endif
