#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *firstName;

	// Allocate memory
	firstName = malloc(32);

	printf("Enter your first name: ");
	scanf("%s", firstName);
	printf("Hello %s", firstName);

	// Deallocate memory
	free(firstName);

	return 0;
}