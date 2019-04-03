
#include<stdio.h>
#include<conio.h>
#define MAX 100
#include<limits.h>
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
int GiaTriCanTim(int a[MAX][MAX], int m, int n) 
{
	  int Max=INT_MIN; 
      for (int i=0; i<m; i++) 
      { 
          for(int j=0; j<n; j++) 
          { 
              Max = (Max>a[i][j])?Max:a[i][j]; 
          } 
      } 
	  int Max2 =INT_MIN; 
      for (int i=0; i<m; i++) 
      { 
          for(int j=0; j<n; j++) 
          { 
             if (Max>Max2 && a[i][j]!=Max && Max2<a[i][j]) 
             { 
                Max2 = a[i][j]; 
             } 
         } 
	  } 
      return Max2; 
} 
void main()
{
	int a[MAX][MAX],m,n;
	nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	int s=GiaTriCanTim(a,m,n);
	printf("So lon thu hai la:%d\n",s);
	getch();
}
