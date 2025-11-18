#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "ThreeColumnsBackground.hpp"
#include "BuilderButton.hpp"
#include "PlayerButton.hpp"
#include "SaveButton.hpp"
#include "ExitButton.hpp"
#include "GameState.hpp"
#include "Drawable.hpp"
#include "Color.hpp"


class GameMenu : public Drawable {
public:
	void draw() override;
	void update();
	GameState* handle_event(SDL_Event& event);
	GameMenu();
private:
	BuilderButton builderBtn_;
	PlayerButton playerBtn_;
	SaveButton saveBtn_;
	ExitButton exitBtn_;

	ThreeColumnsBackground background_ = 
	ThreeColumnsBackground(Color::brown5, Color::brown1);
};

#endif
