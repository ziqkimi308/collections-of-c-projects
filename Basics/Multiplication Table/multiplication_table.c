#include <stdio.h>
#include <assert.h>

int main() {
    int number, i;

    // Get the number for the multiplication table
    printf("Enter a number for the multiplication table: ");
    scanf("%d", &number);

    // Assert that the number is positive and no greater than 12
	// If false, abort the programme
    assert(number > 0 && number <= 12);

    // Print the multiplication table
    printf("Multiplication table for %d:\n", number);
    for (i = 1; i <= 12; i++) {
        printf("%d x %d = %d\n", number, i, number * i);
    }

    return 0;
}
