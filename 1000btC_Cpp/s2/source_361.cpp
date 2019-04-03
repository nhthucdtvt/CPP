
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 100
void nhapmatran(int a[MAX][MAX],int &m,int &n)
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
void tinhtongcacdongvalietkedongcotonglonnhat(int a[MAX][MAX],int m,int n)
{
	int b[MAX],max=INT_MIN,vitri=0;
	for(int i=0;i<m;i++)
	{
		int tong=0;
		for(int j=0;j<n;j++)
		{
			tong+=a[i][j];
			b[i]=tong;
		}
	}
	for(int i=0;i<m;i++)
		printf("\nTong cac phan tu cua dong %d la:%d",i,b[i]);
	for(int i=0;i<m;i++)
	{
		if(b[i]>max)
		{
			max=b[i];
		}
	}
	printf("\nCac dong co tong lon nhat la:");
	for(int i=0;i<m;i++)
	{
		if(b[i]==max)
		{
			vitri=i;
			printf("%4d",vitri);
		}
	}
}
void main()
{
	int a[MAX][MAX],m,n,tieptuc;
	quaylai:nhapmatran(a,m,n);
	printf("\n>>>>>>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,m,n);
	tinhtongcacdongvalietkedongcotonglonnhat(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
