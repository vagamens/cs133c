#include <stdio.h>
#include <stdlib.h>

int main() {
	int attendees = 0;
	int capacity = 0;
	int difference = 0;

	printf("Enter the number of meeting participants: ");
	scanf(" %d",&attendees);getchar();

	printf("Enter the meeting room capacity: ");
	scanf(" %d",&capacity);getchar();

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