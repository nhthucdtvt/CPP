
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm Nhập Mảng .
void NhapMang(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
// Hàm Xuất Mảng .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm Hoán Vị .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm Sắp Xếp Mảng Tăng Dần .
void SapXepMangTangDan(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				HoanVi(a[i],a[j]);
			}
		}
	}
}
// Hàm Liệt Kê Và Tính Tần Suất Xuất Hiện Của Các Gía Trị Phân Biệt .
void LietKeVaTinhTanSuatXuatHienCuaCacGiaTriPhanBiet(int a[],int b[],int n)
{
	int dem=1,j=1;
	printf("\nCac Gia Tri Phan Biet Trong Mang La:");
	printf("%4d",a[0]); // In ra trước phần tử gốc a[0] .
	for(int i=1;i<n;i++)
	{
		b[0]=a[0]; // Gán phần tử đầu tiên của mảng b là phần tử gốc giá trị phân biệt đầu tiên .
		if(a[i]!=a[i-1])
		{
			printf("%4d",a[i]); // In ra các giá trị phân biệt trong mảng a .
			dem++; // Đếm số lượng các giá trị phân biệt .
			b[j++]=a[i]; // Đưa các giá trị phân biệt trong mảng a vào mảng b .
		}
	}
	printf("\n");
	printf("\nSo luong cac gia tri phan biet la:%d",dem); // Xuất ra số lượng các giá trị phân biệt trong mảng a .
	printf("\n");
	for(j=0;j<dem;j++)
	{
		int dem1=0; // Khởi tạo biến dem1=0 .
		for(int i=0;i<n;i++)
		{
			if(b[j]==a[i])
			{
				dem1++; // Với mỗi lần bằng nhau thì tăng biến dem1 lên 1 đơn vị .
			}
		}
		printf("\nTan Suat Xuat Hien Cua Phan Tu: \t%d\tLa:\t%d",b[j],dem1); // Xuất ra tần suất xuất hiện của các giá trị phân biệt .
	}
}
// Hàm Chính .
void main()
{
	int a[MAX],b[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapXepMangTangDan(a,n);
	LietKeVaTinhTanSuatXuatHienCuaCacGiaTriPhanBiet(a,b,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}