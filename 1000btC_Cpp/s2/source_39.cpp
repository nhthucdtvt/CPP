
#include<stdio.h>
#include<conio.h>
void chusodautien(int &n)
{
	do{
		printf("Nhap vao so nguyen duong n(n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
	printf("\nChu so dau tien cua %d la:",n);
	if(n>=0&&n<=9)
		printf("%4d",n);
	if(n>=10&&n<=99)
	{
		int a=n/10;
		printf("%4d",a);
	}
	if(n>=100&&n<=999)
	{
		int b=n/100;
		printf("%4d",b);
	}
	if(n>=1000&&n<=9999)
	{
		int c=n/1000;
		printf("%4d",c);
	}
	if(n>=10000&&n<=99999)
	{
		int d=n/10000;
		printf("%4d",d);
	}
	if(n>=100000&&n<=999999)
	{
		int e=n/100000;
		printf("%4d",e);
	}
	if(n>=1000000&&n<=9999999)
	{
		int f=n/1000000;
		printf("%4d",f);
	}
	if(n>=10000000&&n<=99999999)
	{
		int g=n/10000000;
		printf("%4d",g);
	}
	if(n>=100000000&&n<=999999999)
	{
		int h=n/100000000;
		printf("%4d",h);
	}
	if(n>=1000000000&&n<=9999999999)
	{
		int i=n/1000000000;
		printf("%4d",i);
	}
}
void main()
{
	int n,tieptuc;
	quaylai:chusodautien(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}