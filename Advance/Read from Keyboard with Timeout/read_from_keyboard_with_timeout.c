#include <stdio.h>
#include <sys/time.h> // for struct timeval
#include <unistd.h> // for read()
#include <string.h> // for memset()
#include <sys/select.h> // for fd_set
#include <stdlib.h>

// Function
char *timeReadLine(int timeout)
{
	// Setup variables
	// Var to store user input. If you use static memory allocation, you need to use static variable 
	char *userInput = malloc(512);
	// struct to track file descriptors
	fd_set fileDescriptorSets;
	// struct to store timeout duration
	struct timeval timeValue;
	// var for return value
	int selectResult, bytesRead;

	// Setup fileDescriptorSets;
	// Clear all file descriptors from fileDescriptorSets
	FD_ZERO(&fileDescriptorSets);
	// Add standard input (keyboard) to the set
	FD_SET(0, &fileDescriptorSets);

	// Setup timeValue
	// Set the second to timeout
	timeValue.tv_sec = timeout; // sec is seconds while usec is microseconds
	// No use of microseconds
	timeValue.tv_usec = 0;

	// Setup select(highets fd + 1, read, write, except, timeout)
	selectResult = select(1, &fileDescriptorSets, 0, 0, &timeValue); // Because we waiting input from keyboard, so 0. Then 0 + 1 = 1.

	// if select returns 0 or lower, it is false. Previously, we set keyboard to fileDescriptorSets. Now we check again if they are ready (ready = 1).
	if (selectResult && FD_ISSET(0, &fileDescriptorSets))
	{
		// memset to makes sure userInput empty (filled with 0)
		memset(userInput, 0, 512);

		// read will read from keyboard (0) and store data into userInput by maximum data bytes of 511
		bytesRead = read(0, userInput, 511);

		// if read returns negative which means error, or 0 which mean empty input
		if (bytesRead < 0)
		{
			perror("Error reading input");
			return NULL;
		}
		else if (bytesRead == 0)
			return NULL;
		else
		{
			// Set null terminator at the end
			bytesRead--;
			userInput[bytesRead] = '\0';
			return userInput;
		}	
	}
	else
		return NULL;
}

int main()
{
	char *name;

	printf("What is your name? Think fast!\n");
	name = timeReadLine(5);
	if (name)
		printf("Hello %s\n", name);
	else
		printf("Too slow!\n");
	
	free(name);

	return 0;
}