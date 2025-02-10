// Import
#include <stdio.h>

int main() 
{
	// Create a variable reserves for storing user input name
	char userName[100]; // I give size 50

	printf("What is your name?\n");

	scanf("%s", &userName); // scanf only take the string input from terminal until encounter a space " ". So only first name will be recorded

	printf("Hello %s!\n", userName); // userName will replace %s

	return (0);
}