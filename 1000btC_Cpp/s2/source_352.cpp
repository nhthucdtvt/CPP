
#include<stdio.h>
#include<conio.h>
#define MAX 100
#include<limits.h>
#define bool
void nhapmatran(int a[MAX][MAX],int &m,int &n)
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
void timchanlonnhat(int a[MAX][MAX],int m,int n)
{
	int max=INT_MIN,Co;
	bool Co=false;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]%2==0&&a[i][j]>max)
			{
				max=a[i][j];
				Co=true;
			}
		}
	}	
	if(Co==true)
	printf("So chan lon nhat la:%d\n",max);
	else
	printf("Trong ma tran khong ton tai so chan");
}
void main()
{
	int a[MAX][MAX],m,n,max,Co;
	bool Co=false;
	nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	timchanlonnhat(a,m,n);
	getch();
}
