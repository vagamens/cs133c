#include <stdio.h>

int main(int argc, char* argv) {
	short s = 32767;
	int i = 7483647;
	long l = 2147483647;
	float f = 3.456237;
	double d = 1.753651984571356;
	long double ld = 1.126495873156497821;
	char c = 'h';
	char cs[] = "CS133C";

	printf("short =       %d\n", s);
	printf("int =         %d\n", i);
	printf("long =        %d\n", l);
	printf("float =       %g\n", f);
	printf("double =      %g\n", d);
	printf("long double = %g\n", ld);
	printf("char =        %c\n", c);
	printf("string =      %s\n", cs);
	return 0;
}