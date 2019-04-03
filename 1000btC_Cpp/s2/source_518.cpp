
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập mảng A .
void NhapMangA(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
// Hàm nhập mảng B .
void NhapMangB(int b[],int &m)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:");
	scanf("%d",&m);
	if(m<1||m>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	for(int i=0;i<m;i++)
	{
		printf("\nNhap vao b[%d]=",i);
		scanf("%d",&b[i]);
	}
}
// Hàm xuất mảng .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm tạo mảng C .
void TaoMangC(int a[],int b[],int c[],int n,int m)
{
	int k=0;
	int dem=n+m;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			c[k++]=a[i];
		}
	}
	for(int i=0;i<m;i++)
	{
		if(b[i]%2==0)
		{
			c[k++]=b[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			c[k++]=a[i];
		}
	}
	for(int i=0;i<m;i++)
	{
		if(b[i]%2!=0)
		{
			c[k++]=b[i];
		}
	}
	// Xuất mảng C
	for(int k=0;k<dem;k++)
	{
		printf("%4d",c[k]);
	}
}
// Hàm chính .
void main()
{
	int a[MAX],b[MAX],c[MAX],n,m,tieptuc;
	quaylai:printf("\n>>>>>>>>>>>Nhap Mang A:<<<<<<<<<<<<<\n");
	NhapMangA(a,n);
	printf("\n>>>>>>>>>>>Nhap Mang B:<<<<<<<<<<<<<\n");
	NhapMangB(b,m);
	printf("\n>>>>>>>>>>>Xuat Mang A:<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	printf("\n>>>>>>>>>>>Xuat Mang B:<<<<<<<<<<<<<<<\n");
	XuatMang(b,m);
	printf("\n");
	printf("\n>>>>>>>>>>>Xuat Mang C:<<<<<<<<<<<<<<<\n");
	TaoMangC(a,b,c,n,m);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}