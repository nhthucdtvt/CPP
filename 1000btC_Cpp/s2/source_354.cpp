
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
void timnguyentolonnhat(int a[MAX][MAX],int m,int n)
{
	int f,max=INT_MIN,Co;
	bool Co=false;
	printf("Cac so nguyen to trong ma tran la:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			f=1;
			if(a[i][j]<2)
			f=0;
			for(int k=2;k<=a[i][j]/2;k++)
			{
				if(a[i][j]%k==0)
				f=0;
			}
			if(f==1)
			{
			printf("%4d",a[i][j]);
				if(a[i][j]>max)
				{
					max=a[i][j];
					Co=true;
				}
			}
		}
	}
	if(Co==true)
	printf("\nSo nguyen to lon nhat la:%d\n",max);
	else
	printf("\nChang co so nguyen to nao ca\n");
}
void main()
{
	int a[MAX][MAX],m,n,f,max=INT_MIN,Co;
	bool Co=false;
	nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	timnguyentolonnhat(a,m,n);
	getch();
}