
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
void demsoduongtrenbien(float a[MAX][MAX],int m,int n)
{
	int dem=0,dem1=0,dem2,dem3=0,dem4=0,dem5=0;
	if(m!=1&&n!=1)
	{
		for(int i=0;i<m;i=i+m-1)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>=0)
					dem++;
			}
		}
		for(int i=1;i<m-1;i++)
		{
			for(int j=0;j<n;j=j+n-1)
			{
				if(a[i][j]>=0)
					dem1++;
			}
		}
		dem2=dem+dem1;
		printf("\nSo luong cac so duong tren bien ma tran la:%d",dem2);
	}
	if(m==1&&n!=1)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>=0)
				dem3++;
			}
		}
		printf("\nSo luong cac so duong tren bien ma tran la:%d",dem3);
	}
	if(m!=1&&n==1)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>=0)
				dem4++;
			}
		}
		printf("\nSo luong cac so duong tren bien ma tran la:%d",dem4);
	}
	if(m==1&&n==1)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>=0)
				dem5++;
			}
		}
		printf("\nSo luong cac so duong tren bien ma tran la:%d",dem5);
	}
}
void main()
{
	float a[MAX][MAX];
	int m,n,tieptuc;
	quaylai:nhapmatran(a,m,n);
	printf("\n>>>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,m,n);
	demsoduongtrenbien(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}