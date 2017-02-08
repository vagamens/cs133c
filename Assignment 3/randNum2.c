#include <stdio.h>
#include "utils.c"

int main(void) {
	int in1 = 0;
	int in2 = 0;
	int randNum = 0;

	printf("What is your minimum value? ");
	scanf("%d", &in1);
	clrBuf();

	printf("What is your maximum value? ");
	scanf("%d", &in2);

	randNum = randRange(in1, in2);

	printf("You havw %d baloons.\n", randNum);

	return 0;
}