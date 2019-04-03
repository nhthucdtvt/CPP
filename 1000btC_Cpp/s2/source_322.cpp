
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatran(float a[MAX][MAX],int &m,int &n)
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
			scanf("%f",&a[i][j]);
		}
	}
}
void xuatmatran(float a[MAX][MAX],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%16f",a[i][j]);
		}
		printf("\n");
	}
}
void kiemtra(float a[MAX][MAX],int m,int n)
{
	float x;
	int dem=0;
	printf("Nhap vao x=");
	scanf("%f",&x);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==x)
				dem++;
		}
	}
	printf("Tan so xuat hien cua x trong ma tran la:%d lan\n",dem);
}
void main()
{
	float a[MAX][MAX];
	int m,n,dem;
	nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	kiemtra(a,m,n);
	getch();
}