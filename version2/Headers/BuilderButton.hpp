#ifndef BUILDERBUTTON_H
#define BUILDERBUTTON_H

#include "MenuButton.hpp"
#include "BuilderState.hpp"

class BuilderButton : public MenuButton {
public:
	GameState* get_next_state() override;
	BuilderButton();
};

#endif
