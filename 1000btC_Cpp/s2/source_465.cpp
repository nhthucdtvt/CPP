
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
// Hàm trả về vị trí của phần tử nhỏ nhất trong mảng .
int ViTriMin(int *a,int n)
{
	int min=a[0],vitri=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			vitri=i;
		}
	}
	return vitri;
}
// Hàm xóa phần tử tại vị trí k .
void Delete(int *a,int &n,int k)
{
	for(int i=k;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
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
	printf("\n>>>>>>>>>>>>>>>>>>>>>> Mang Vua Nhap La <<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	int vitrimin=ViTriMin(a,n);
	Delete(a,n,vitrimin);
	printf("\n>>>>>>>>>>>>>>>>>>>>> Mang Sau Khi Xoa Di Phan Tu Nho Nhat La <<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
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
