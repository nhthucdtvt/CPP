
#include<stdio.h>
#include<Windows.h>
#define MAX 100
void nhapmang(int a[MAX],int &n)
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
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void color(int a)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,a);
}
void XuatChanVangLeTrang(int a[MAX], int n)
{
	for (int i=0; i<n; i++)
	{
		if (a[i]%2==0)
		{
			color(14);
			printf("%4d",a[i]);
		}
		else
		{
			color(7);
			printf("%4d",a[i]);
		}
	}
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>MANG XUAT RA LA:<<<<<<<<<<<<<<<<<\n");
	XuatChanVangLeTrang(a,n);
}
