#include <stdio.h>
#include "../Sources/utils.c"

/*
	A savings account typically accures savings using compound interest. if you
	deposit $1000 with a 10% interest rate per year, after one year you will
	have $1100. If you leave this money in the account for another year at 10%
	interest, you will have $1210. After three years you will have $1331, and
	so on.

	Write a program that inputs the initial amount, an interest rate per year,
	and the number of years the money will accrue compound interest. Write a
	recursive function that calculates the amount of money that will be in the
	savings account using the input information.

	To verify your function, the amount should be equal to P(1+i)^n, where P is
	the amount initially saved, i is the interest rate per year, and n is the
	number of years.
*/

float interest(float savings, float accrue, int years) {
	if(years <= 0) {
		return savings;
	}
	savings += savings*accrue;
	years--;
	return interest(savings, accrue, years);
}

int main(void) {
	for(float i=1000.0;i<50000;i+=1000) {
		for(float j=0.01;j<1;j+=0.01) {
			for(int k=0;k<100;k++) {
				printf("Saved:$%f Interest:%f Years:%d Total:$%f\n", i, j, k, interest(i, j, k));
			}
		}
	}
}