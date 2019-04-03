
#include<stdio.h>
#include<conio.h>
#define MAX 100
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
int AmDauTien(float a[MAX][MAX], int m, int n) 
{ 
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n; j++) 
        { 
            if (a[i][j]<0) 
            { 
                return a[i][j]; 
            } 
        } 
   } 
     return 0; 
}
int GiaTriCanTim(float a[MAX][MAX], int m, int n) 
{ 
   int AmMax = AmDauTien(a,m,n); 
   if (AmMax == 0) 
   { 
        return 0; 
   } 
   for (int i=0; i<m;i++) 
   { 
       for (int j=0; j<n; j++) 
       { 
           if (a[i][j]<0) 
           { 
               AmMax = (AmMax>a[i][j])?AmMax:a[i][j]; 
           } 
      } 
   } 
     return AmMax; 
} 
void main()
{
	float a[MAX][MAX];
	int m,n;
	nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	float s=GiaTriCanTim(a,m,n);
	printf("So am lon nhat trong ma tran la:%f\n",s);
	getch();
}
