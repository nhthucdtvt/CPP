
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(float a[MAX],int &n)
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
		scanf("%f",&a[i]);
	}
}
void xuatmang(float a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
int toanam(float a[MAX],int n)
{
	if(n==1&&a[0]>=0)
		return 0;
	if(n==1&&a[0]<0)
		return 1;
	if(a[n-1]>=0)
		return 0;
	return (toanam(a,n-1));
}
void main()
{
	int n,tieptuc;
	float a[MAX];
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	int s=toanam(a,n);
	printf("%d",s);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}