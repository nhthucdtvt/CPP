
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
// hàm hoán vị 2 phần tử
void hoanvi(int &x,int &y)	// phải để theo kiểu truyền tham biến vì 2 phần tử do mình nhập vào và gọi lại hàm hoanvi này.
{
	int temp=x;
	x=y;
	y=temp;
}
int tinhtongdong(int a[MAX][MAX],int n,int x)	// ta phải để kiểu int để 1 lát ở dưới ta gọi lại hàm tinhtongdong này.
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		tong+=a[x][i];
	}
	return tong;
}
void sapxeptheotongdong(int a[MAX][MAX],int n,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(tinhtongdong(a,n,i)>tinhtongdong(a,n,j))	// sắp xếp tăng dần
			{
				for(int k=0;k<n;k++)
					hoanvi(a[i][k],a[j][k]);
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
	sapxeptheotongdong(a,n,m);
	xuatmatranvuong(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}