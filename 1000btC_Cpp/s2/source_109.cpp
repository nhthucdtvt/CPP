
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(float a[MAX],int &n)
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
		scanf("%f",&a[i]);
	}
}
void xuatmang(float a[MAX],int n)
{
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
int xulydulieu(float a[MAX],int n)
{
	int vitri=-1,i;
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			vitri=i;
			break;
		}
	}
	for(i=i+1;i<n;i++)
	{
		if(a[i]<0&&a[i]>a[vitri])
		{
			vitri=i;
		}
	}
	return vitri;
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	int s=xulydulieu(a,n);
	printf("\nVi tri cua gia tri am lon nhat trong mang la:%d",s);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}