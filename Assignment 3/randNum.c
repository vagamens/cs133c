#include "utils.c"
#include <stdio.h>

int main(void) {
	int numNums = 10;

	for(int i=0;i<numNums;i++) {
		int num = randNum();
		printf("%d\n", num);
	}


	return 0;
}