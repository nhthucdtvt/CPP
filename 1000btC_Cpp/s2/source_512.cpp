
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<Windows.h>
// Hàm nhập vào số n .
void NhapN(int &n)
{
	quaylai:printf("\nNhap vao n=");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int n)
{
	float s=0;
	float pow(float x,float y); // Khai báo định dạng pow .
	for(int i=1;i<=n;i++)
	{
		int s1=1;
		for(int j=1;j<=2*i;j++)
		{
			s1*=j;
		}
		s+=(pow(-1,i)*((2*i-1)+(2*i)))/s1;
	}
	printf("\nKet qua la:%f",s);
}
// Hàm chính .
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
