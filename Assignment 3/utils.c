#include <stdio.h>

void clrBuf() {
	while(getchar() != '\n');
}

int lenStr(char *string) {
	int len=0;
	for(int i=0; string[i] != '\0' && string[i] != '\n';i++) {
		len++;
	}
	return len;
}

int strRealLen(char *string) {
	int actualLen = lenStr(string);
	char newString[actualLen];
	for(int i=0; string[i] != '\0'; i++) {
	 	newString[i] == string[i];
	}
	string = newString;
	return 0;
}