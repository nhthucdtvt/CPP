
#include<stdio.h>
#include<conio.h>
void PhuongAn()
{
	long dem=0;
	for(long a=1;a<=200;a++)
	{
		for(long b=1;b<=100;b++)
		{
			for(long c=1;c<=40;c++)
			{
				if(a*1000+b*2000+c*5000==200000)
				{
					dem++;
					printf("\nSo to 1000d:%d,so to 2000d:%d,so to 5000d:%d",a,b,c);
				}
			}
		}
	}
	printf("\nTong cong ta co:%d phuong an",dem);
}
void main()
{
	PhuongAn();
}