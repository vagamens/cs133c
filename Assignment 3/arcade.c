#include <stdio.h>
#include "utils.c"

int main(void) {
	int coupons = 0;
	int candyBars = 0;
	int gumballs = 0;
	int coupForBar = 10;
	int coupForGum = 3;

	printf("How many coupons do you have?");
	scanf("%d", &coupons);
	clrBuf();

	if(coupons == 0) {printf("You do not have enough coupons\n");return 0;}
	candyBars = coupons/10;
	coupons = coupons - candyBars*10;
	gumballs = coupons/3;
	coupons = coupons - gumballs*3;

	printf("You can purchase %d candy bars.\n", candyBars);
	printf("You can purchase %d gumballs.\n", gumballs);
	if(coupons == 1) {printf("You will have %d coupon left.", coupons);}
	else {printf("You will have %d coupons left.", coupons);}
}