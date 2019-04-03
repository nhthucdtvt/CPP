
#include<stdio.h>
#include<conio.h>
#include<float.h>
#define MAX 100
void nhapmatran(float a[MAX][MAX],int &n,int &m)
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
void xuatmatran(float a[MAX][MAX],int n,int m)
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
void xulydulieu(float a[MAX][MAX],int n,int m)
{
	float max=FLT_MIN;
	int tam;
	for(int i=0;i<m;i++)	// 2 vòng lặp này là để tìm ra giá trị max trong ma trận.
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>max)
				max=a[i][j];
		}
	}
	for(int i=0;i<m;i++)	// 2 vòng lặp này là tìm ra dòng nào có chứa giá trị max vừa tìm được ở trên.
	{
		for(int j=0;j<n;j++)
		{
			tam=0;
			if(a[i][j]==max)
			{
				tam=1;
				break;
			}
		}
		if(tam==1)
			printf("\nDong:%d",i);
	}
}
void main()
{
	float a[MAX][MAX];
	int n,m,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>>CAC DONG TRONG MA TRAN CO CHUA GIA TRI MAX LA:<<<<<<<<<<<<<<<<<<<<\n");
	xulydulieu(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}