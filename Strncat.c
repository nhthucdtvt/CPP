#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to implement strncat() function in C
char* my_strncat(char* destination, const char* source, size_t num)
{
	// make ptr point to the end of destination string
	char* ptr = destination + strlen(destination);

	// Appends characters of source to the destination string
	while (*source != '\0' && num--)
		*ptr++ = *source++;

	// null terminate destination string
	*ptr = '\0';

	// destination string is returned by standard strncat()
	return destination;
}

// Implement strncat function in C
int main()
{
	char dest[30];
	strcpy(dest, "Techie ");

	char src[] = "Delight - Implement strncat";

	my_strncat(dest, src, 7);

	puts(dest);

	return 0;
}