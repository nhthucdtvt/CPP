
#include<stdio.h>
#include<conio.h>
void nhapdulieu(int &n)
{
	quaylai:printf("\nNhap vao gia tri n=");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
}
long tong(int n)
{
	if(n==0)
		return 0;
	return (n+tong(n-1));
}
float tinhtong(int n)
{
	long s=tong(n);
	if(n==1)
		return 1;
	return (1.0/s+tinhtong(n-1));
}
void main()
{
	int n,tieptuc;
	quaylai:nhapdulieu(n);
	float s=tinhtong(n);
	printf("\nKet qua la:%f",s);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
