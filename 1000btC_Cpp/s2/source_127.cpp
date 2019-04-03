
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
// Hàm trả về giá trị lớn nhất của mảng .
int TimSoLonNhatCuaMang(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}
// Hàm tìm bội chung nhỏ nhất của mảng .
int BCNN(int a[],int n,int max)
{
	int boiso=max;
	for (int i=0;i<n;i++)
	{
		if (boiso%a[i]!=0)
		{
			boiso+=max;
			i=-1;
		}
	}
	return boiso;
}
// Hàm chính .
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	int max=TimSoLonNhatCuaMang(a,n);
	int s=BCNN(a,n,max);
	printf("\nBCNN cua cac phan tu la:%d",s);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}