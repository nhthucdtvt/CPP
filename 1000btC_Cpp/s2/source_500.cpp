
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
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
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
int KiemTra(int a[],int n)
{
	int b=a[1]-a[0],dem=0;
	for(int i=2;i<n;i++)
	{
		if(a[i]-a[i-1]==b)
		{
			dem++;
		}
	}
	if(dem==n-2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\nKiem Tra Neu Mang Lap Thanh Cap So Cong Thi Tra Ve Gia Tri 1,Nguoc Lai Tra Ve Gia Tri 0\n");
	int s=KiemTra(a,n);
	printf("\nKet qua tra ve la:%d",s);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}