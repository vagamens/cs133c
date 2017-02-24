#include <stdio.h>
#include <ctype.h>
#include "../Sources/utils.c"

int firstRun = 1;

int game(char player1[], char player2[], char missing[]) {
	char p2in;
	for(int i=0;i<lenStr(player2);i++) {
		if(('a' <= player2[i] && player2[i] <= 'z') || ('A' <= player2[i] && player2[i] <= 'Z')) {
			printf("%c", player2[i]);
		} else {
			printf("_");
		}
		printf(" ");
	}
	printf("\n");
	printf("%s\n", player2);
	printf("Please input a letter: ");
	scanf("%c", &p2in);
	clrBuf();
	p2in = tolower(p2in);
	int match = 0;
	for(int i=0;i<lenStr(player1);i++) {
		if(p2in == tolower(player1[i])) {
			player2[i] = player1[i];
			match = 1;
		}
	}
	if(!match) {
		for(int i=0;i<26;i++) {
			if('A' < missing[i] < 'Z') {
				continue;
			} else {
				missing[i] = toupper(p2in);
			}
		}
	}
}

int main(void) {
	char player1[100];
	char missing[26];
	printf("Please enter the secret word: ");
	fgets(player1, 100, stdin);

	// remove extra space for the extra word
	int strLen = lenStr(player1);
	char newplayer1[strLen];
	for(int i=0;i<strLen;i++) {
		newplayer1[i] = player1[i];
	}
	*player1 = *newplayer1;

	// create player2 guess
	char player2[strLen];
	while(!compareStrings(player1, player2)) {
		game(player1, player2, missing);
	}

	return 0;
}