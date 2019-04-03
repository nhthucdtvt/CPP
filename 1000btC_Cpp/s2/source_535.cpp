
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
void NhapN(int &n)
{
	do
	{
		printf("\nNhap vao so giay:");
		scanf("%d",&n);
		if(n<0)
		{
			printf("\nSo giay khong hop le!Xin vui long nhap lai!");
		}
	}while(n<0);
}
void ChuyenDoi(int n)
{
	int gio,phut,giay;
	gio=n/3600;
	phut=(n-(gio*3600))/60;
	giay=n-(gio*3600+phut*60);
	printf("\nChuyen doi ra thanh: %d:%d:%d",gio,phut,giay);
}
void main()
{
	int n,tieptuc;
	quaylai:NhapN(n);
	ChuyenDoi(n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
