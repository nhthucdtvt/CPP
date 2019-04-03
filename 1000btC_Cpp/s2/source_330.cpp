
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatran(int a[MAX][MAX],int &m,int &n)
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
void xuatmatran(int a[MAX][MAX],int m,int n)
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
void kiemtra(int a[MAX][MAX],int m,int n)
{
	int b=m*n;
	int dem=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>=0)
				dem++;
		}
	}
	if(dem==b)
		printf("Ma tran nay toan so duong\n");
	else
		printf("Ma tran nay co ton tai so am\n");
}
void main()
{
	int a[MAX][MAX],m,n,dem,b;
	int NAMSON;
	quaylai:nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	kiemtra(a,m,n);
	printf("\nCo tiep tuc khong ? Bam phim C de tiep tuc,Bam cac phim khac de thoat\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C') 
	goto quaylai;
}
