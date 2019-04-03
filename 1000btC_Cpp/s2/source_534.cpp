
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
// Hàm tô màu .
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void NhapN(unsigned long &n)
{
	quaylai:printf("\nNhap vao so nguyen N=");
	scanf("%lu",&n);
	if(n<=100000)
	{
		printf("\nGia tri N khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
void PhuongAn(unsigned long n)
{
	unsigned long dem=0;
	unsigned long a,b,c;
	textcolor(14); // Tô màu vàng .
	printf("\n--------------------------------------------------------------------------------");
	printf("Cach Thu \t");
	printf("So To 10 000 \t");
	printf("So To 20 000 \t");
	printf("So To 50 000 \t");
	printf("\n--------------------------------------------------------------------------------");
	textcolor(7); // Trả về màu chữ bình thường .
	for(a=0;a<=n/10000;a++)
	{
		for(b=0;b<=n/20000;b++)
		{
			for(c=0;c<=n/50000;c++)
			{
				if(a*10000+b*20000+c*50000==n)
				{
					dem++;
					printf("%lu\t\t\t",dem);
					printf("%lu\t\t",a);
					printf("%lu\t\t",b);
					printf("%lu\t",c);
					printf("\n--------------------------------------------------------------------------------");
				}
			}
		}
	}
	printf("\n");
	printf("\nTong cong ta co %lu cach de tra %lu dong",dem,n);
}
void main()
{
	int tieptuc;
	unsigned long n;
	quaylai:NhapN(n);
	PhuongAn(n);
	printf("\n");
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}