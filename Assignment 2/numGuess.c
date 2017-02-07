#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int genNum(int in) {
	int num = 0;
	time_t t;
	srand((unsigned) time(&t));
	num = rand()%in;
	num = ++num;
	return num;
}

int main() {
	int input = 0;
	int guesses = 3;
	int guessed = 0;
	int low = 1;
	int high = 10;
	int num = genNum(10);

	while (guessed < guesses) {
		if(input >= low && input <= high) {
			guessed++;
		}
		printf("Enter a number between %d and %d: ", low, high);
		scanf(" %d",&input);getchar();
		if (input == num) {
			printf("You guessed correctly!\n");
			break;
		} else if (input > num) {
			high = input;
			printf("You weren\'t quite right :(\n");
			printf("Too large!\n\n");
		} else if (input < num) {
			low = input;
			printf("You weren\'t quite right :(\n");
			printf("Too small!\n\n");
		}
	}

	if(guessed >= guesses) {
		printf("You ran out of guesses :(\n");
	}

	return 0;
}