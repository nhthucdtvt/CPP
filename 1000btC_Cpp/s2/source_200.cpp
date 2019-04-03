
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 100
#define bool
void nhapmang(int a[MAX],int &n)
{
	do{
		printf("Nhap vao so phan tu cua mang:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("So phan tu ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1||n>MAX);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void kiemtra(int a[MAX],int n)
{
	int Co,tong,max=INT_MIN;
	bool Co=false;
	for(int i=0;i<n;i++)
	{
		tong=0;
		for(int k=1;k<a[i];k++)
		{
			if(a[i]%k==0)
			{
				tong+=k;
			}
		}
		if(tong==a[i]&&tong>max)
		{
			max=tong;
			Co=true;
		}
	}
	if(Co==true)
	{
		if(max>256)
			printf("\n0");
		else
			printf("\n1");
	}
	else
		printf("\nMang nay khong ton tai so hoan thien\n");
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	kiemtra(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}