
#include<stdio.h>
#include<conio.h>
#define MAX 100
#include<float.h>
#define bool
void nhapmatran(float a[MAX][MAX],int &m,int &n)
{
	do{
	printf("Nhap vao so dong:m=");
	scanf("%d",&m);
	if(m<1||m>MAX)
	printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
	else
	break;
	}while(m<1||m>MAX);
	do{
	printf("Nhap vao so cot:n=");	
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
void timduongnhonhat(float a[MAX][MAX],int m,int n)
{
	int Co;
	float min=FLT_MAX;
	bool Co=false;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>=0&&a[i][j]<min)
			{
				min=a[i][j];
				Co=true;
			}
		}
	}
	if(Co==true)
	printf("So duong nho nhat la:%f\n",min);
	else
	printf("Ma tran nay khong co so duong");
}
void main()
{
	float a[MAX][MAX],min=FLT_MAX;
	int m,n,Co;
	nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	timduongnhonhat(a,m,n);
	getch();
}
	