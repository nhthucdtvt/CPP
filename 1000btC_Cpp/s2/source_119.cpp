
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
void nhapmang(int a[MAX],int &n)
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
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
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
	int dem,demb=0,demc=0,deme=0,demj=0,demo=0;
	printf("Cac gia tri trong mang thoa tinh chat so ganh la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]>=-9&&a[i]<=9)
		{
				printf("%4d",a[i]);
				demb++;
				Co=true;
		}
		if(a[i]>=10&&a[i]<=99)
		{
			int c=a[i]/10;
			int d=a[i]%10;
			if(c==d)
			{
				printf("%4d",a[i]);
				demc++;
				Co=true;
			}
		}
		if(a[i]>=100&&a[i]<=999)
		{
			int e=a[i]/100;
			int g=a[i]%10;
			if(e==g)
			{
				printf("%4d",a[i]);
				deme++;
				Co=true;
			}
		}
		if(a[i]>=1000&&a[i]<=9999)
		{
			int j=a[i]/1000;
			int k=a[i]%10;
			int l=a[i]/10;
			int m=l%10;
			int z=a[i]/100;
			int t=z%10;
			if(j==k&&m==t)
			{
				printf("%4d",a[i]);
				demj++;
				Co=true;
			}
		}
		if(a[i]>=10000&&a[i]<=99999)
		{
			int o=a[i]/10000;
			int p=a[i]%10;
			int q=a[i]/10;
			int r=q%10;
			int s=a[i]/1000;
			int u=s%10;
			if(o==p&&r==u)
			{
				printf("%4d",a[i]);
				demo++;
				Co=true;
			}
		}
	}
	dem=demb+demc+deme+demj+demo;
	if(Co==true)
	printf("\nTrong mang co %d gia tri thoa man yeu cau de bai",dem);
	else
	printf("\nKhong co gia tri nao trong mang thoa man yeu cau de bai");
}
void dautien(int a[MAX],int n)
{
	int Co,vitri=0,i,Co1;
	bool Co=false;
	bool Co1=false;
	for(i=0;i<n;i++)
	{
		if(a[i]>=-9&&a[i]<=9)
		{
				Co=true;
		}
		if(a[i]>=10&&a[i]<=99)
		{
			int c=a[i]/10;
			int d=a[i]%10;
			if(c==d)
			{
				Co=true;
			}
		}
		if(a[i]>=100&&a[i]<=999)
		{
			int e=a[i]/100;
			int g=a[i]%10;
			if(e==g)
			{
				Co=true;
			}
		}
		if(a[i]>=1000&&a[i]<=9999)
		{
			int j=a[i]/1000;
			int k=a[i]%10;
			int l=a[i]/10;
			int m=l%10;
			int z=a[i]/100;
			int t=z%10;
			if(j==k&&m==t)
			{
				Co=true;
			}
		}
		if(a[i]>=10000&&a[i]<=99999)
		{
			int o=a[i]/10000;
			int p=a[i]%10;
			int q=a[i]/10;
			int r=q%10;
			int s=a[i]/1000;
			int u=s%10;
			if(o==p&&r==u)
			{
				Co=true;
			}
		}
		if(Co==true)
		{
			Co1=true;
			vitri=i;
			break;
		}
	}
	if(Co1==true)
		printf("\nSo dau tien trong mang thoa tinh chat so ganh la:%d tai vi tri:%d",a[i],vitri);
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietke(a,n);
	dautien(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}
