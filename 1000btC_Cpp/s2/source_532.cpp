
#include "stdio.h"
#include "conio.h"
void XuLyDuLieu(int &n)
{
	printf("\n>>>>>>>>>>>> Cac so duong co 3 chu so thoa dieu kien <<<<<<<<<<<<<<<<\n");
	printf("\n");
	for(n=100;n<=999;n++)
	{
		int temp=n;
		int tong=0;
		while(temp!=0)
		{
			tong+=temp%10;
			temp/=10;
		}
		if(tong%2==0)
		{
			printf("%8d",n);
		}		
	}
}
void main()
{
	int n;
	XuLyDuLieu(n);
	getch();
}
