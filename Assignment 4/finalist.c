#include <stdio.h>
#include "../Sources/utils.c"

int main(void) {
	int done = 0;
	int final[4];
	zeroArray(final, 4);

	while(!done) {
		int r = randRange(1, 25);
		for(int i=0;i<4;i++) {
			if(r = final[i]) {
				break;
			} else if(final[i] == 0) {
				final[i] = r;
			}
		}

		if(final[3] !=0 ) {
			done = 1;
		}
	}

	printf("The finalists are %d, %d, %d and %d!\n", final[0], final[1], final[2], final[3]);

	return 0;
}