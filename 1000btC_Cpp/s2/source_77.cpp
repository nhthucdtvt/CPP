
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void NhapMangNhiPhan(int a[])
{
	for (int i=0; i<32; i++)
	{
		quaylai:printf ("\nnhap a[%d]=",i);
		scanf ("%d",&a[i]);
		if(a[i]!=0&&a[i]!=1)
		{
			printf("\nGia tri ban nhap khong hop le!Xin vui long nhap lai!");
			goto quaylai;
		}
	}
}
void ChuyenSangHe10(int a[])
{
	int n=0;
	for (int i=0;i<=31;i++)
	{
		n=n^(a[i]<<(32-1-i)) ;
	}
	printf ("\nSo thap phan tuong ung la:%d",n);
}
void main()
{
	int a[32],tieptuc;
	quaylai:NhapMangNhiPhan(a);
	ChuyenSangHe10(a);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc !");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}