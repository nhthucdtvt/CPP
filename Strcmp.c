#include<stdio.h>

// Function to implement strcmp function
int strcmp(const char *X, const char *Y)
{
	while(*X)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y)
			break;
		
		// move to next pair of characters
		X++;
		Y++;
	}

	// return the ASCII of the first difference character after converting char* to unsigned char*
	// ex: abc vs bcd -> a difference b of str2, so return a-b = -1
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}

// Implement strcmp function in C
int main()
{
	char *X = "abcd";
	char *Y = "cdef";

	int ret = strcmp(X, Y);
	printf("ret = %d\n", ret);
	
	if (ret > 0)
		printf("%s", "X is greater than Y\n");
	else if (ret < 0)
		printf("%s", "X is less than Y\n");
	else
		printf("%s", "X is equal to Y\n");

	return 0;
}