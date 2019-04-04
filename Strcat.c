#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to implement strcat() function in C
char* my_strcat(char* destination, const char* source)
{
	// make ptr point to the end of destination string
	char* ptr = destination + strlen(destination);

	// Appends characters of source to the destination string
	while (*source != '\0')
		*ptr++ = *source++;

	// null terminate destination string
	*ptr = '\0';

	// destination is returned by standard strcat()
	return destination;
}

// Implement strcat function in C
int main()
{
	char* str = (char*)calloc(100, 1);

	my_strcat(str, "Techie ");
	my_strcat(str, "Delight ");
	my_strcat(str, "- ");
	my_strcat(str, "Coding ");
	my_strcat(str, "made ");
	my_strcat(str, "easy");

	puts(str);

	return 0;
}