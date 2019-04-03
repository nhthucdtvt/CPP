
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
	for(int i=0;i<n;i++)
	{
		quaylai1:printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
		if(a[i]<1)
		{
			printf("\nGia tri ban nhap vao khong hop le!Xin vui long nhap lai!");
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
// Hàm trả về giá trị nhỏ nhất của mảng .
int TimSoNhoNhatCuaMang(int a[],int n)
{
	int min=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	return min;
}
// Hàm kiểm tra ước chung của các giá trị trong mảng .
bool KiemTraUocChung(int a[],int n,int UocSo)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]%UocSo!=0)
		{
			return false;
		}
	}
	return true;
}
// Hàm trả về ước chung lớn nhất của các phần tử trong mảng .
int UCLN(int a[],int n)
{
	for(int UocSo=TimSoNhoNhatCuaMang(a,n);UocSo>=1;UocSo--)
	{
		if(KiemTraUocChung(a,n,UocSo)==true) // nếu đúng thì trả về ước số .
		{
			return UocSo;
		}
	}
	return 1; // nếu sai thì trả về giá trị là 1 .
}
// Hàm chính .
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	int s=UCLN(a,n);
	printf("\nUCLN cua cac phan tu la:%d",s);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}