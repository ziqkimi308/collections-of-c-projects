#include <stdio.h>

float area_triangle(float base, float height)
{
	float area;

	area = (base * height) / 2;

	return (area);
}

int main()
{
	float base, height, area;

	printf("Unit is in cm\nBase : ");
	// fflush(stdout); // You don't need fflush() for this case
	scanf("%f", &base);

	printf("height : ");
	// fflush(stdout); // You don't need fflush() for this case
	scanf("%f", &height);

	area = area_triangle(base, height);
	printf("Area: %f cm^2", area);

	return (0);
}