
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<math.h>
#define MAX 100
void NhapMang(int a[MAX],int &n)
{
	quaylai:printf("\nNhap vao so phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
	for(int i=0;i<n;i++)
	{
		quaylai1:printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
		if(a[i]!=0&&a[i]!=1)
		{
			printf("\nGia tri ban nhap khong hop le!Xin vui long nhap lai!\n");
			goto quaylai1;
		}
	}
}
void XuatMang(int a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void ChuyenSangHe10(int a[MAX],int n)
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		tong+=a[i]*pow(2.0,n-1-i);
	}
	printf("\nHe thap phan la:%d",tong);
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	XuatMang(a,n);
	ChuyenSangHe10(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}