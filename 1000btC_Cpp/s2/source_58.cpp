
#include<stdio.h>
#include<conio.h>
#include<math.h>
void kiemtra(int &n)
{
	double log(double x);
	printf("Nhap vao n=");
	scanf("%d",&n);
	if(n<1)
		printf("\nSo %d khong co dang 3^k",n);
	else
	{
		float a=log(n)/log(3);
		if(a==floor(a)) //có thể dùng hàm làm tròn ceil cũng được.
			printf("\nSo %d co dang 3^k",n);
		else
			printf("\nSo %d khong co dang 3^k",n);
	}
}
void main()
{
	int n,tieptuc;
	quaylai:kiemtra(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}