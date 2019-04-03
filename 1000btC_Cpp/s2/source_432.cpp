
#include<stdio.h>
#include<conio.h>
void nhapdulieu(float &x,int &n)
{
	printf("\nNhap gia tri x=");
	scanf("%f",&x);
	quaylai:printf("\nNhap vao gia tri n=");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
}
long giaithua(int n)
{
	if(n==0)
		return 1;
	return (giaithua(n-1)*2*n*(2*n-1));
}
float tinhmu(float x,int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return x*x;
	return (tinhmu(x,n-1)*x*x);
}
float tinhtong(float x,int n)
{
	long s=giaithua(n);
	float s1=tinhmu(x,n);
	if(n==0)
		return 1;
	return (s1/s+tinhtong(x,n-1));
}
void main()
{
	int n,tieptuc;
	float x;
	quaylai:nhapdulieu(x,n);
	float s=tinhtong(x,n);
	printf("\nket qua la:%f",s);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
