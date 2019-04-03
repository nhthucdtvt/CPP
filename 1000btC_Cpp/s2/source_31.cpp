
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<Windows.h>
void Nhapn(int &n)
{
	quaylai:printf("\nNhap vao gia tri n=");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
}
// Hàm tính giai thừa theo đệ quy.
double giaithua(double n)
{
	if(n==0||n==1)
		return 1;
	return (n*giaithua(n-1));
}
void XuLyDuLieu(int n)
{
	float s=sqrt(1.0);
	for(int i=2;i<=n;i++)
	{
		s=pow(1.0*(giaithua(i)+s),1.0/(i+1));
	}
	printf("\nKet qua la:%f",s);
}
void main()
{
	int n,tieptuc;
	quaylai:Nhapn(n);
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