
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 10
// Hàm nhập số nguyên dương .
void NhapN(int &n)
{
	quaylai:printf("\nNhap vao so nguyen duong:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
// Hàm xuất số nguyên dương .
void XuatN(int n)
{
	printf("\nSo nguyen duong vua nhap vao la:%d",n);
}
// Hàm xử lý dữ liệu tách ra các chữ số của số nguyên dương và lưu vào trong mảng a .
int XuLyDuLieu(int a[],int n)
{
	int i=0;
	while(n!=0)
	{
		a[i]=n%10;
		n=n/10;
		i++;
	}
	return i;
}
// Hàm liệt kê ra các chữ số của số nguyên dương .
void LietKeCacChuSo(int a[],int n)
{
	int s=XuLyDuLieu(a,n);
	printf("\n>>>>>>>>>>Cac Chu So Cua So %d La:<<<<<<<<<<<<\n",n);
	for(int k=s-1;k>=0;k--)
	{
		printf("%4d",a[k]);
	}
}
// Hàm kiểm tra xem các chữ số có được sắp thứ tự hay không ? 
void KiemTra(int a[],int n)
{
	int s=XuLyDuLieu(a,n);
	int dem=0,dem1=0;
	printf("\n>>>>>Cac Chu So Cua So %d Co Duoc Sap Thu Tu Hay Khong ?<<<<<<\n",n);
	for(int k=s-2;k>=0;k--)
	{
		if(a[k]-a[k+1]>=0)
		{
			dem++;
		}
		else
		{
			dem1++;
		}
	}
	if(dem==s-1||dem1==s-1)
	{
		printf("\nYES");
	}
	else
	{
		printf("\nNO");
	}
}
// Hàm MeNu .
void MeNu()
{
	int a[MAX],b[MAX],n,tieptuc;
	quaylai:NhapN(n);
	printf("\n");
	XuatN(n);
	printf("\n");
	LietKeCacChuSo(a,n);
	printf("\n");
	KiemTra(a,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
// Hàm chính .
void main()
{
	MeNu();
}