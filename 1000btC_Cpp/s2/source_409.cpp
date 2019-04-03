
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(int a[MAX],int &n)
{
	do{
		printf("\nNhap vao so phan tu cua mang:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1||n>MAX);
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
int giatriphanbiet(int a[MAX],int n)
{
	if(n<1)
		return 0;
	if(n==1)
		return 1;
	int kiemtra=1;
	for(int i=0;(i<n-1&&kiemtra==1);i++)
	{
		if(a[i]==a[n-1])
			kiemtra=0;
	}
	return (kiemtra+giatriphanbiet(a,n-1));
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	int s=giatriphanbiet(a,n);
	printf("\nSo luong gia tri phan biet co trong mang la:%d",s);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}