
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhap2matranvuong(int a[MAX][MAX],int b[MAX][MAX],int &n,int &m,int &r,int &c)
{
	do{
		printf("Nhap vao so dong cua ma tran A:m=");
		scanf("%d",&m);
		if(m<1||m>MAX)
			printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(m<1||m>MAX);
	do{
		printf("Nhap vao so cot cua ma tran A:n=");
		scanf("%d",&n);
		if(n!=m)
			printf("So cot ban nhap vao khong thoa tinh chat la ma tran vuong (n==m)!Xin vui long nhap lai!\n");
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
	do{
		printf("Nhap vao so dong cua ma tran B:r=");
		scanf("%d",&r);
		if(r<1||r>MAX)
			printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(r<1||r>MAX);
	do{
		printf("Nhap vao so cot cua ma tran B:c=");
		scanf("%d",&c);
		if(c!=r)
			printf("So cot ban nhap vao khong thoa tinh chat la ma tran vuong (c==r)!Xin vui long nhap lai!\n");
		else
			break;
	}while(c!=r);
	for(int k=0;k<r;k++)
	{
		for(int l=0;l<c;l++)
		{
			printf("Nhap vao b[%d][%d]=",k,l);
			scanf("%d",&b[k][l]);
		}
	}
}
void xuat2matranvuong(int a[MAX][MAX],int b[MAX][MAX],int n,int m,int r,int c)
{
	printf("\n>>>>>>>>>>>>>>>>>>MA TRAN A VUA NHAP:<<<<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n>>>>>>>>>>>>>>>>>>MA TRAN B VUA NHAP:<<<<<<<<<<<<<<<<<<<<<<\n");
	for(int k=0;k<r;k++)
	{
		for(int l=0;l<c;l++)
		{
			printf("%4d",b[k][l]);
		}
		printf("\n");
	}
}
int tinhtongmatranA(int a[MAX][MAX],int n,int m)
{
	int tong=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			tong+=a[i][j];
		}
	}
	printf("\nTong cac phan tu cua ma tran A la:%d",tong);
	return tong;
}
int tinhtongmatranB(int b[MAX][MAX],int r,int c)
{
	int tong1=0;
	for(int k=0;k<r;k++)
	{
		for(int l=0;l<c;l++)
		{
			tong1+=b[k][l];
		}
	}
	printf("\nTong cac phan tu cua ma tran B la:%d",tong1);
	return tong1;
}
void main()
{
	int a[MAX][MAX],b[MAX][MAX],n,m,r,c,tieptuc;
	quaylai:nhap2matranvuong(a,b,n,m,r,c);
	xuat2matranvuong(a,b,n,m,r,c);
	int s=tinhtongmatranA(a,n,m);
	int s1=tinhtongmatranB(b,r,c);
	int s2=s-s1;
	int s3=s1-s;
	printf("\nHieu cua 2 ma tran A va B la:%d",s2);
	printf("\nHieu cua 2 ma tran B va A la:%d",s3);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}