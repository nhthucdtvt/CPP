
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 10
// Hàm nhập vào số nguyên dương .
void NhapSoNguyenDuong(int &n)
{
	quaylai:printf("\nNhap vao so nguyen duong:n=");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ để quay lại,chức năng tương tự như vòng lặp .
	}
}
// Hàm đảo ngược chữ số .
void DaoNguocChuSo(int a[],int n)
{
	int i=0;
	if(n!=0)
	{
		while(n!=0)
		{
			a[i]=n%10;
			n=n/10;
			i++;
		}
		for(int k=0;k<i;k++)
		{
			printf("%d",a[k]);
		}
	}
	else if(n==0)
	{
		printf("%d",n);
	}
}
// Hàm chính .
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapSoNguyenDuong(n);
	printf("\n>>>>>>>>>>>So Dao Nguoc Lai La:<<<<<<<<<<<<<<<<<\n");
	DaoNguocChuSo(a,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); // Xóa hết mọi dữ liệu cũ đã thực thi trước đó để bắt đầu lần thực thi mới .
		goto quaylai; // Dùng hợp ngữ để quay lại,chức năng tương tự như vòng lặp .
	}
}