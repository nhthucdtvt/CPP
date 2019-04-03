
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define bool
void kiemtra(int &n)
{
	int Co;
	bool Co=false;
	do{
		printf("Nhap vao n(n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
	double sqrt(double x);// Dòng này để khai báo cho sqrt.
	for(int i=0;i<=n;i++)
	{
		if(sqrt (n)==i)
			Co=true;
	}
	if(Co==true)
		printf("\nSo %d la so chinh phuong",n);
	else
		printf("\nSo %d khong phai la so chinh phuong",n);
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