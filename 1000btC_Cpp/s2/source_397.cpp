
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatranvuong(int a[MAX][MAX],int &n,int &m)
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
}
void xuatmatranvuong(int a[MAX][MAX],int n,int m)
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
void sapxeptangtrenduongcheochinh(int a[MAX][MAX],int n,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(a[i][i]>a[j][j])
			{
				int temp=a[i][i];
				a[i][i]=a[j][j];
				a[j][j]=temp;
			}
		}
	}
}
void main()
{
	int a[MAX][MAX],n,m,tieptuc;
	quaylai:nhapmatranvuong(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatranvuong(a,n,m);
	printf(">>>>>>>>>>>>>>>>>>MA TRAN SAU KHI SAP XEP:<<<<<<<<<<<<<<<<<<<<<<<\n");
	sapxeptangtrenduongcheochinh(a,n,m);
	xuatmatranvuong(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}