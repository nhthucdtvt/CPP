
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 10
void NhapSo(int &n)
{
	printf("\nNhap vao so nguyen:");
	scanf("%d",&n);
}
void KiemTraDoiXung(int a[],int n)
{
	int i=0,dem=0;
	if(n>=0)
	{
		while(n!=0)
		{
			a[i]=n%10;
			n=n/10;
			i++;
		}
		for(int k=0;k<i/2;k++)
		{
			if(a[k]==a[i-1-k])
			{
				dem++;
			}
		}
		if(dem==i/2)
		{
			printf("\nYES");
		}
		else
		{
			printf("\nNO");
		}
	}
	else if(n<0)
	{
		printf("\nNO");
	}
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapSo(n);
	printf("\n>>>>>>>>>>>>So %d Co Phai La So Doi Xung ? <<<<<<<<<<<<<<<<<<<\n",n);
	KiemTraDoiXung(a,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}