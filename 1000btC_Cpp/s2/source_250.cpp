
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
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
void XuatMang(int a[],int n)
{
   for(int i=0;i<n;i++)
   {
	   printf("%4d",a[i]);
   }
}
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
void SapXepGiamDanBangThuatToanBubbleSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				HoanVi(a[j],a[j-1]);
			}
		}
	}
}
void main()
{
	int a[MAX],n,tieptuc,i,j;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>>>>Mang Ban Dau La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapXepGiamDanBangThuatToanBubbleSort(a,n);
	printf("\n>>>>>>>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan La:<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	printf("\nBan muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}