#include <stdio.h>

void printChar(char c, char *text)
{
	// print string, c in 
	printf("%s = '%c' (0x%x)\n", text, c, c);
	return;
}

int main()
{
	char clearText = 'A';
	char key = 'X';
	char cipherText, newClearText;

	// Basically the text "clearText" is just for print for clarity. Not important.
	printChar(clearText, "clearText");
	printChar(key, "key");

	// The ^ is called bitwise XOR (exclusive or)
	cipherText = clearText ^ key;
	printChar(cipherText, "cipherText");

	newClearText = cipherText ^ key;
	printChar(newClearText, "newClearText");

	return 0;
}