#include <stdio.h>
#include "../Sources/utils.c"

int row(int n, int len) {
	for(int i=0;i<len-n;i++) {
		printf(" ");
	}
	for(int i=0;i<n;i++) {
		printf("* ");
	}
	printf("\n");
}

int rows(int n) {
	if(n>1) {
		rows(n-1);
	}
	row(n);
}

int main(void) {
	rows(5);
}