#include <stdio.h>
#include "../Sources/utils.c"

float hat(int weight, int height) {
	return ((float) weight/height)*2.9;
}

float jacket(int weight, int height, int age) {
	float j = ((float) height*weight)/288;
	age = age-30;
	while(age>10) {
		age-=10;
		j+=0.125;
	}
	return j;
}

float waist(int weight, int age) {
	float j = weight/5.7;
	age-=28;
	while(age>2) {
		age-=2;
		j+=0.1;
	}
	return j;
}

int contin() {
	while(1) {
		printf("Would you like to continue (Y/n)? ");
		char c;
		scanf("%c", &c);
		clrBuf();
		if(c == 'y' || c == 'Y') {
			return 1;
		} else if (c == 'n' || c == 'N') {
			return 0;
		} else {
			printf("Invalid input. Please try again.\n");
		}
	}
}

int main(void) {
	int cont = 1;

	while(cont) {
		int weight;
		int height;
		int age;

		printf("What is your weight(lbs)? ");
		scanf("%d", &weight);
		clrBuf();

		printf("What is your height(inches)? ");
		scanf("%d", &height);
		clrBuf();

		printf("What is your age? ");
		scanf("%d", &age);

		printf("Your has size is: %f inches.\n", hat(weight, height));
		printf("Your jacket size is: %f inches.\n", jacket(weight, height, age));
		printf("Your waist size is: %f inches.\n", waist(weight, age));

		if(!contin()) {
			cont = 0;
		}
	}

	return 0;
}