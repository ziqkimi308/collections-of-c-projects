#include <stdio.h>

int main() {
	int userAnswer;
	printf("Choose one: 1. apples, 2. pears, 3. bananas: \n");
	scanf("%d", &userAnswer);

	switch (userAnswer)
	{
		case (1):
		printf("The answer is: Apples\n");
		break;

		case (2):
		printf("The answer is: Pears\n");
		break;

		case (3):
		printf("The answer is: Bananas\n");
		break;

		default:
		printf("Not in the options.");
	}

	return 0;
}