#include <stdio.h>

int main()
{
	int firstNumber, secondNumber, productNumber;

	printf("Enter the first number: ");
	scanf("%d", &firstNumber);

	printf("Enter the second number: ");
	scanf("%d", &secondNumber);

	productNumber = firstNumber + secondNumber;

	printf("%d + %d = %d", firstNumber, secondNumber, productNumber);

	return (0);
}