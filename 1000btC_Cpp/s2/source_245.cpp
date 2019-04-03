
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
void SapXepGiamDanBangThuatToanInterchangeSort(int a[])
{
	for(int i=0;i<MAX-1;i++)
	{
		for(int j=i+1;j<MAX;j++)
		{
			if(a[i]<a[j])
			{
				HoanVi(a[i],a[j]);
			}
		}
	}
}
void main()
{
	int a[MAX],tieptuc;
	quaylai:PhatSinhNgauNhien(a);
	printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a);
	printf("\n");
	SapXepGiamDanBangThuatToanInterchangeSort(a);
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