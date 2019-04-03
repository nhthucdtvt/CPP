
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
void nhapmang (int a[MAX],int &n)
{
	do{
	printf("Nhap vao so phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
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
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void lietke(int a[MAX],int n)
{
	int Co;
	bool Co=false;
	int dem,demb=0,demc=0,demd=0,deme=0,demf=0;
	printf("Cac gia tri trong mang co chu so dau tien la chu so le la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]>=-9&&a[i]<=9)
		{
			int b=a[i]%10;
			if(b%2!=0)
			{
				printf("%4d",a[i]);
				demb++;
				Co=true;
			}
		}
		if(a[i]>=-99&&a[i]<=-10||a[i]>=10&&a[i]<=99)
		{
			int c=a[i]/10;
			if(c%2!=0)
			{
				printf("%4d",a[i]);
				demc++;
				Co=true;
			}
		}
		if(a[i]>=-999&&a[i]<=-100||a[i]>=100&&a[i]<=999)
		{
			int d=a[i]/100;
			if(d%2!=0)
			{
				printf("%4d",a[i]);
				demd++;
				Co=true;
			}
		}
		if(a[i]>=-9999&&a[i]<=-1000||a[i]>=1000&&a[i]<=9999)
		{
			int e=a[i]/1000;
			if(e%2!=0)
			{
				printf("%4d",a[i]);
				deme++;
				Co=true;
			}
		}
		if(a[i]>=-99999&&a[i]<=-10000||a[i]>=10000&&a[i]<=99999)
		{
			int f=a[i]/10000;
			if(f%2!=0)
			{
				printf("%4d",a[i]);
				demf++;
				Co=true;
			}
		}
	}
	dem=demb+demc+demd+deme+demf;
	if(Co==true)
	printf("\nTrong mang co ton tai %d gia tri thoa yeu cau de bai",dem);
	else
	printf("\nKhong co gia tri nao trong mang thoa man yeu cau de bai");
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietke(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}