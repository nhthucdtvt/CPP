
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
void tinhtichmotcot(int a[MAX][MAX],int n,int m,int &x)
{
	int s=1;
	do{
		printf("\nNhap vao so cot can tinh tich:x=");
		scanf("%d",&x);
		if(x<0||x>n-1)
			printf("\nSo cot ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(x<0||x>n-1);
	for(int i=0;i<m;i++)
	{
		if(a[i][x]%2==0)
			s*=a[i][x];
	}
	printf("\nTich cac gia tri chan tren cot:%d la:%d",x,s);
}
void main()
{
	int a[MAX][MAX],n,m,x,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	tinhtichmotcot(a,n,m,x);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}