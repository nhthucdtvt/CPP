
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#define MAX 40
void PhatSinhNgauNhien(int a[])
{
	srand(time(0));
	for(int i=0;i<MAX;i++)
	{
		a[i]=(rand()%61)-30;
	}
}
void XuatMang(int a[])
{
	for(int i=0;i<MAX;i++)
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
void SapXepGiamDanBangThuatToanQuickSort(int a[],int left,int right)
{
	int i,j,x;
	if(left>=right)
	{
		return;
	}
	x=a[(left+right)/2]; // Chọn phần tử giữa làm giá trị mốc .
	i=left;
	j=right;
	while(i<j)
	{
		while(a[i]>x) // ở đây là sắp giảm dần
		{
			i++;
		}
		while(a[j]<x) // ở đây là sắp giảm dần
		{
			j--;
		}
		if(i<=j)
		{
			HoanVi(a[i],a[j]);
			i++;
			j--;
		}
	}
	SapXepGiamDanBangThuatToanQuickSort(a,left,j);
	SapXepGiamDanBangThuatToanQuickSort(a,i,right);
}
void main()
{
	int a[MAX],tieptuc;
	quaylai:PhatSinhNgauNhien(a);
	printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a);
	printf("\n");
	SapXepGiamDanBangThuatToanQuickSort(a,0,MAX-1);
	printf("\n>>>>>>>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan La:<<<<<<<\n");
	XuatMang(a);
	printf("\n");
	printf("\nBan muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}