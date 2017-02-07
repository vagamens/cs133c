#include <stdio.h>
#include "utils.c"

int main(void) {
	char input1[100];
	char input2[100];

	printf("What is the first string you would like to compare? ");
	fgets(input1, 100, stdin);

	printf("what is the second string you would like to compare? ");
	fgets(input2, 100, stdin);

	// remove extra space for input1
	int strLen = lenStr(input1);
	char newIn1[strLen];
	for(int i=0;i<strLen;i++) {
		newIn1[i] = input1[i];
	}
	*input1 = *newIn1;

	// remove extra space for input2
	strLen = lenStr(input2);
	char newIn2[strLen];
	for(int i=0;i<strLen;i++) {
		newIn2[i] = input2[i];
	}
	*input2 = *newIn2;

	for(int i=0;i<lesser(lenStr(input1), lenStr(input2));i++) {
		printf("greater: \'%c\'; lesser: \'%c\'\n", greater(input1[i], input2[i]), lesser(input1[i], input2[i]));
	}

	return 0;
}