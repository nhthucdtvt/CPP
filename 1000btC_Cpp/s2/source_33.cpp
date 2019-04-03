
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
void Nhapx(float &x)
{
	quaylai:printf("\nNhap vao x=");
	scanf("%f",&x);
	if(x<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
}
void XuLyDuLieu(int n,float x)
{
	float s=sqrt(x);
	for(int i=2;i<=n;i++)
	{
		s=sqrt(pow(x,i)+s);
	}
	printf("\nKet qua la:%f",s);
}
void main()
{
	int n,tieptuc;
	float x,s;
	quaylai:Nhapn(n);
	Nhapx(x);
	XuLyDuLieu(n,x);
	printf("\nBan co muon tiep tuc thuc hien chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
