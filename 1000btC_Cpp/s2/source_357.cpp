
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 100
#define bool
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
void xulydulieu(int a[MAX][MAX],int n,int m)
{
	int min=INT_MAX,dem=0,Co;
	bool Co=false;
	for(int i=0;i<m;i++) // vòng lặp đầu tiên này là để tìm ra giá trị chẵn nhỏ nhất.
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]%2==0&&a[i][j]<min)
				min=a[i][j];
		}
	}
	for(int i=0;i<m;i++)	// vòng lặp thứ hai này là để so sánh giá trị chẵn nhỏ nhất vừa tìm được với các giá trị trong mảng.
	{
		for(int j=0;j<n;j++)
		{
			if(min==a[i][j])	// ở đây cho a[i][j]==min thì kết quả cũng như nhau
				dem++;
		}
	}
	printf("\nSo luong gia tri chan nho nhat co trong ma tran la:%d",dem);
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
