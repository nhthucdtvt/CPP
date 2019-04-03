
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 100
#define bool
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
void timnguyentolonnhat(int a[MAX][MAX],int m,int n)
{
	int max=INT_MIN,f,dem=0,Co;
	bool Co=false;
	printf("\nCac so nguyen to co trong ma tran la:");
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
				dem++;
				if(a[i][j]>max)
				{
					max=a[i][j];
					Co=true;
				}
			}
		}
	}
	printf("\nSo luong cac so nguyen to co trong ma tran la:%d",dem);
	if(Co==true)
	printf("\nSo nguyen to lon nhat la:%d",max);
	else
	printf("\nTrong ma tran khong ton tai so nguyen to");
}
void main()
{
	int a[MAX][MAX],n,m,tieptuc;
	quaylai:nhapmatranvuong(a,m,n);
	printf("\n>>>>>>>>>>>>>>>>>>>>MA TRAN VUA NHAP:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatranvuong(a,m,n);
	timnguyentolonnhat(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
