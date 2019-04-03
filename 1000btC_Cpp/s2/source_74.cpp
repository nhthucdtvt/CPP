
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void NhapDuLieu(int &a,int &n)
{
	printf("a=");
	scanf("%d",&a);
	quaylai:printf("n=");
	scanf("%d",&n);
	if(n<0||n>31)
	{
		printf("\nGia tri n khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
	else
	{
		int b=a>>n;
		if(0x001&b)
			printf("\nBit la 1");
		else
			printf("\nBit la 0");
	}
}
void main()
{
	int a,n,tieptuc;
	quaylai:NhapDuLieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}