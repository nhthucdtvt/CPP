
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
	printf("So ban nhap vao khong hop le!Xin ban vui long nhap lai!\n");
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
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void lietkenguyento(int a[MAX],int n)
{
	int f,Co,dem=0;
	bool Co=false;
	printf("\nCac so nguyen to co trong mang la:");
	for(int i=0;i<n;i++)
	{
		f=1;
		if(a[i]<2)
			f=0;
		for(int k=2;k<=a[i]/2;k++)
		{
			if(a[i]%k==0)
				f=0;
		}
		if(f==1)
		{
			printf("%4d",a[i]);
			dem++;
			Co=true;
		}
	}
	if(Co==true)
		printf("\nTrong mang co %d so nguyen to",dem);
	else
		printf("\n0");
}
void nguyentolonnhat(int a[MAX],int n)
{
	int f,Co,max=INT_MIN,vitri=0;
	bool Co=false;
	for(int i=0;i<n;i++)
	{
		f=1;
		if(a[i]<2)
			f=0;
		for(int k=2;k<=a[i]/2;k++)
		{
			if(a[i]%k==0)
				f=0;
		}
		if(f==1)
		{
			if(a[i]>max)
			{
				max=a[i];
				vitri=i;
				Co=true;
			}
		}
	}
	if(Co==true)
		printf("\nSo nguyen to lon nhat la:%d tai vi tri:%d",max,vitri);
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietkenguyento(a,n);
	nguyentolonnhat(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}