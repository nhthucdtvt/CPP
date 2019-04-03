
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
void kiemtratang(int a[MAX][MAX],int n,int m)
{
	int b[MAX];
	for(int i=0;i<m;i++)
	{
		int dem=0;
		for(int j=1;j<n;j++)
		{
			int c=a[i][j]-a[i][j-1];
			if(c>=0)
			{
				dem++;
				b[i]=dem;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(b[i]==n-1)
			printf("\nDong %d:YES",i);
		else
			printf("\nDong %d:NO",i);
	}
}
void main()
{
	int a[MAX][MAX],n,m,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>>CAC DONG TRONG MA TRAN CO TANG DAN KHONG ?<<<<<<<<<<<<<<<<<<<<\n");
	kiemtratang(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}