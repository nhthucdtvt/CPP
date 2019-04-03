
#include<stdio.h>
#include<conio.h>
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
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
// Hàm xuất mảng các số nguyên .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
// Hàm nhập giá trị cần tìm kiếm .
void NhapGiaTrixCanTim(int &x)
{
	printf("\nNhap vao x=");
	scanf("%d",&x);
}
// Thuật toán LinearExhaustive
int TimKiemTuanTuVetCan(int a[],int n,int x)
{ 
	for(int i=0; i<n; i++)
	{ 
		if(a[i] == x)
		{ return i; 
		}
	} 
	return -1; 
}
// Thuật toán LinearSentinel
int TimKiemTuanTuLinhCanh(int a[],int n,int x)
{
	a[n]=x;
	for(int i=0;;i++)
	{
		if(a[i]==x)
			return i;
	}
}
// Hàm hoán vị .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm sắp xếp mảng tăng dần (hỗ trợ cho thuật toán BinarySearch) .
void SapXepTangDan(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				HoanVi(a[i],a[j]);
			}
		}
	}
}
// Thuật toán BinarySearch
int TimKiemNhiPhan(int a[], int n, int x)
{ 
	int l = 0, r = n-1; 
	while (l <= r)
	{ 
		int m = (l + r)/2; 
		if (a[m] == x)
		{ 
			return m; 
		} 
		else
		{ 
			if (x < a[m])
			{ 
				r=m-1;
			} 
			else
			{ 
				l = m + 1; 
			} 
		} 
	} 
	return -1; 
}
// Hàm MeNu .
void MeNu()
{
	int a[MAX],n,x,m,i,w;
	printf("\n");
	printf("\n---------------------MeNu-----------------------\n");
	do{
		// Bảng MeNu đưa ra các sự lựa chọn .
		printf("\n");
		printf("\n");
		printf("\n Moi ban lua chon cac yeu cau !");
		printf("\n");
		printf("\nNhap so ban chon roi nhan Enter de xac nhan!");
		printf("\n");
		printf("\n 1 - Tim Kiem Phan Tu Bang Thuat Toan LinearExhaustive ");
		printf("\n");
		printf("\n 2 - Tim Kiem Phan Tu Bang Thuat Toan LinearSentinel ");
		printf("\n");
		printf("\n 3 - Tim Kiem Phan Tu Bang Thuat Toan BinarySearch ");
		printf("\n");
		printf("\n 0 - Thoat Chuong Trinh ");
		printf("\n");
		printf("\n------------------------------------------------\n");
		printf("\n");
		printf("\n Moi ban nhap vao lua chon cua ban o day:");
		scanf("%d",&w);
		// Cấu trúc switch-case .
		switch(w)
		{
		case 1:
			{
				printf("\n>>>>>>Chao Mung Ban Den Voi Thuat Toan LinearExhaustive<<<<<<<\n");
				printf("\n");
				printf("\n");
				NhapMang(a,n);
				printf("\n>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<\n");
				XuatMang(a,n);
				NhapGiaTrixCanTim(x);
				i=TimKiemTuanTuVetCan(a,n,x);
				if(i==-1)
				{
					printf("\nKhong tim thay x trong mang a");
				}
				else
				{
					printf("\nVi Tri cua x trong mang a la:%d",i+1);
				}
				break;
			}
		case 2:
			{
				printf("\n>>>>>>Chao Mung Ban Den Voi Thuat Toan LinearSentinel<<<<<<<\n");
				printf("\n");
				printf("\n");
				NhapMang(a,n);
				printf("\n>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<\n");
				XuatMang(a,n);
				NhapGiaTrixCanTim(x);
				i=TimKiemTuanTuLinhCanh(a,n,x);
				if(i==-1)
				{
					printf("\nKhong tim thay x trong mang a");
				}
				else
				{
					printf("\nVi Tri cua x trong mang a la:%d",i+1);
				}
				break;
			}
		case 3:
			{
				printf("\n>>>>>>Chao Mung Ban Den Voi Thuat Toan BinarySearch<<<<<<<\n");
				printf("\n");
				printf("\n");
				NhapMang(a,n);
				printf("\n>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<\n");
				XuatMang(a,n);
				SapXepTangDan(a,n);
				printf("\n>>>>>>Mang Sau Khi Da Sap Xep Tang Dan La:<<<<<<\n");
				XuatMang(a,n);
				NhapGiaTrixCanTim(x);
				m=TimKiemNhiPhan(a,n,x);
				if(m==-1)
				{
					printf("\nKhong tim thay x trong mang a");
				}
				else
				{
					printf("\nVi Tri cua x trong mang a la:%d",m+1);
				}
				break;
			}
		}
			if(w==0)
			{
				printf("\nThanks You For Using The Program ! Goodbye And See You Later !\n"); 
				getch(); 
			}
	}while(w!=0);
}
// Hàm chính .
void main()
{
	MeNu();
}