#include "../Headers/Game.hpp"

//test now that the game has been initialized
int main() {
	Game* game = Game::get_instance();
	game->initialize();
	game->run();	
	return 0;
}
