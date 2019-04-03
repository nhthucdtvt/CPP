
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
void NhapN(int &n)
{
	do{
		printf("\nNhap vao thang:");
		scanf("%d",&n);
		if(n<1||n>12)
		{
			printf("\nThang ban nhap vao khong hop le!Xin vui long nhap lai!");
		}
	}while(n<1||n>12);
}
void XuLyDuLieu(int n)
{
	if(n==1||n==3||n==5||n==7||n==8||n==10||n==12)
	{
		printf("\nThang %d co 31 ngay",n);
	}
	else if(n==4||n==6||n==9||n==11)
	{
		printf("\nThang %d co 30 ngay",n);
	}
	else if(n==2)
	{
		printf("\nThang %d co 28 hoac 29 ngay",n);
	}
}
void main()
{
	int n,tieptuc;
	quaylai:NhapN(n);
	XuLyDuLieu(n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}