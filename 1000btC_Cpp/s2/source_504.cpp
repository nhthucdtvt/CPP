
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập vào số nguyên lớn .
void NhapN(long &n)
{
	printf("\nNhap Vao So Nguyen : ");
	scanf("%ld",&n);
}
// Hàm xuất ra số nguyên .
void XuatN(long n)
{
	printf("So Ban Vua Nhap Vao La:%ld",n);
}
// Hàm trả về giá trị từng chữ số của số vừa nhập và được lưu vào trong mảng 1 chiều .
int XuLyDuLieu(int a[],long n)
{
	int i=0;
	while(n!=0)
	{
		a[i]=n%10;
		n=n/10;
		i++;
	}
	return i;
}
// Hàm liệt kê các chữ số .
void LietKeCacChuSo(int a[],long n)
{
	int s=XuLyDuLieu(a,n);
	printf("\nCac Chu So Cua So %ld La:",n);
	for(int k=s-1;k>=0;k--)
	{
		printf("%4d",a[k]);
	}
}
// Hàm tìm chữ số đầu tiên .
void ChuSoDauTien(int a[],long n)
{
	int s=XuLyDuLieu(a,n);
	printf("\nChu So Dau Tien Cua %ld La:%d",n,a[s-1]);
}
// Hàm tính tổng tất cả các chữ số .
void TongCacChuSo(int a[],long n)
{
	int s=XuLyDuLieu(a,n);
	int tong=0;
	for(int k=s-1;k>=0;k--)
	{
		tong+=a[k];
	}
	printf("\nTong Cac Chu So Cua So %ld La:%d",n,tong);
}
// Hàm tìm chữ số lớn nhất .
void ChuSoLonNhat(int a[],long n)
{
	int s=XuLyDuLieu(a,n);
	int max=a[0];
	for(int k=1;k<s;k++)
	{
		if(a[k]>max)
		{
			max=a[k];
		}
	}
	printf("\nChu So Lon Nhat Cua So %ld La:%d",n,max);
}
// Hàm đếm số lượng chữ số .
void DemSoChuSo(int a[],long n)
{
	int s=XuLyDuLieu(a,n);
	printf("\nSo Luong Cac Chu So Cua So %ld La:%d",n,s);
}
// Hàm hoán vị 2 số nguyên .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm kiểm tra xem các chữ số có khác nhau đôi một hay không ?
void KiemTraChuSoKhacNhauDoiMot(int a[],long n)
{
	int s=XuLyDuLieu(a,n);
	int dem=0;
	// Sắp mảng tăng dần bằng thuật toán Interchange Sort .
	for(int k=0;k<s;k++)
	{
		for(int l=k+1;l<s;l++)
		{
			if(a[k]>a[l])
			{
				HoanVi(a[k],a[l]);
			}
		}
	}
	// Đặt điều kiện .
	printf("\nSo %ld Co Cac Chu So Khac Nhau Doi Mot Hay Khong ? ",n);
	for(int k=1;k<s;k++)
	{
		if(a[k]!=a[k-1])
		{
			dem++;
		}
	}
	if(dem==s-1)
	{
		printf("\nYES");
	}
	else
	{
		printf("\nNO");
	}
}
// Hàm MeNu .
void MeNu()
{
	int a[MAX];
	long n,tieptuc;
	quaylai:NhapN(n);
	printf("\n");
	XuatN(n);
	printf("\n");
	LietKeCacChuSo(a,n);
	printf("\n");
	ChuSoDauTien(a,n);
	printf("\n");
	TongCacChuSo(a,n);
	printf("\n");
	ChuSoLonNhat(a,n);
	printf("\n");
	DemSoChuSo(a,n);
	printf("\n");
	KiemTraChuSoKhacNhauDoiMot(a,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
// Hàm chính .
void main()
{
	MeNu();
}