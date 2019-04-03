
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
// Hàm xóa 1 phần tử tại vị trí k .
void Xoa(int *a,int &n,int k)
{
	for(int i=k;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}
// Hàm xóa tất cả các phần tử trùng nhau trong mảng .
void XoaCacPhanTuTrungNhau(int *a,int &n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]==a[j])
			{
				Xoa(a,n,i);
				i--;
			}
		}
	}
}
// Hàm chính .
void main()
{
	int *a,n,tieptuc;
	quaylai:printf("\nNhap vao so luong cac phan tu cua mang:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong cac phan tu khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	a=(int *)malloc(n*sizeof(int));
	NhapMang(a,n);
	printf("\n>>>>>>>>>>>>>>>> Mang Vua Nhap La <<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	XoaCacPhanTuTrungNhau(a,n);
	printf("\n>>>>>>>>>>>>>>>> Mang Sau Khi Xoa Di Cac Phan Tu Trung Nhau La <<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	free(a);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}