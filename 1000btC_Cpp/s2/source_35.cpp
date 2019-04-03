
#include<stdio.h>
#include<conio.h>
void nhapgiatri(int &n)
{
	do{
		printf("Nhap vao so nguyen duong (n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
}
void xulydulieu(int n)
{
	int k=0;
	int s=0;
	do{
		k=k+1;
		s=s+k;
	}while(s+k+1<n);
	printf("\nGia tri k can tim la:%d",k);
}
void main()
{
	int n,tieptuc;
	quaylai:nhapgiatri(n);
	xulydulieu(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}