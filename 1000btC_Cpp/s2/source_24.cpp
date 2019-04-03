
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
	float s=0;
	for(int i=0;i<n;i++)
	{
		s=sqrt(2+s);
	}
	printf("\nDap so la:%f",s);
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