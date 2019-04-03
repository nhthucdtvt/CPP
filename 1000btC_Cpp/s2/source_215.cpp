
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập mảng các số thực .
void NhapMang(float a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp . Chức năng tương tự như vòng lặp .
	}
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%f",&a[i]);
	}
}
// Hàm xuất mảng các số thực .
void XuatMang(float a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\t%.2f",a[i]);
	}
}
// Hàm hoán vị 2 số thực .
void HoanVi(float &x,float &y)
{
	float temp=x;
	x=y;
	y=temp;
}
// Hàm sắp mảng tăng dần tại các vị trí lẻ .
void SapTangDanTaiViTriLe(float a[],int n)
{
	for(int i=1;i<n-1;i=i+2)
	{
		for(int j=i+2;j<n;j=j+2)
		{
			if(a[i]>a[j])
			{
				HoanVi(a[i],a[j]);
			}
		}
	}
}
// Hàm chính .
void main()
{
	int n,tieptuc;
	float a[MAX];
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>>>Mang Ban Dau La:<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	XuatMang(a,n);
	SapTangDanTaiViTriLe(a,n);
	printf("\n>>>>>>>>>>>>>>Mang Sau Khi Sap Tang Tai Cac Vi Tri Le:<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	XuatMang(a,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng xóa mọi dữ liệu đã làm trước đó .
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp . Chức năng tương tự như vòng lặp .
	}
}