
#include<stdio.h>
#include<conio.h>
void nhapn(int &n)
{
	do{
		printf("\nNhap vao so nguyen duong n=");
		scanf("%d",&n);
		if(n<1)
			printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1);
}
long tich(int n)
{
	if(n==1)
		return 1;
	return (n*tich(n-1));
}
long tong(int n)
{
	long s=tich(n);
	if(n==1)
		return 1;
	return (s+tong(n-1));
}
void main()
{
	int n,tieptuc;
	quaylai:nhapn(n);
	long s1=tong(n);
	printf("\nKet qua la:%d",s1);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}