#include <stdio.h>
#include "../Sources/utils.c"

struct Game {
	int board[9];
	int currentPlayer;
};

int initGame(struct Game *this) {
	this->currentPlayer = 1;
	for(int i=0;i<9;i++) {
		this->board[i] = 0;
	}
}

int printBoard(struct Game *this) {
	printf("\n ");
	for(int i=0;i<9;i++) {
		if( i>0 && i%3==0) {
			printf("\n ");
		}
		if(this->board[i] == 1) {
			printf("X");
		} else if(this->board[i] == 2) {
			printf("O");
		} else {
			printf("%d", i+1);
		}
		if(i%3<=1) {
			printf(" | ");
		}
		if(i%3==2 && i<8) {
			printf("\n---+---+---");
		}
	}
	printf("\n");
}

char getPlayerInput(struct Game *this) {
	int in;
	do {
	 	printf("\nPlayer %d: Where would you like to play? ", this->currentPlayer);
		scanf("%d", &in);
		clrBuf();
		if(in<1 || in>9) {
			printf("Invalid input. Please try again.\n");
		}
	} while (in<1 || in>9);
	return in;
}

int updateBoard(struct Game *this, char pos) {
	for(int i=0;i<9;i++) {
		if(i+1==pos) {
			if(this->board[i] == 0) {
				this->board[i] = this->currentPlayer;
			}
		}
	}
}

int changePlayer(struct Game *this) {
	if(this->currentPlayer == 1) {
		this->currentPlayer = 2;
	} else {
		this->currentPlayer = 1;
	}
}

int complete(struct Game *this) {
	// check vertical
	for(int i=0;i<3;i++) {
		if((this->board[i] == this->board[i+3]) && (this->board[i] == this->board[i+6])) {
			if(this->board[i] == 1) { return 1; }
			else if(this->board[i] == 2) { return 2; }
		}
	}
	//check horizontal
	for(int i=0;i<8;i+=3) {
		if(this->board[i] == this->board[i+1] && this->board[i] == this->board[i+2]) {
			if(this->board[i] == 1) { return 1; }
			else if(this->board[i] == 2) { return 2; }
		}
	}
	//check diagonals
	if(this->board[0] == this->board[4] && this->board[0] == this->board[8]) {
		if(this->board[0] == 1) { return 1; }
		else if(this->board[0] == 2) { return 2; }
	}
	if(this->board[2] == this->board[4] && this->board[2] == this->board[6]) {
		if(this->board[2] == 1) { return 1; }
		else if(this->board[2] == 2) { return 2; }	
	}
	return 0;
}

int runGame(struct Game *this) {
	printBoard(this);
	int playerIn = getPlayerInput(this);
	updateBoard(this, playerIn);
	changePlayer(this);
	int winner = complete(this);
	if(winner) {
		printBoard(this);
		printf("\nCongratulations Player %d! You Win!\n", winner);
		return 0;
	}
	return 1;
}

int main(void) {
	struct Game game;
	initGame(&game);
	while(runGame(&game)) {}
}