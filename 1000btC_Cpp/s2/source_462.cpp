
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
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm trả về số lượng các phần tử chẵn trong mảng a (cũng chính là số lượng các phần tử trong mảng b) .
int SoLuongPhanTuChan(int *a,int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			dem++;
		}
	}
	return dem;
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int *a,int *b,int n)
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			b[k++]=a[i];
		}
	}
}
// Hàm chính .
void main()
{
	int *a,*b,n,tieptuc;
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
	int dem=SoLuongPhanTuChan(a,n);
	b=(int *)malloc(dem*sizeof(int)); // Khởi tạo bộ nhớ cần sử dụng .
	XuLyDuLieu(a,b,n);
	printf("\n>>>>>>>>>>>>>>> Mang B Chua Cac Phan Tu Chan Cua Mang A La <<<<<<<<<<<<<<<<<<<\n");
	XuatMang(b,dem);
	free(a); // Giải phóng bộ nhớ .
	free(b); // Giải phóng bộ nhớ .
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc! ");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}