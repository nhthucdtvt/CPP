
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập mảng các số nguyên .
void NhapMang(int a[],int &n,int &k)
{
	quaylai:printf("\nNhap vao so luong cac phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp .
	}
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
	quaylai1:printf("\nNhap vao so k=");
	scanf("%d",&k);
	if(k<1)
	{
		printf("\nSo k ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp .
	}
}
// Hàm xuất mảng các số nguyên .
void XuatMang(int a[],int n,int k)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm hoán vị 2 số nguyên .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm sắp mảng tăng dần bằng thuật toán Interchange Sort .
void SapMangTangDan(int a[],int n,int k)
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
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int a[],int b[],int n,int k)
{
	int dem=1,j=1; // Khởi tạo biến đếm = 1 và j = 1 .
	b[0]=a[0]; // Lưu giá trị đầu tiên của mảng a vào mảng b .
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			dem++; // Biến đếm tăng lên khi nhận được giá trị phân biệt .
			b[j++]=a[i]; // Lưu giá trị phân biệt vào mảng b .
		}
	}
	printf("\n>>>>>>>>>>Cac Gia Tri Phan Biet Co Trong Mang:<<<<<<<<<<<<<<<<\n");
	// Mảng b lúc này đang chứa các giá trị phân biệt của mảng a và đã được sắp xếp tăng dần .
	for(int j=0;j<dem;j++)
	{
		printf("%4d",b[j]); // Xuất ra mảng b .
	}
	printf("\n");
	if(k<=dem)
	{
		printf("\nSo hang lon thu %d la:%d",k,b[dem-k]);
	}
	else if(k>dem)
	{
		printf("\nKhong ton tai so hang lon thu %d",k);
	}
}
// Hàm chính .
void main()
{
	int a[MAX],b[MAX],n,k,tieptuc;
	quaylai:NhapMang(a,n,k);
	printf("\n>>>>>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n,k);
	printf("\n");
	SapMangTangDan(a,n,k);
	XuLyDuLieu(a,b,n,k);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); // Xóa hết mọi dữ liệu đã thực thi trước đó để bắt đầu lần thực thi mới .
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp .
	}
}
