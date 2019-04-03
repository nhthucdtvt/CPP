
#include<stdio.h>
#include<limits.h>
#include<conio.h>
#define MAX 100
#define bool
void nhapmang(int a[MAX],int &n)
{
	do{
	printf("Nhap vao so phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	printf("So ban nhap vao khong hop le!Xin ban vui long nhap lai!\n");
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
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
    int Co,min=INT_MAX;
	bool Co=false;
	printf("\nCac so le co trong mang la:");
    for(int i=0;i<n;i++)
    {
		if(a[i]%2!=0)
		printf("%4d",a[i]);
        if(a[i]%2!=0&&a[i]<min)
		{
            min=a[i];
			Co=true;
		}
    }
    if(Co==true)
	{
		int b=min-1;
		printf("\nSo chan lon nhat nho hon moi gia tri le co trong mang la:%d",b);
	}
	else
	printf("\nMang nay khong ton tai gia tri le nen khong the tinh toan duoc");
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
