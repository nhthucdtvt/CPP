
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatran(int a[MAX][MAX],int &n,int &m)
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
void xuatmatran(int a[MAX][MAX],int n,int m)
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
void sapxepgiamtrendong(int a[MAX][MAX],int n,int m,int &x)
{
	do{
		printf("Nhap vao so dong can sap xep:x=");
		scanf("%d",&x);
		if(x<0||x>m-1)
			printf("\nSo dong ban nhap khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(x<0||x>m-1);
	for (int j=0; j<n; j++)
	{
		for (int k=j+1; k<n;k++)
		{
			if (a[x][j]<a[x][k])
			{
				int temp = a[x][j];
				a[x][j] = a[x][k];
				a[x][k] = temp;
			}
		}
	}
} 
void main()
{
	int a[MAX][MAX],n,m,x,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>>SAP XEP GIAM DAN TU TRAI SANG PHAI TREN 1 DONG:<<<<<<<<<<<<<<<<<<<<\n");
	sapxepgiamtrendong(a,n,m,x);
	xuatmatran(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
