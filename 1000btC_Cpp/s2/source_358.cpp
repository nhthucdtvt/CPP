
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<limits.h>
#define MAX 100
#define bool
void nhapmatran(int a[MAX][MAX],int &n,int &m)
{
	do{
		printf("Nhap vao so dong cua ma tran:m=");
		scanf("%d",&m);
		if(m<1||m>MAX)
			printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(m<1||m>MAX);
	do{
		printf("Nhap vao so cot cua ma tran:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("So cot ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1||n>MAX);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Nhap vao a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatmatran(int a[MAX][MAX],int n,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}
void xulydulieu(int a[MAX][MAX],int n,int m)
{
	int max=INT_MIN,dem=0,Co;
	double sqrt(double x);
	bool Co=false;
	printf("\nCac so chinh phuong co trong ma tran la:");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<=a[i][j];k++)
			{
				if(sqrt (a[i][j])==k)
				{
					printf("%4d",a[i][j]);
					dem++;
				}
			}
		}
	}
	printf("\nSo luong cac so chinh phuong la:%d",dem);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<=a[i][j];k++)
			{
				if(sqrt (a[i][j])==k&&a[i][j]>max)
				{
					max=a[i][j];
					Co=true;
				}
			}
		}
	}
	if(Co==true)
		printf("\nSo chinh phuong lon nhat la:%d",max);
	else
		printf("\nTrong mang khong ton tai so chinh phuong");
}
void main()
{
	int a[MAX][MAX],n,m,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	xulydulieu(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}