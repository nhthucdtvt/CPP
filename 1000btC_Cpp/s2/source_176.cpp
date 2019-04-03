
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang (float a[MAX],int &n)
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
		scanf("%f",&a[i]);
	}
}
void nhapgiatrix(float &x)
{
	printf("Nhap vao x=");
	scanf("%f",&x);
}
void xuatmang(float a[MAX],int n)
{
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void xulydulieu(float a[MAX],int n,float x)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			dem++;
		}
	}
	printf("\nSo lan xuat hien cua gia tri x la:%d",dem);
}
void main()
{
	float a[MAX],x;
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	nhapgiatrix(x);
	xuatmang(a,n);
	xulydulieu(a,n,x);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}
