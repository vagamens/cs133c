#include <stdio.h>
#include "../Sources/utils.c"



int main(void) {
	int students;
	int hist[11];

	for(int i=0;i<11;i++) {
		hist[i] = 0;
	}

	printf("For how many students would you like to enter grades? ");
	scanf("%d", &students);
	clrBuf();

	for(int i=0;i<students;i++) {
		int input;
		
		in: printf("Please enter a new grade(0-10): ");
		scanf("%d", &input);
		if(input<0 || input >10) {
			printf("Invalid input\n");
			goto in;
		}
		hist[input]+=1;
	}
	printf("\n\n");

	for(int i=0;i<11;i++) {
		printf("%d grade(s) of %d\n", hist[i], i);
	}
}