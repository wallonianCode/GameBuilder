#ifndef EXITERSTATE_H
#define EXITERSTATE_H
#include <memory>
#include "GameState.hpp"
#include "Background.hpp"
#include "Color.hpp"


class ExiterState : public GameState {
public:
	GameState* process_events(bool& running) override;
	void update() override;
	void draw() override;
	ExiterState();
private:
	std::shared_ptr<Background> background_;

};

#endif
