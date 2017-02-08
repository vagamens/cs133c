#include <stdio.h>
#include "utils.c"

int main(void) {
	int coupons = 0;
	int candyBars = 0;
	int gumballs = 0;
	int coupForBar = 10;
	int coupForGum = 3;

	coupons = 0;

	printf("%d\n");

	printf("How many coupons do you have?");
	scanf("%d", &coupons);
	clrBuf();

	printf("%d\n", coupons);

	while(coupons < 3) {
		printf("Not enough coupons, please get more before you attempt to use this machine\n\n");

		printf("How many coupons do you have?");
		scanf("%d", &coupons);
		clrBuf();		
	}

	if(coupons == 0) {printf("You do not have enough coupons\n");return 0;}
	while(coupons > 0) {
		if(coupons >= coupForBar) {
			candyBars++;
			coupons-=coupForBar;
		} else if(coupons >= coupForGum) {
			gumballs++;
			coupons-=coupForGum;
		}
	}

	if(candyBars == 1) {printf("You can purcahse 1 candy bar.\n");}
	else {printf("You can purchase %d candy bars.\n", candyBars);}
	if(gumballs == 1) {printf("You can purchase 1 gumball.\n");}
	else {printf("You can purchase %d gumballs.\n", gumballs);}
	if(coupons == 1) {printf("You will have %d coupon left.\n", coupons);}
	else {printf("You will have %d coupons left.\n", coupons);}
}