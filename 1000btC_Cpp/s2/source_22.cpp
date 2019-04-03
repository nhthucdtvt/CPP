
#include<stdio.h>
#include<conio.h>
void kiemtra(int &n)
{
	int f;
	do{
		printf("Nhap vao n(n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
		f=1;
		if(n<2)
			f=0;
		for(int k=2;k<=n/2;k++)
		{
			if(n%k==0)
				f=0;
		}
		if(f==1)
			printf("\nSo %d la so nguyen to",n);
		else
			printf("\nSo %d khong phai la so nguyen to",n);
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