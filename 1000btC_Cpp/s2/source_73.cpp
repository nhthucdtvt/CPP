
#include<stdio.h>
#include<conio.h>
void main()
{
	int i;
	printf("\3 Cac so thoa dieu kien la:\3 ");
	for(i=-1000;i<=1000;i++) // vòng lặp này cho đại khái i chạy từ -1000 -> 1000 chứ không nhất thiết phải như vậy .
	{
		if(i<=-100&&i>=-999||i>=100&&i<=999)
		{
			int a=i%10;
			int b=i/10;
			int c=b%10;
			int d=b/10;
			int e=a+c+d;
			int f=(a+d)/2;
			if(e==18&&f==c)
			printf("%4d",i);
		}
	}
	getch();
}