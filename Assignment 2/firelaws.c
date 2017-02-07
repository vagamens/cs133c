#include <stdio.h>

int clrBuf() {
	while(getchar() != '\n');
}

int main() {
	int attendees;
	int capacity;
	int difference;
	int maxTries = 5;
	int triesRemaining = maxTries;

	printf("Enter the number of meeting participants: ");
	scanf(" %d",&attendees);clrBuf()

	while(attendees <= 0 && triesRemaining > 0) {
		printf("Invalid attendee count, please try again.\n");
		scanf(" %d",&attendees);clrBuf();
		triesRemaining--;
	}

	triesRemaining = maxTries;

	printf("Enter the meeting room capacity: ");
	scanf(" %d",&capacity);clrBuf();

	while(capacity <= 0) {
		printf("Inalid capacity count, please try again.\n");
		scanf(" %d",&capacity);clrBuf();
	}

	if(attendees > capacity) {
		difference = attendees - capacity;
		printf("\nThe number of attendees is too large to meet fire codes.\n");
		if(difference == 1) {
			printf("Please exclude %d attendee.\n", difference);
		} else {
			printf("Please exclude %d attendees.\n", difference);
		}
	} else {
		printf("\nYour meeting is good to go. Have a good time.\n");
	}

	return 0;
}