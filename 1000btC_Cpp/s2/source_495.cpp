
#include<stdio.h>
#include<conio.h>
void BanCuuChuong()
{
	int s;
	printf("\n>>>>>>>>>>>Ban Cuu Chuong:<<<<<<<<<<<<<<<<\n");
	printf("\n");
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			s=i*j;
			printf("%d x %d = %d ",i,j,s);
			printf("\n");
		}
		printf("\n");
	}
}
void main()
{
	BanCuuChuong();
	getch();
}