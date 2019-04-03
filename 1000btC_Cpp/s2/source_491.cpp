
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
#define MAX 100
// Hàm nhập ma trận các số nguyên .
void NhapMaTran(int b[MAX][MAX],int &M,int &N)
{
	do{
		printf("\nNhap vao so dong cua ma tran:");
		scanf("%d",&M);
		if(M<1||M>MAX)
		{
			printf("\nSo dong khong hop le!Xin vui long nhap lai!");
		}
	}while(M<1||M>MAX);
	do{
		printf("\nNhap vao so cot cua ma tran:");
		scanf("%d",&N);
		if(N<1||N>MAX)
		{
			printf("\nSo cot khong hop le!Xin vui long nhap lai!");
		}
	}while(N<1||N>MAX);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("\nNhap vao a[%d][%d]=",i,j);
			scanf("%d",&b[i][j]);
		}
	}
}
// Hàm xuất ma trận các số nguyên .
void XuatMaTran(int b[MAX][MAX],int M,int N)
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%4d",b[i][j]);
		}
		printf("\n");
	}
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int b[MAX][MAX],int M,int N)
{
	int dem1=0;
	for(int i=0;i<M;i++)
	{
		int dem=0;
		for(int j=0;j<N;j++)
		{
			if(b[i][j]==1)
			{
				dem++;
			}
		}
		if(dem>=3)
		{
			printf("%4d",i);
			dem1++;
		}
	}
	printf("\n\nSo luong dong co chua it nhat 3 so 1 la:%d",dem1);
}
// Hàm chính .
void main()
{
	int b[MAX][MAX],M,N,tieptuc;
	quaylai:NhapMaTran(b,M,N);
	printf("\n>>>>>>>>>>>>>>> Ma Tran Vua Nhap La <<<<<<<<<<<<<<<<\n");
	XuatMaTran(b,M,N);
	printf("\n>>>>>>>>>>>>>>> Cac Dong Co Chua It Nhat 3 So 1 La <<<<<<<<<<<<<<<<<\n");
	XuLyDuLieu(b,M,N);
	printf("\n\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}