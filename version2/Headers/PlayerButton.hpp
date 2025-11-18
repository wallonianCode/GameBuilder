#ifndef PLAYERBUTTON_H
#define PLAYERBUTTON_H

#include "MenuButton.hpp"
#include "PlayerState.hpp"

class PlayerButton : public MenuButton {
public:
	GameState* get_next_state() override;
	PlayerButton();
};

#endif
