#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int random_function(int max)
{
	int x = rand() % max + 1;
	
	return x;
}

int main()
{
	int random; 

	srand(getpid());
	random = random_function(10);
	printf("%d\n", random);

	random = random_function(10);
	printf("%d\n", random);

	return 0;
}