#include <stdio.h>
#include "../Sources/utils.c"

int fibbo(int n) {
	if(n <= 1) {
		return 1;
	}
	return fibbo(n-1)+fibbo(n-2);
}

int main(void) {
	for(int i=0;i<50;i++) {
		printf("F(%d): %d\n", i, fibbo(i));
	}
}