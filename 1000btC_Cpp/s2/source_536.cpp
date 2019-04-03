
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
// Hàm nhập dữ liệu ngày-tháng-năm .
void NhapDuLieu(int &ngay,int & thang,int &nam)
{
	quaylai:printf("\nNhap vao nam:");
	scanf("%d",&nam);
	if(nam<1)
	{
		printf("\nNam khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	quaylai1:printf("\nNhap vao thang:");
	scanf("%d",&thang);
	if(thang<1||thang>12)
	{
		printf("\nThang khong hop le!Xin vui long nhap lai!");
		goto quaylai1;
	}
	quaylai2:printf("\nNhap vao ngay:");
	scanf("%d",&ngay);
	if(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10||thang==12)
	{
		if(ngay<1||ngay>31)
		{
			printf("\nNgay khong hop le!Xin vui long nhap lai!");
			goto quaylai2;
		}
	}
	else if(thang==4||thang==6||thang==9||thang==11)
	{
		if(ngay<1||ngay>30)
		{
			printf("\nNgay khong hop le!Xin vui long nhap lai!");
			goto quaylai2;
		}
	}
	// Năm nhuận => tháng 2 có 29 ngày .
	if(nam%400==0)
	{
		if(thang==2)
		{
			if(ngay<1||ngay>29)
			{
				printf("\nNgay khong hop le!Xin vui long nhap lai!");
				goto quaylai2;
			}
		}
	}
	// Năm không nhuận => tháng 2 có 28 ngày .
	else if(nam%4!=0)
	{
		if(thang==2)
		{
			if(ngay<1||ngay>28)
			{
				printf("\nNgay khong hop le!Xin vui long nhap lai!");
				goto quaylai2;
			}
		}
	}
}
// Hàm xuất dữ liệu ngày-tháng-năm vừa nhập .
void XuatDuLieu(int ngay,int thang,int nam)
{
	printf("\n>>>>>>>>>>>>>>>>>> Du Lieu Ngay,Thang,Nam Vua Nhap <<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngay);
	printf("%d \t\t",thang);
	printf("%d \t\t",nam);
	printf("\n-------------------------------------------------------------------\n");
}
// Hàm xuất ra dữ liệu ngày-tháng-năm kế tiếp .
void KeTiep(int ngay,int thang,int nam)
{
	int ngayketiep,thangketiep,namketiep;
	if(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10)
	{
		if(ngay>=1&&ngay<=30)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==31)
		{
			ngayketiep=1;
			thangketiep=thang+1;
			namketiep=nam;
		}
	}
	else if(thang==12)
	{
		if(ngay>=1&&ngay<=30)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==31)
		{
			ngayketiep=1;
			thangketiep=1;
			namketiep=nam+1;
		}
	}
	else if(thang==4||thang==6||thang==9||thang==11)
	{
		if(ngay>=1&&ngay<=29)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==30)
		{
			ngayketiep=1;
			thangketiep=thang+1;
			namketiep=nam;
		}
	}
	else if(thang==2)
	{
		// Năm nhuận => tháng 2 có 29 ngày .
		if(nam%400==0)
		{
			if(ngay>=1&&ngay<=28)
			{
				ngayketiep=ngay+1;
				thangketiep=thang;
				namketiep=nam;
			}
			else if(ngay==29)
			{
				ngayketiep=1;
				thangketiep=thang+1;
				namketiep=nam;
			}
		}
		// Năm không nhuận => tháng 2 có 28 ngày .
		else if(nam%4!=0)
		{
			if(ngay>=1&&ngay<=27)
			{
				ngayketiep=ngay+1;
				thangketiep=thang;
				namketiep=nam;
			}
			else if(ngay==28)
			{
				ngayketiep=1;
				thangketiep=thang+1;
				namketiep=nam;
			}
		}
	}
	printf("\n>>>>>>>>>>>>>>>>>> Du Lieu Ngay,Thang,Nam Ke Tiep <<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngayketiep);
	printf("%d \t\t",thangketiep);
	printf("%d \t\t",namketiep);
	printf("\n-------------------------------------------------------------------\n");
}
// Hàm xuất ra dữ liệu ngày-tháng-năm trước đó .
void TruocDo(int ngay,int thang,int nam)
{
	int ngaytruocdo,thangtruocdo,namtruocdo;
	if(thang==2||thang==4||thang==6||thang==8||thang==9||thang==11)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=31;
			thangtruocdo=thang-1;
			namtruocdo=nam;
		}
	}
	else if(thang==1)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=31;
			thangtruocdo=12;
			namtruocdo=nam-1;
		}
	}
	else if(thang==5||thang==7||thang==10||thang==12)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=30;
			thangtruocdo=thang-1;
			namtruocdo=nam;
		}
	}
	else if(thang==3)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			// Năm nhuận => tháng 2 có 29 ngày .
			if(nam%400==0)
			{
				ngaytruocdo=29;
				thangtruocdo=thang-1;
				namtruocdo=nam;
			}
			// Năm không nhuận => tháng 2 có 28 ngày .
			else if(nam%4!=0)
			{
				ngaytruocdo=28;
				thangtruocdo=thang-1;
				namtruocdo=nam;
			}
		}
	}
	printf("\n>>>>>>>>>>>>>>>>>> Du Lieu Ngay,Thang,Nam Truoc Do <<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngaytruocdo);
	printf("%d \t\t",thangtruocdo);
	printf("%d \t\t",namtruocdo);
	printf("\n-------------------------------------------------------------------\n");
}
// Hàm chính .
void main()
{
	int tieptuc;
	int ngay,thang,nam;
	quaylai:NhapDuLieu(ngay,thang,nam);
	XuatDuLieu(ngay,thang,nam);
	KeTiep(ngay,thang,nam);
	TruocDo(ngay,thang,nam);
	printf("\n");
	printf("\nLua Chon ? ");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}