#include <stdio.h>
#include <string.h>

struct person {
	char firstName[100];
	char lastName[100];
	int age;
};

int main() {
	struct person kimi;

	// strcpy auto includes null terminator in contrast to strncpy
	strcpy(kimi.firstName, "Haziq");
	strcpy(kimi.lastName, "Hakimi");
	kimi.age = 10;

	printf("%s %s of the age %d\n",
	kimi.firstName,
	kimi.lastName,
	kimi.age);

	return 0;

}