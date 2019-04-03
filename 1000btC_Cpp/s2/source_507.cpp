
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập mảng .
void NhapMang(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:n=");
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
// Hàm xuất mảng .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm tạo mảng B chứa các số dương của mảng A .
void TaoMangB(int a[],int b[],int n)
{
	int dem=0,j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			dem++;
			b[j++]=a[i];
		}
	}
	// Xuất mảng B
	for(int j=0;j<dem;j++)
	{
		printf("%4d",b[j]);
	}
}
// Hàm chính .
void main()
{
	int a[MAX],b[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>Xuat Mang A:<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n>>>>>>>>>>>Tao Mang B Chua Cac So Duong Cua Mang A:<<<<<<<<<<<<\n");
	TaoMangB(a,b,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}