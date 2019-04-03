
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập ma trận .
void NhapMaTran(int a[MAX][MAX],int &m,int &n)
{
	quaylai:printf("\nNhap vao so dong cua ma tran:");
	scanf("%d",&m);
	if(m<1||m>MAX)
	{
		printf("\nSo dong khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	quaylai1:printf("\nNhap vao so cot cua ma tran:");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo cot khong hop le!Xin vui long nhap lai!");
		goto quaylai1;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("\nNhap vao a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
// Hàm xuất ma trận .
void XuatMaTran(int a[MAX][MAX],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}
// Hàm hoán vị .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int a[MAX][MAX],int b[],int m,int n)
{
	int dem=0,k=0,l;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>=0)
			{
				dem++; // Đếm số lượng các giá trị dương trong ma trận .
				b[k++]=a[i][j]; // Lưu các giá trị dương trong ma trận vào mảng b .
			}
		}
	}
	// Sắp xếp mảng b chứa các giá trị dương trong ma trận giảm dần và xuất ra mảng b .
	for(k=0;k<dem;k++)
	{
		for(l=k+1;l<dem;l++)
		{
			if(b[k]<b[l])
			{
				HoanVi(b[k],b[l]);
			}
		}
		printf("%4d",b[k],b[l]);
	}
}
// Hàm chính .
void main()
{
	int a[MAX][MAX],b[MAX],n,m,tieptuc;
	quaylai:NhapMaTran(a,m,n);
	printf("\n>>>>>>>>>Ma Tran Vua Nhap La:<<<<<<<<<<<\n");
	XuatMaTran(a,m,n);
	printf("\n>>>>>>>>>Cac So Duong Co Trong Ma Tran Va Duoc Sap Giam Dan:<<<<<<<<<<<<<\n");
	XuLyDuLieu(a,b,m,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc thi chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}