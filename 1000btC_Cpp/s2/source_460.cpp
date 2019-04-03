
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
// Hàm nhập mảng các số nguyên .
void NhapMang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
// Hàm xuất mảng các số nguyên .
void XuatMang(int *a,int n)
{
	printf("\n>>>>>>>>>>>>>>> Mang Vua Nhap La <<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm kiểm tra cấp số cộng .
void KiemTraCapSoCong(int *a,int n)
{
	printf("\n>>>>>>>>>> Mang Co La Cap So Cong Khong ? <<<<<<<<<<<<<<\n");
	int dem=0;
	for(int i=2;i<n;i++)
	{
		if(a[i]-a[i-1]==a[1]-a[0])
		{
			dem++;
		}
	}
	if(dem==n-2)
	{
		printf("\nYES");
		printf("\nCong sai cap so cong la:%d",a[1]-a[0]);
	}
	else
	{
		printf("\nNO");
	}
}
// Hàm kiểm tra cấp số nhân .
void KiemTraCapSoNhan(int *a,int n)
{
	printf("\n>>>>>>>>>> Mang Co La Cap So Nhan Khong ? <<<<<<<<<<<<<<\n");
	int dem=0;
	for(int i=2;i<n;i++)
	{
		if((float)a[i]/a[i-1]==(float)a[1]/a[0])
		{
			dem++;
		}
	}
	if(dem==n-2)
	{
		printf("\nYES");
		printf("\nCong sai cap so nhan la:%f",(float)a[1]/a[0]);
	}
	else
	{
		printf("\nNO");
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
	XuatMang(a,n);
	KiemTraCapSoCong(a,n);
	printf("\n");
	KiemTraCapSoNhan(a,n);
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
