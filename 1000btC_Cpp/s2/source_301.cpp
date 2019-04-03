
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
void tinhtongcacsoduong(float a[MAX][MAX],int m,int n)
{
	float tong=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>=0)
			{
				tong+=a[i][j];
			}
		}
	}
	printf("\nTong cac so duong co trong ma tran la:%f",tong);
}
void main()
{
	float a[MAX][MAX];
	int m,n,tieptuc;
	quaylai:nhapmatran(a,m,n);
	printf("\n>>>>>>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,m,n);
	tinhtongcacsoduong(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}