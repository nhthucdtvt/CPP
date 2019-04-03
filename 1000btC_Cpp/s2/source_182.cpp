
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(int a[MAX],int &n)
{
	do{
		printf("Nhap vao so phan tu cua mang:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("So phan tu ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1||n>MAX);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao a[%d]=",i);
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
void lietkevadem(int a[MAX],int n)
{
	int dem,dem1=0,dem2=0,dem3=0;
	printf("\nCac phan tu ke nhau ma ca hai deu la gia tri chan la:");
	for(int i=1;i<n-1;i++)
	{
		if(a[i]%2==0&&a[i-1]%2==0)
		{
			printf("%4d",a[i]);
			dem1++;
		}
	}
	for(int i=0;i<n;i=i+n)
	{
		if(a[i]%2==0&&a[i+1]%2==0)
		{
			printf("%4d",a[i]);
			dem2++;
		}
	}
	for(int i=n-1;i<n;i=i+n)
	{
		if(a[i]%2==0&&a[i-1]%2==0)
		{
			printf("%4d",a[i]);
			dem3++;
		}
	}
	dem=dem1+dem2+dem3;
	printf("\nSo luong cac phan tu thoa yeu cau de bai la:%d",dem);
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	lietkevadem(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
