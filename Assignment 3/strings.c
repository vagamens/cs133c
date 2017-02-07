#include <stdio.h>
#include "utils.c"

int main(void) {
	char myStr[100];
	int letters=0;

	fgets(myStr, 100, stdin);

	int strLen = lenStr(myStr);
	char newStr[strLen];
	for(int i=0;i<strLen;i++) {
		newStr[i] = myStr[i];
	}
	*myStr = *newStr;

	// print fowards
	for(int i=0; i<strLen; i++) {
		printf("%c\n", myStr[i]);
	}

	// print backwards
	for(int i=strLen-1; i>=0;i--) {
		if('a' <= myStr[i] <= 'z') {
			printf("%c\n", myStr[i]);
		} else if('A' <= myStr[i] <= 'Z') {
			printf("%c\n", myStr[i]);
		}
	}

	// count letters
	for(int i=0; i<strLen;i++) {
		if(myStr[i] != ' ' && myStr[i] != '\n' && myStr[i] != '\0') {
			letters++;
		}
	}

	return 0;
}

