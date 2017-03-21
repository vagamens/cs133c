#include <stdio.h>
#include "../Sources/utils.c"

int main(int argc, char* argv[]) {
	// for(int i=0;i<argc;i++) {
	// 	printf("%s\n", argv[i]);
	// }
	char fileName[1000];
	printf("What file would you like to open? ");
	fgets(fileName, 1000, stdin);
	fileName = realLen(1000, fileName);
}