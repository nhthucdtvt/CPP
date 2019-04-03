
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
void Xoa(int a[MAX][MAX],int n,int &m)
{
	int x,i,j;
	do{
	printf("Nhap chi so dong ban muon xoa:x=");
	scanf("%d", &x);
	if(x<0||x>m-1)
		printf("\nDong ban can xoa khong hop le!Xin vui long nhap lai!\n");
	else
		break;
	}while(x<0||x>m-1);
	for(i=x;i<m-1;i++ )
	{
		for (j=0; j<n;j++)
		{
			a[i][j] = a[i+1][j];
		}
	}
	m--;
}
void main()
{
	int a[MAX][MAX],n,m,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>>MA TRAN SAU KHI XOA :<<<<<<<<<<<<<<<<<<<<\n");
	Xoa(a,n,m);
	xuatmatran(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}