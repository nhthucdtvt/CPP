
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "Windows.h"
// Nhập số nguyên N .
void NhapN(int &n)
{
	printf("\nO day ta cho phep gioi han n chay den 10 000 \n");
	quaylai:printf("\nNhap vao n=");
	scanf("%d",&n);
	if(n<0||n>10000)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
// Liệt kê ra N số Nguyên Tố đầu tiên .
void NguyenTo(int n)
{
	int f,dem=0;
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n%d So nguyen to dau tien la:",n);
	for(int i=2;i<=10000;i++)
	{
		f=1;
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				f=0;
			}
		}
		if(f==1)
		{
			dem++;
			if(dem<=n)
			{
				printf("%8d",i);
			}
		}
	}
	printf("\n");
}
// Liệt kê ra N số Chính Phương đầu tiên .
void ChinhPhuong(int n)
{
	int dem=0;
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n%d So Chinh Phuong dau tien la:",n);
	float sqrt(float x);
	for(int i=0;i<=10000;i++)
	{
		float ketqua=sqrt(i);
		if((float)ketqua==(int)ketqua)
		{
			dem++;
			if(dem<=n)
			{
				printf("%8d",i);
			}
		}
	}
	printf("\n");
}
// Liệt kê ra N Số Chẵn đầu tiên .
void SoChan(int n)
{
	int dem=0;
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\nO day ta cho phep so chan bat dau tu 0 \n");
	printf("\n%d So Chan dau tien la:",n);
	for(int i=0;i<=10000;i=i+2)
	{
		dem++;
		if(dem<=n)
		{
			printf("%8d",i);
		}
	}
}
// Hàm chính .
void main()
{
	int n,tieptuc;
	quaylai:NhapN(n);
	NguyenTo(n);
	ChinhPhuong(n);
	SoChan(n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc !");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
