#include <stdio.h>

int main()
{
	int x = 0;

	while (x != 1) {
		printf("Press 1 if you want to quit: ");
		scanf("%d", &x);

		// Break condition
		if (x == 1)
			break;
	}

	printf("The programmed has stopped.");

	return (0);
}