
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
void hoanvi(int &a,int &b)	// đây là 1 hàm hoán vị giúp tiết kiệm thời gian chạy chương trình hơn những hàm hoán vị trước giờ hay sử dụng.
{
	a=a^b;
	b=a^b;
	a=a^b;
}
void xulydulieu(int a[MAX][MAX],int n,int m)
{
	int b[MAX],i,j,f,dem=0;
	printf("\nCac so nguyen to co trong ma tran la:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
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
				b[dem]=a[i][j];
				dem++;
			}
		}
	}
	printf("\nSo luong cac so nguyen to co trong ma tran la:%d",dem);
	printf("\nCac so nguyen to sau khi sap xep tang dan la:");
	for(i=0;i<dem-1;i++)
	{
		for(j=i+1;j<dem;j++)
		{
			if(b[i]>b[j])
			{
				hoanvi(b[i],b[j]);
			}
		}
	}	
	for(int i=0;i<dem;i++)
	printf("%d ",b[i]);
}
void main()
{
	int a[MAX][MAX],n,m,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	xulydulieu(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	goto quaylai;
}
