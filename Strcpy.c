#include <stdio.h>

// Function to implement strcpy() function
char* strcpy(char* destination, const char* source)
{
	// return if no memory is allocated to the destination
	if (destination == NULL)
		return NULL;

	// take a pointer pointing to the beginning of destination string
	char *ptr = destination;
	
	// copy the C-string pointed by source into the array
	// pointed by destination
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	// include the terminating null character
	*destination = '\0';

	// destination is returned by standard strcpy()
	return ptr;
}

// Implement strcpy function in C
int main(void)
{
	char source[] = "Techie Delight";
	char destination[25];

	printf("%s\n", strcpy(destination, source));
	
	return 0;
}