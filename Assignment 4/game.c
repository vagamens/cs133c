#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
	char gameboard[14][52];
};

int initGame(struct Game *this) {
	this->guesses[0] = 6;
	this->guesses[1] = 0;
	for(int i=0;i+'A'<='Z';i++) {
		this->available[i] = i+'A';
	}
	this->firstRun = 1;
	this->width = 52;
	this->height = 14;
	for(int i=0;i<100;i++) {
		this->player2[i] = ' ';
	}
	this->player2[99] = '\0';
}

int updateMan(struct Game *this) {
	if(this->guesses[1]>=1) {
		this->gameboard[3][25] = '0';
	}
	if(this->guesses[1]>=2) {
		this->gameboard[4][25] = '|';
		this->gameboard[5][25] = '|';
	}
	if(this->guesses[1]>=3) {
		this->gameboard[4][24] = '/';
	}
	if(this->guesses[1]>=4) {
		this->gameboard[4][26] = '\\';
	}
	if(this->guesses[1]>=5) {
		this->gameboard[6][24] = '/';
	}
	if(this->guesses[1]>=6) {
		this->gameboard[6][26] = '\\';
	}
}

int updateBoxes(struct Game *this) {
	char avail[17] = "AVAILABLE LETTERS";
	char incor[17] = "INCORRECT LETTERS";
	char gues[17] = " CORRECT LETTERS ";

	// blocking
	for(int i=0;i<12;i++) {
		if(i == 0 || i == 5 || i == 8 || i == 11) {
			this->gameboard[i][31] = '+';
			this->gameboard[i][51] = '+';
			for(int j=32;j<51;j++) {
				this->gameboard[i][j] = '-';
			}
		} else {
			this->gameboard[i][31] = '|';
			this->gameboard[i][51] = '|';
		}
	}

	//titles
	for(int i=0;avail[i] != '\0';i++) {
		this->gameboard[1][i+33] = avail[i];
	}
	for(int i=0;incor[i] != '\0';i++) {
		this->gameboard[6][i+33] = incor[i];
	}
	for(int i=0;gues[i] != '\0';i++) {
		this->gameboard[9][i+33] = gues[i];
	}

	//available letters
	int row = 0;
	int col = 0;
	for(int i=0;i<26;i++) {
		if('A' <= this->available[i] <= 'Z') {
			this->gameboard[2+row][33+col] = this->available[i];
			col+=2;
		}
		if(col >= 18) {
			col = 0;
			row++;
		}
	}

	//incorrect letters
	// col=0;
	// for(int i=0;i<26;i++) {
	// 	if('A' <= this->incorrect[i] <= 'Z') {
	// 		this->gameboard[7][33+col] = this->incorrect[i];
	// 		col+=2;
	// 	}
	// }
}

int updateP2(struct Game *this) {
	int col = 0;
	for(int i=0;this->player2[i]!='\0';i++) {
		if('A' <= this->player2[i] <= 'Z') {
			this->gameboard[13][col] = this->player2[i];
		} else {
			this->gameboard[13][col] = '_';
		}
		col+=2;
	}
}

int fixIssues(struct Game *this) {
	for(int i=0;i<this->height;i++) {
		for(int j=0;j<this->width;j++) {
			if(0 <= i && i < 11) {
				if(0 <= j && j < 11) {
					this->gameboard[i][j] = ' ';
				}
			}
		}
	}
	//correct failed blocking
	this->gameboard[1][50] = ' ';
	this->gameboard[1][51] = '|';
	this->gameboard[6][50] = ' ';
	this->gameboard[6][51] = '|';
	this->gameboard[9][50] = ' ';
	this->gameboard[9][51] = '|';
}

int printInterface(struct Game *this) {
	updateMan(this);
	updateBoxes(this);
	updateP2(this);
	fixIssues(this);
	for(int i=0;i<this->height;i++) {
		for(int j=0;j<this->width;j++) {
			printf("%c", this->gameboard[i][j]);
		}
		printf("\n");
	}
}

int setupHangmanPicture(struct Game *this) {
	this->gameboard[0][11] = '+';
	this->gameboard[0][25] = '+';
	this->gameboard[11][11] = '+';
	this->gameboard[1][13] = '/';
	this->gameboard[2][12] = '/';
	this->gameboard[1][24] = '\\';
	this->gameboard[1][25] = '|';
	this->gameboard[2][25] = '|';
	for(int i=12;i<25;i++) {
		this->gameboard[0][i] = '-';
	}
	for(int i=1;i<11;i++) {
		this->gameboard[i][11] = '|';
	}
	for(int i=0;i<26;i++) {
		if(i != 11) {
			this->gameboard[11][i] = '_';
		}
	}
}

int setupGameboard(struct Game *this) {
	//reset gameboard
	for(int i=0;i<this->height;i++) {
		for(int j=0;j<this->width;j++) {
			this->gameboard[i][j] = ' ';
		}
	}
	setupHangmanPicture(this);
	updateMan(this);
	updateBoxes(this);
	updateP2(this);
	fixIssues(this);
}

int fRun(struct Game *this) {
	setupGameboard(this);
	printf("Please enter the secret word : ");
	fgets(this->player1, 100, stdin);
	for(int i=0;this->player1[i] != '\0';i++) {
		this->player1[i] = toupper(this->player1[i]);
	}
	this->firstRun = 0;
	printf("%s\n", this->player1);
	this->player2[strlen(this->player1)+1] = '\0';
	for(int i=0;i<50;i++) {
		printf("\n");
	}
}

int addToIncorrect(struct Game *this, char letter) {
	for(int i=0;i<26;i++) {
		if('A' <= this->incorrect[i] <= 'Z') {
			if(this->incorrect[i] == letter) {
				break;
			}
			continue;
		} else {
			this->incorrect[i] = letter;
		}
	}
}

int updateAvailable(struct Game *this, char letter) {
	for(int i=0;i<26;i++) {
		if (this->available[i] == letter) {
			this->available[i] = ' ';
			break;
		}
	}
}

int matches(struct Game *this, char letter) {
	for(int i=0;this->player1[i]!='\0';i++) {
		if(letter == this->player1[i]) {
			return i;
		}
	}
	return -1;
}

char getP2Input() {
	char p2in = 'a';
	printf("\nPlesae input a letter: ");
	scanf("%c", &p2in);
	clrBuf();
	return toupper(p2in);
}

int complete(struct Game *this) {
	/*
		THIS FUNCTION SHOULD BE WORKING!!!!!!
		FOR ODD REASONS, THE FITNESS SECTION
		CURRENTLY CAUSES A SEGFAULT. WILL
		DEBUG TOMORROW!!!!!!!!!!!!!!!!!!!!!!!
	*/
	//check loss state
	if(this->guesses[1] == this->guesses[0]) {
		return 1;
	}
	int correctness = 0;
	//fitness function
	// for(int i=0;strlen(this->player1);i++) {
	// 	if(this->player1[i] != this->player2[i]) {
	// 		correctness++;
	// 	}
	// }
	if(correctness < strlen(this->player1)) {
		//continue state
		return 0;
	} else if(correctness >= strlen(this->player1)) {
		//win state
		return 2;
	}
	return 0;
}

int runGame(struct Game *this) {
	if(this->firstRun) {
		fRun(this);
	}
	printInterface(this);
	char p2in = getP2Input();
	int match = matches(this, p2in);
	if(match != -1) {
		this->player2[match] = this->player1[match];
	} else {
		addToIncorrect(this, p2in);
		//updateAvailable(this, p2in);
		this->guesses[1]+=1;
	}
	int comp = complete(this);
	if(comp == 2) {
		printf("\n\nPLAYER 2 WINS!\nTHE WORD WAS: %s", this->player1);
		return 0;
	} else if(comp == 1) {
		printInterface(this);
		printf("\n\nPLAYER 1 WINS!!!\nTHE WORD WAS: %s\n", this->player1);
		return 0;
	} else {
		return 1;
	}
	/*
		CURRENTLY ENDS WITH A SEGFAULT!!!!!!!!
		WILL DEBUG LATER!!!!!!!!!!!!!!!!!!!!!!
	*/
}