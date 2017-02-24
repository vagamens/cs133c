#include "game.c"

int main(void) {
	struct Game game;
	game.guesses[0] = 7;
	initGame(&game);
	
	while(runGame(&game)) {}

	return 0;
}

