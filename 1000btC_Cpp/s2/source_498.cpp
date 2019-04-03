
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void NhapSo(int &n)
{
	printf("\nNhap vao so nguyen:");
	scanf("%d",&n);
}
void KiemTraDoiXung(int n)
{
	int reverse = 0; // Số đảo ngược của n
	int temp = n; // Copy giá trị của n vào biến temp
	// 1. Đảo ngược số n
	while(temp > 0)
	{
		int digit = temp % 10;
		reverse = reverse * 10 + digit;
		temp = temp / 10;
	}
	// 2. Kiểm số đảo ngược của n có bằng n hay không?
	//	+ Nếu bằng, ta kết luận n là số đối xứng
	//	+ Ngược lại, n không phải là số đối xứng
	if(reverse == n)
	{
		printf("\nYES");
	}
	else
	{
		printf("\nNO");
	}
}
void main()
{
	int n,tieptuc;
	quaylai:NhapSo(n);
	printf("\n>>>>>>>>>>>>So %d Co Phai La So Doi Xung ? <<<<<<<<<<<<<<<<<<<\n",n);
	KiemTraDoiXung(n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
