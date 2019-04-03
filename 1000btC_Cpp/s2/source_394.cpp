
#include<stdio.h>
#include<conio.h>
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
		if(n!=m)
			printf("So cot ban nhap vao khong thoa tinh chat la ma tran vuong!Xin vui long nhap lai!\n");
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
void tamgiactrenduongcheochinh(int a[MAX][MAX],int m,int n)
{
	int dem=0;
	for(int i=0;i<m-1;i++)
	{
		for(int j=m-1;j>i;j--)
		{
			if(a[i][j]%2==0)
				dem++;
		}
	}
	printf("So luong gia tri chan trong ma tran tam giac tren duong cheo chinh la:%d\n",dem);
}
void tamgiactrenduongcheophu(int a[MAX][MAX],int m,int n)
{
	int dem=0;
	for(int i=0;i<m-1;i++)
	{
		for(int j=0;j<=n-2-i;j++)
		{
			if(a[i][j]%2==0)
				dem++;
		}
	}
	printf("So luong gia tri chan trong ma tran tam giac tren duong cheo phu la:%d\n",dem);
}
void main()
{
	int a[MAX][MAX],m,n,dem,tieptuc;
	quaylai:nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	tamgiactrenduongcheochinh(a,m,n);
	tamgiactrenduongcheophu(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}