
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
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void lietketatcasohoanthien(int a[MAX],int n)
{
	int Co;
	bool Co=false;
	int dem=0;
	printf("Trong mang co cac so hoan thien la:");
	for(int i=0;i<n;i++)
	{
		int tong=0; // tong=0 phải để ở trong vòng lặp thì mới hiển thị ra được kết quả.
		for(int k=1;k<a[i];k++)
		{
			if(a[i]%k==0)
			{
				tong+=k;
				if(tong==a[i])
				{
					printf("%4d",a[i]);
					dem++;
					Co=true;
				}
			}
		}
	}
	if(Co==true)
	{
		printf("\nCo %d so hoan thien trong mang",dem);
	}
	else
	printf("\n0");
}
void sohoanthiennhonhat(int a[MAX],int n)
{
	int Co;
	bool Co=false;
	int vitri=0,min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int tong=0; // tong=0 phải để ở trong vòng lặp thì mới hiển thị ra được kết quả.
		for(int k=1;k<a[i];k++)
		{
			if(a[i]%k==0)
			{
				tong+=k;
				if(tong==a[i])
				{
					if(a[i]<min)
					{
						min=a[i];
						vitri=i;
						Co=true;
					}
				}
			}
		}
	}
	if(Co==true)
		printf("\nSo hoan thien nho nhat trong mang la:%d tai vi tri:%d",min,vitri);
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietketatcasohoanthien(a,n);
	sohoanthiennhonhat(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}
