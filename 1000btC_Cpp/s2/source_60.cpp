
#include<stdio.h>
#include<conio.h>
void main()
{
	int s=0,n=0;
	while(s<10000)
	{
		n++;
		s=s+n;
	}
	printf("\nSo N la:%d",n);
	getch();
}