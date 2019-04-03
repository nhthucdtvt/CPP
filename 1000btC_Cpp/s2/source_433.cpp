
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
void uocso(int n,int k)
{
	int max;
	int l=n/k;
	if(l<k)
		return;
	if(l*k==n)
		printf("%4d",k);
	uocso(n,k+1);
	if(l*k==n&&l!=k)
		printf("%4d",l);
}
void main()
{
	int n,k=1,tieptuc;
	quaylai:nhapn(n);
	printf("\n>>>>>>Cac Uoc So La:<<<<<<<<<\n");
	uocso(n,k);
	if(n==0)
		printf("\nCo Vo So Uoc So");
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}