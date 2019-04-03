
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatran(float a[MAX][MAX],int &m,int &n)
{
	do{
	printf("Nhap vao so dong:m=");
	scanf("%d",&m);
	if(m<1||m>MAX)
	printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
	else
	break;
	}while(m<1||m>MAX);
	do{
	printf("Nhap vao so cot:n=");	
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
			scanf("%f",&a[i][j]);
		}
	}
}
void xuatmatran(float a[MAX][MAX],int m,int n)
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
float tinhtongtamgiactrenduongcheochinh(float a[MAX][MAX],int m,int n)
{
	float tong=0;
	for(int i=0;i<m-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			tong+=a[i][j];
		}
	}
	return tong;
}
float tinhtongtamgiactrenduongcheophu(float a[MAX][MAX],int m,int n)
{
	float tong=0;
	for(int i=0;i<m-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			tong+=a[i][j];
		}
	}
	return tong;
}
void main()
{
	float a[MAX][MAX];
	int m,n,tieptuc;
	quaylai:nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	float s=tinhtongtamgiactrenduongcheochinh(a,m,n);
	float s1=tinhtongtamgiactrenduongcheophu(a,m,n);
	printf("Tong cac phan tu thuoc ma tran tam giac tren duong cheo chinh la la:%f\n",s);
	printf("Tong cac phan tu thuoc ma tran tam giac tren duong cheo phu la:%f\n",s1);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ?Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc !\n ");
	tieptuc=getch();
	if(tieptuc=='C'||tieptuc=='c')
		goto quaylai;
}
	