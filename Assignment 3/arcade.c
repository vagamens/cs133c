#include <stdio.h>
#include "utils.c"

int main(void) {
	int coupons = 0;
	int candyBars = 0;
	int gumballs = 0;
	int coupForBar = 10;
	int coupForGum = 3;

	printf("How many coupons do you have? ");
	scanf("%d", &coupons);
	clrBuf();

	if(coupons < 3 ) {printf("You do not have enough coupons\n");return 0;}
	candyBars = coupons/coupForBar;
	coupons = coupons - candyBars*coupForBar;
	gumballs = coupons/coupForGum;
	coupons = coupons - gumballs*coupForGum;

	if(candyBars == 1) {printf("You can purcahse 1 candy bar.\n");}
	else {printf("You can purchase %d candy bars.\n", candyBars);}
	if(gumballs == 1) {printf("You can purchase 1 gumball.\n");}
	else {printf("You can purchase %d gumballs.\n", gumballs);}
	if(coupons == 1) {printf("You will have %d coupon left.\n", coupons);}
	else {printf("You will have %d coupons left.\n", coupons);}
}