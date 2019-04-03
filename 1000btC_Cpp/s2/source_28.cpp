
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<math.h>
void Nhapn(int &n)
{
	quaylai:printf("\nNhap vao n=");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
void XuLyDuLieu(int n)
{
	float s=sqrt(1.0);
	float s1=1;
	for(int i=2;i<=n;i++)
	{
		s1*=i; // Tính giai thừa .
		s=sqrt(s1+s);
	}
	printf("\nKet qua la:%f",s);
}
void main()
{
	int n,tieptuc;
	float s;
	quaylai:Nhapn(n);
	XuLyDuLieu(n);
	printf("\nBan co muon tiep tuc thuc hien chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}