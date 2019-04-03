
#include<stdio.h>
#include<conio.h>
void nhapn(int &n)
{
	quaylai:printf("\nNhap vao so nguyen duong n=");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
}
float tong(int n)
{
	if(n==0)
		return 0;
	return ((n*1.0)/(n+1)+tong(n-1));
}
void main()
{
	int n,tieptuc;
	quaylai:nhapn(n);
	float s=tong(n);
	printf("\nKet qua la:%f",s);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}