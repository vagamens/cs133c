#include <stdio.h>

int equals(char *str1, int len1, char *str2, int len2) {
	if(len1 != len2) {
		return 0;
	}
	for(int i=0;i<len1;i++) {
		if(str1[i] != str2[i]) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	return 0;
}