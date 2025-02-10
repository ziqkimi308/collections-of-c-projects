#include <stdio.h>
#include <string.h> // For strcspn()

int main() 
{
    // Create a variable for storing user input name
    char userName[100]; // Increased size to 100 for longer input

    printf("What is your name?\n");

    fgets(userName, sizeof(userName), stdin); // Read a full line, including spaces

    // Remove the newline character at the end of the string, if present
	int lastIndex = strcspn(userName, "\n");
    userName[lastIndex] = '\0'; 

    printf("Hello %s!\n", userName); // userName will replace %s

    return (0);
}
