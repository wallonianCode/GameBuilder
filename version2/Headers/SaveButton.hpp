#ifndef SAVEBUTTON_H
#define SAVEBUTTON_H

#include "MenuButton.hpp"


class SaveButton : public MenuButton {
public:
	GameState* get_next_state() override;
	SaveButton();
};

#endif
