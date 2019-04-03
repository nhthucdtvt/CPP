
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void NhapSoCanChuyenDoi(int &n)
{
	quaylai:printf("\nNhap vao so nguyen duong can chuyen doi:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
void NhapCoSoCanChuyenDoi(int &x)
{
	quaylai:printf("\nNhap vao co so can chuyen doi:");
	scanf("%d",&x);
	if(x!=2&&x!=8&&x!=16)
	{
		printf("\nCo so can chuyen doi khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
}
void ChuyenDoi(int n,int x)
{
	char a[100];
	int m=n,i=0,q,r,j;
	do
	{
		q=m/x;
		r=m%x;
		if(r>=10)
		{
			if(r==10) a[i]='A';
			else if(r==11) a[i]='B';
			else if(r==12) a[i]='C';
			else if(r==13) a[i]='D';
			else if(r==14) a[i]='E';
			else if(r==15) a[i]='F';
		}
		else
			a[i]=r+0x30;
		i++;
		m=q;
	}while(q!=0);
	for(i=i-1;i>=0;i--)
		printf("%c",a[i]);
	printf("\n");
}
void main()
{
	int n,x,tieptuc;
	quaylai:NhapSoCanChuyenDoi(n);
	NhapCoSoCanChuyenDoi(x);
	printf("\n>>>>>>>>>>>Chuyen Doi So %d Sang He %d La:<<<<<<<<<<<<<<\n",n,x);
	ChuyenDoi(n,x);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
