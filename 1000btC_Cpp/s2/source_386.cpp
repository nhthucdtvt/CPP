
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatranvuong(int a[MAX][MAX],int &m,int &n)
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
		if(n!=m)
			printf("So cot ban nhap vao khong thoa tinh chat la ma tran vuong (n==m).Xin vui long nhap lai!\n");
		else
			break;
	}while(n!=m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Nhap vao a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatmatranvuong(int a[MAX][MAX],int m,int n)
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
void tongchantrenbien(int a[MAX][MAX],int m,int n)
{
	int tong=0,tong1=0,tong2,tong3=0;
	if(m!=1)
	{
		for(int i=0;i<m;i=i+m-1)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]%2==0)
					tong+=a[i][j];
			}
		}
		for(int i=1;i<m-1;i++)
		{
			for(int j=0;j<n;j=j+n-1)
			{
				if(a[i][j]%2==0)
					tong1+=a[i][j];
			}
		}
		tong2=tong+tong1;
		printf("\nTong tat ca cac phan tu chan nam tren bien cua ma tran la:%d",tong2);
	}
	if(m==1)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]%2==0)
					tong3+=a[i][j];
			}
		}
		printf("\nTong tat ca cac phan tu chan nam tren bien cua ma tran la:%d",tong3);
	}
}
void main()
{
	int a[MAX][MAX],n,m,tieptuc;
	quaylai:nhapmatranvuong(a,m,n);
	printf("\n>>>>>>>>>>>>>>>>>>>>MA TRAN VUA NHAP:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatranvuong(a,m,n);
	tongchantrenbien(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}