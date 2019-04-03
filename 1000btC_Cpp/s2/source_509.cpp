
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
// Hàm nhập số .
void NhapSo(int &n)
{
	quaylai:printf("\nNhap vao so nguyen co 3 chu so:n=");
	scanf("%d",&n);
	if(n<=0||n>=1000)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ . Chức năng tương tự như vòng lặp .
	}
}
// Hàm đọc số .
void DocSo(int n)
{
	int a=n%10;
	int b=n/10;
	int c=b%10;
	int d=b/10;
	if(d==0)
		printf(" ");
	else if(d==1)
		printf("Mot Tram ");
	else if(d==2)
		printf("Hai Tram ");
	else if(d==3)
		printf("Ba Tram ");
	else if(d==4)
		printf("Bon Tram ");
	else if(d==5)
		printf("Nam Tram ");
	else if(d==6)
		printf("Sau Tram ");
	else if(d==7)
		printf("Bay Tram ");
	else if(d==8)
		printf("Tam Tram ");
	else if(d==9)
		printf("Chin Tram ");
	if(c==0)
		printf("Le ");
	else if(c==1)
		printf("Muoi ");
	else if(c==2)
		printf("Hai muoi ");
	else if(c==3)
		printf("Ba muoi ");
	else if(c==4)
		printf("Bon muoi ");
	else if(c==5)
		printf("Nam muoi ");
	else if(c==6)
		printf("Sau muoi ");
	else if(c==7)
		printf("Bay muoi ");
	else if(c==8)
		printf("Tam muoi ");
	else if(c==9)
		printf("Chin muoi ");
	if(a==0)
		printf(" ");
	else if(a==1)
		printf("Mot");
	else if(a==2)
		printf("Hai");
	else if(a==3)
		printf("Ba");
	else if(a==4)
		printf("Bon");
	else if(a==5)
		printf("Nam");
	else if(a==6)
		printf("Sau");
	else if(a==7)
		printf("Bay");
	else if(a==8)
		printf("Tam");
	else if(a==9)
		printf("Chin");
}
// Hàm chính .
void main()
{
	int n,tieptuc;
	quaylai:NhapSo(n);
	DocSo(n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng xóa mọi dữ liệu đã làm trước đó .
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp . Chức năng tương tự như vòng lặp .
	}
}