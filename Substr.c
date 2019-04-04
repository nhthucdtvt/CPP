#include<stdio.h>

// Function to implement substring function in C
char* substring(char *destination, const char *source, int beg, int n)
{
	// extracts n characters from source string starting from beg index
	// and copy them into the destination string
	while (n > 0)
	{
		*destination = *(source + beg);

		destination++;
		source++;
		n--;
	}

	// null terminate destination string
	*destination = '\0';

	// return the destination string
	return destination;
}

// Implement substring function in C
int main()
{
	char source[] = "Techie Delight - Coding made easy";
	char destination[25];

	int start = 7;
	int len = 7;

	substring(destination, source, start, len);

	printf("%s\n", destination);

	return 0;
}