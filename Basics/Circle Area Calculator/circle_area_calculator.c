#include <stdio.h>

int main()
{
	float radius, pi, areaCircle;

	printf("Enter radius of the circle in cm : ");
	scanf("%f", &radius);

	pi = 3.14;
	areaCircle = radius * radius * pi;

	printf("Area of Circle: %f cm^2", areaCircle);

	return (0);
}