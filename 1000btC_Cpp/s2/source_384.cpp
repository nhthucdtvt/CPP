
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatranvuong(float a[MAX][MAX],int &m,int &n)
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
			scanf("%f",&a[i][j]);
		}
	}
}
void xuatmatranvuong(float a[MAX][MAX],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%16f",a[i][j]);
		}
		printf("\n");
	}
}
void tongduongcheochinh(float a[MAX][MAX],int m,int n)
{
	float tong=0;
	for(int i=0;i<m;i++)
	{
		tong+=a[i][i];
	}
	printf("\nTong cac phan tu tren duong cheo chinh la:%f",tong);
}
void main()
{
	float a[MAX][MAX];
	int n,m,tieptuc;
	quaylai:nhapmatranvuong(a,m,n);
	printf("\n>>>>>>>>>>>>>>>>>>>>MA TRAN VUA NHAP:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatranvuong(a,m,n);
	tongduongcheochinh(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}