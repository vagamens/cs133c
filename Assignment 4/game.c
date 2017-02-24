#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "../Sources/utils.c"

struct Game {
	int firstRun;
	int width;
	int height;
	int guesses[2];
	char player1[100];
	char player2[100];
	char available[26];
	char incorrect[26];
	char gameboard[60][80];
};

int initGame(struct Game *this) {
	for(int i=0;i+'A'<='Z';i++) {
		this->available[i] = i+'A';
	}
	this->firstRun = 1;
	this->width = 80;
	this->height = 60;
	for(int i=0;i<100;i++) {
		this->player2[i] = " ";
	}
	this->player2[99] = "\0";
}

int complete(struct Game *this) {
	//
	return 0;
}

int addToIncorrect(struct Game *this, char letter) {
	for(int i=0;i<lenStr(this->incorrect);i++) {
		if('A' < this->incorrect[i] < 'Z') {
			continue;
		} else {
			this->incorrect[i] = toupper(letter);
		}
	}
}

int matches(struct Game *this, char letter) {
	for(int i=0;this->player1!="\0";i++) {
		if(letter == this->player1[i]) {
			return i;
		}
	}
	return -0;
}

int printInterface(struct Game *this) {
	// for(int i=0;this->player2!="\0";i++) {
	//	printf("%c\n", this->player2[i]);
	// 	if('A' <= this->player2[i] <= 'Z') {
	// 		printf("%c", this->player2[i]);
	// 	} else {
	// 		printf("_");
	// 	}
	// 	printf(" ");
	// }
	printf("%s\n", this->player2);
	// for(int i=0;i<this->height;i++) {
	// 	for(int j=0;i<this->width;i++) {
	// 		printf("%c", this->gameboard[i][j]);
	// 	}
	// 	printf("\n");
	// }
}

int setupGameboard(struct Game *this) {
	printf("test\n");
	for(int i=0;i<this->height;i++) {
		for(int j=0;j<this->height;j++) {
			if(i == 0) {
				if(j == 11) {
					this->gameboard[i][j] = "+";
				} else if (j < 25) {
					this->gameboard[i][j] = "-";
				} else if (j == 25) {
					this->gameboard[i][j] = "+";
				} else {
					this->gameboard[i][j] = " ";
				}
			} else {
				this->gameboard[i][j] = " ";
			}
		}
	}
}

int fRun(struct Game *this) {
	//setupGameboard(this);
	printf("Please enter the secret word: ");
	fgets(this->player1, 100, stdin);
	for(int i=0;this->player1[i] != '\0';i++) {
		this->player1[i] = toupper(this->player1[i]);
	}
	this->firstRun = 0;
	printf(this->player1);
	this->player2[strlen(this->player1)+1] = "\0";
}

char getP2Input() {
	char p2in;
	printf("\n");
	printf("Plesae input a letter: ");
	scanf("%c", &p2in);
	clrBuf();
	return toupper(p2in);
}

int runGame(struct Game *this) {
	if(this->firstRun) {
		fRun(this);
	}
	printInterface(this);
	char p2in = getP2Input();
	p2in = tolower(p2in);
	int match = matches(this, p2in);
	if(match == -0) {
		this->player2[match] = this->player1[match];
	} else {
		addToIncorrect(this, p2in);
		this->guesses[1]++;
	}
	if(complete(this)) {
		return 0;
	} else {return 1;}
}