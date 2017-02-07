#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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

int randNum() {
	int num = 0;
	time_t t;
	srand((unsigned) time(NULL));
	num = rand();
	return num;
}

int randModNum(int in) {
	int num = randNum();
	num = num%in;
	num = ++num;
	return num;
}

int lesser(int a, int b) {
	if(a<b) {
		return a;
	}
	return b;
}

int greater(int a, int b) {
	if(a>b) {
		return a;
	}
	return b;
}

int randRange(int a, int b) {
	return randModNum((b-a)+1)+a;
}