
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
void hoanvi2cot(int a[MAX][MAX],int n,int m,int &cot1,int &cot2)
{
	do{
		printf("\nNhap vao cot can hoan vi thu 1:cot1=");
		scanf("%d",&cot1);
		if(cot1<0||cot1>n-1)
			printf("\nSo cot ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(cot1<0||cot1>n-1);
	do{
		printf("\nNhap vao cot can hoan vi thu 2:cot2=");
		scanf("%d",&cot2);
		if(cot2<0||cot2>n-1)
			printf("\nSo cot ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(cot2<0||cot2>n-1);
	for(int i=0;i<m;i++)
	{
		int temp=a[i][cot1];
		a[i][cot1]=a[i][cot2];
		a[i][cot2]=temp;
	} 
}
void main()
{
	int a[MAX][MAX],n,m,cot1,cot2,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	printf(">>>>>>>>>>>>>>>>>>MA TRAN SAU KHI HOAN VI:<<<<<<<<<<<<<<<<<<<<<<<\n");
	hoanvi2cot(a,n,m,cot1,cot2);
	xuatmatran(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}