
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
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int *a,int n)
{
	int dem=0,dem1=0;
	float tongduong=0,tongam=0;
	float tichchan=1,tichle=1;
	float trungbinhcongduong,trungbinhcongam,trungbinhtichchan,trungbinhtichle;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			tongduong+=a[i];
			dem++;
		}
		else
		{
			tongam+=a[i];
		}
		if(a[i]%2==0)
		{
			tichchan*=a[i];
			dem1++;
		}
		else
		{
			tichle*=a[i];
		}
	}
	if(dem!=0)
	{
		trungbinhcongduong=tongduong/dem;
		printf("\nTrung binh cong cac so duong la:%f",trungbinhcongduong);
	}
	else if(dem==0)
	{
		printf("\nMang nay khong ton tai so duong nen khong the tinh trung binh cong duoc ! ");
	}
	if(dem!=n)
	{
		trungbinhcongam=tongam/(n-dem);
		printf("\nTrung binh cong cac so am la:%f",trungbinhcongam);
	}
	else if(dem==n)
	{
		printf("\nMang nay khong ton tai so am nen khong the tinh trung binh cong duoc ! ");
	}
	if(dem1!=0)
	{
		trungbinhtichchan=tichchan/dem1;
		printf("\nTrung binh tich cac so chan la:%f",trungbinhtichchan);
	}
	else if(dem1==0)
	{
		printf("\nMang nay khong ton tai so chan nen khong the tinh trung binh tich duoc ! ");
	}
	if(dem1!=n)
	{
		trungbinhtichle=tichle/(n-dem1);
		printf("\nTrung binh tich cac so le la:%f",trungbinhtichle);
	}
	else if(dem1==n)
	{
		printf("\nMang nay khong ton tai so le nen khong the tinh trung binh tich duoc ! ");
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
	XuLyDuLieu(a,n);
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