#include "game.c"

int main(void) {
	struct Game game;
	initGame(&game);
	while(runGame(&game)) {continue;}
	return 0;
}

