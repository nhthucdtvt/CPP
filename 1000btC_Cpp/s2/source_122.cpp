
#include<stdio.h>
#include<conio.h>
#define MAX 100
#include<limits.h>
#define bool
void nhapmang (int a[MAX],int &n)
{
	do{
	printf("Nhap vao so phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
	else
	break;
	}while(n<1||n>MAX);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[MAX],int n)
{
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
	int max=INT_MIN,Co;
	bool Co=false;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			Co=true;
		}
	}
	if(Co==true)
	{
		if(max>=-9&&max<=9)
		{
			int b=max%10;
			if(b%2!=0)
			printf("So thoa dieu kien la:%d",max);
			else
			printf("0\n");
		}
		if(max>=-99&&max<=-10||max>=10&&max<=99)
		{
			int b=max/10;
			int c=max%10;
			if(b%2!=0&&c%2!=0)
			printf("So thoa dieu kien la:%d",max);
			if(b%2==0||c%2==0)
			printf("0\n");
		}
		if(max>=-999&&max<=-100||max>=100&&max<=999)
		{
			int b=max/100;
			int c=max/10;
			int d=max%10;
			if(b%2!=0&&c%2!=0&&d%2!=0)
			printf("So thoa dieu kien la:%d",max);
			if(b%2==0||c%2==0||d%2==0)
			printf("0\n");
		}
		if(max>=-9999&&max<=-1000||max>=1000&&max<=9999)
		{
			int b=max/1000;
			int c=max/100;
			int d=max/10;
			int e=max;
			if(b%2!=0&&c%2!=0&&d%2!=0&&e%2!=0)
			printf("So thoa dieu kien la:%d",max);
			if(b%2==0||c%2==0||d%2==0||e%2==0)
			printf("0\n");
		}
		if(max>=-99999&&max<=-10000||max>=10000&&max<=99999)
		{
			int b=max/10000;
			int c=max/1000;
			int d=max/100;
			int e=max/10;
			int f=max;
			if(b%2!=0&&c%2!=0&&d%2!=0&&e%2!=0&&f%2!=0)
			printf("So thoa dieu kien la:%d",max);
			if(b%2==0||c%2==0||d%2==0||e%2==0||f%2==0)
			printf("0\n");
		}
	}	
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}