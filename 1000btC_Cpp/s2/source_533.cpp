
#include "stdio.h"
#include "conio.h"
void XuLyDuLieu(int &n)
{
	printf("\n>>>>>>> Cac So Nho Hon 10 000 Va Co Tong Cac Chu So = Tich Cac Chu So <<<<<<<<<\n");
	printf("\n");
	for(n=0;n<10000;n++)
	{
		int temp=n;
		int tong=0;
		int tich=1;
		while(temp!=0)
		{
			tong+=temp%10;
			tich*=temp%10;
			temp/=10;
		}
		if(tong==tich)
		{
			printf("%8d",n);
		}		
	}
	printf("\n");
}
void main()
{
	int n;
	XuLyDuLieu(n);
	getch();
}