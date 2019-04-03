
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
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
void timtatcasothoadieukien(float a[MAX],int n)
{
	printf("Cac so am trong mang lon hon gia tri -1 la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]<0&&a[i]>-1)
		{
			printf("%16f",a[i]);
		}
	}
}
void timsocuoicung(float a[MAX],int n)
{
	int tam,Co,i;
	bool Co=false;
	for(i=0;i<n;i++)
	{
		if(a[i]<0&&a[i]>-1)
		{
			tam=i;
			Co=true;
		}
	}
	if(Co==true)
	printf("\nGia tri am cuoi cung lon hon -1 la:%f",a[tam]);
	else
	printf("\n0");
}	
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	timtatcasothoadieukien(a,n);
	timsocuoicung(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}