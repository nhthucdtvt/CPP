
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
int tinhtichmatranA(int a[MAX][MAX],int n,int m)
{
	int tich=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			tich*=a[i][j];
		}
	}
	printf("\nTich cac phan tu cua ma tran A la:%d",tich);
	return tich;
}
int tinhtichmatranB(int b[MAX][MAX],int r,int c)
{
	int tich1=1;
	for(int k=0;k<r;k++)
	{
		for(int l=0;l<c;l++)
		{
			tich1*=b[k][l];
		}
	}
	printf("\nTich cac phan tu cua ma tran B la:%d",tich1);
	return tich1;
}
void main()
{
	int a[MAX][MAX],b[MAX][MAX],n,m,r,c,tieptuc;
	quaylai:nhap2matranvuong(a,b,n,m,r,c);
	xuat2matranvuong(a,b,n,m,r,c);
	int s=tinhtichmatranA(a,n,m);
	int s1=tinhtichmatranB(b,r,c);
	int s2=s*s1;
	printf("\nTich cua 2 ma tran A va B la:%d",s2);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}