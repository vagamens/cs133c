#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int generateRandomChar() {
	if(randNum()%20 == 0) {
		if(randNum()%2 == 1) {
			return randNum()%((90-65)+1)+65;
		} else {
			return randNum()%((122-97)+1)+97;
		}
	} else {
		return ' ';
	}
}

int main(void) {
	while(1) {
		int width = 80;
		for(int i=0; i<width;i++) {
			printf("%c", generateRandomChar());
		}
		printf("\n");
		delay(500);
		//sleep(1);
	}

	return 0;
}