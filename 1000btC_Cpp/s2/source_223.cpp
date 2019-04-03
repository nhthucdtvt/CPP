
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập mảng các số nguyên .
void NhapMang(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	printf("\nNhap vao a[0]=");
	scanf("%d",&a[0]);
	printf("\n>>>>Chuong trinh chi cho phep phan tu tiep theo phai lon hon hoac bang phan tu lien truoc no:<<<<<<<<\n ");
	for(int i=1;i<n;i++)
	{
		quaylai1:printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])
		{
			printf("\nSo ban nhap khong hop le!Xin vui long nhap lai!");
			goto quaylai1;
		}
	}
}
// Hàm xuất mảng các số nguyên .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm chính .
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>Mang Duoc Sap Tang Dan:<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}