#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for bool
#ifdef _WIN32
#include <windows.h> // For Sleep() on Windows
#else
#include <unistd.h>  // For sleep() on POSIX systems (Linux/macOS)
#endif
#include <time.h> // for time()

int generateRandomNumber(int max)
{
	return rand() % max + 1;
}

int main()
{
	// seed random number generator
	srand(time(NULL)); // returns the current time (in seconds since January 1, 1970, also known as the Unix epoch).

	// Setup variables
	int balance, bet, guess, dice;
	balance = 1000;
	bool isGameOver = false;

	// Loop
	while (!isGameOver)
	{
		// Ask questions
		printf("Balance: $%d\nPlace your bet: $", balance);
		scanf("%d", &bet);

		if (bet > balance) {
			printf("You don't have enough balance. Ukur baju di badan sendiri. Bet again.\n");
			continue;
		}

		printf("Guess a number between 1 to 6. If you want to quit, press 0 : ");
		scanf("%d", &guess);

		// Check if user wants to quit
		if (guess == 0)
		{
			printf("User quit the game.");
			return 0;
		}

		// Pause for 2 secs
		Sleep(2);

		// Generate number from 1 to 6
		dice = generateRandomNumber(6);
		printf("You guess %d. The dice roll is: %d\n", guess, dice);

		// Check guesses
		if (dice == guess)
		{
			printf("Congratulations! You win.\n\n");
			bet += bet *3;
			balance += bet;
		}
		else if (dice != guess)
		{
			printf("You lose...Balance deducted.\n\n");
			balance -= bet;
		}
		
		if (balance <= 0)
		{
			printf("You lost. No more balance. Game over...");
			isGameOver = true;
		}
	}

	return 0;
}