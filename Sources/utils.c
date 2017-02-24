#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int randFirstRun = 1;

void clrBuf() {
	while(getchar() != '\n');
}

int zeroArray(int *array, int len) {
	for(int i=0;i<len;i++) {
		array[i] = 0;
	}
	return 0;
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
	if(randFirstRun) {
		time_t t;
		srand((unsigned) time(NULL));
		randFirstRun = 0;
	}
	return rand();
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

int compareStrings(char *string1, char *string2) {
	for(int i=0;i<lesser(lenStr(string1), lenStr(string2));i++) {
		if(string1[i] != string2[i]) {
			return 0;
		}
	}
	return 1;
}