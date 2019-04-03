
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
// Hàm nhập mảng các số nguyên .
void NhapMang(int *a,int n)
{
	printf("\nNhap vao a[0]=");
	scanf("%d",&a[0]);
	for(int i=1;i<n;i++)
	{
		quaylai:printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]==a[j])
			{
				printf("\nDa co phan tu trung nhau ! Xin vui long nhap lai!");
				goto quaylai;
			}
		}
	}
}
// Hàm xuất mảng các số nguyên .
void XuatMang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm chính .
void main()
{
	int *a,n,tieptuc;
	quaylai:printf("\nNhap vao so luong phan tu cua mang:");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nSo luong phan tu khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	a=(int *)malloc(n*sizeof(int)); // Khởi tạo bộ nhớ cần sử dụng .
	NhapMang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>>>>> Mang Vua Nhap La <<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	free(a); // Giải phóng bộ nhớ .
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc! ");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}