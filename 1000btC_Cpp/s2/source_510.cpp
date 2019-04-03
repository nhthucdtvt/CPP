
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
// Hàm nhập số M .
void NhapM(int &M)
{
	quaylai:printf("\nNhap vao M=");
	scanf("%d",&M);
	if(M<2)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int M)
{
	int n=0,s=0;
	do{
		n++;
		s+=n;
	}while(s+n+1<M);
	printf("\nSo n lon nhat thoa 1+2+3+...+n < M la:%d",n);
}
// Hàm chính .
void main()
{
	int M,n,tieptuc;
	quaylai:NhapM(M);
	XuLyDuLieu(M);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
