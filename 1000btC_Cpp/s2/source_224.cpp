
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập mảng .
void NhapMang(int a[],int &n)
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
// Hàm xuất mảng .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm tạo mảng b .
void TaoMangB(int a[],int b[],int n)
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			b[j++]=1;
		}
		else
		{
			b[j++]=0;
		}
	}
	// Xuất mảng b .
	for(int j=0;j<n;j++) // Số lượng phần tử của mảng b cũng bằng đúng n .
	{
		printf("%4d",b[j]);
	}
}
// Hàm chính .
void main()
{
	int a[MAX],b[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	printf("\n>>>>>>>>>>>Mang B Duoc Tao Tu Mang A:<<<<<<<<<<<<<\n");
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