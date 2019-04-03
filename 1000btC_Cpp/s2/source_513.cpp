
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<Windows.h>
// Hàm nhập vào số n .
void NhapN(int &n)
{
	quaylai:printf("\nNhap vao n=");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
// Hàm tính giai thừa bằng đệ quy .
long giaithua(long x)
{
	if(x==0||x==1)
		return 1;
	return (x*giaithua(x-1));
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int n)
{
	float s=0;
	float sqrt(float x); // Khai báo định dạng của sqrt .
	for(int i=1;i<=n;i++)
	{
		s+=(i*giaithua(i+1))/((i+1)+sqrt(i+2));
	}
	printf("\nKet qua la:%f",s);
}
// Hàm chính .
void main()
{
	int n,tieptuc;
	quaylai:NhapN(n);
	XuLyDuLieu(n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}