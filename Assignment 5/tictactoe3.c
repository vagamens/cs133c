#include <stdio.h>
#include "../Sources/utils.c"

struct Game {
	int board[3][3];
	int currentPlayer;
};

int initGame(struct Game *this) {
	this->currentPlayer = 1;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			this->board[i][j] = 0;
		}
	}
}

int printBoard(struct Game *this) {
	printf("\n");
	int pos=1;
	for(int i=0;i<3;i++) {
		printf(" ");
		for(int j=0;j<3;j++) {
			if(this->board[i][j] == 1) {
				printf("X");
			} else if(this->board[i][j] == 2) {
				printf("O");
			} else {
				printf("%d", pos);
			}
			pos++;
			if(j<2) {
				printf(" | ");
			}
		}
		printf("\n");
		if(i<2) {
			printf("---+---+---\n");
		}
	}
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
	int p=1;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if(p==pos) {
				if(this->board[i][j] == 0) {
					this->board[i][j] = this->currentPlayer;
				}
			}
			p++;
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
	for(int i=0;i<3;i++) {
		if(this->board[i][0] > 0) {
			// check horizontal
			if((this->board[i][0] == this->board[i][1]) && (this->board[i][0] == this->board[i][2])) {
				if(this->board[i][0] == 1) { return 1; }
				else if(this->board[i][0] == 2) { return 2; }
			}
			//check vertical
			if(this->board[0][i] == this->board[1][i] && this->board[0][i] == this->board[2][i]) {
				if(this->board[0][i] == 1) { return 1; }
				else if(this->board[0][i] == 2) { return 2; }
			}
		}
	}
	//check diagonals
	if(this->board[0][0] == this->board[1][1] && this->board[0][0] == this->board[2][2]) {
		if(this->board[0][0] == 1) { return 1; }
		else if(this->board[0][0] == 2) { return 2; }
	}
	if(this->board[0][2] == this->board[1][1] && this->board[0][2] == this->board[2][0]) {
		if(this->board[0][2] == 1) { return 1; }
		else if(this->board[0][2] == 2) { return 2; }	
	}
	return 0;
}

int runGame(struct Game *this) {
	printBoard(this);
	int playerIn = getPlayerInput(this);
	int updated;
	updated = updateBoard(this, playerIn);
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