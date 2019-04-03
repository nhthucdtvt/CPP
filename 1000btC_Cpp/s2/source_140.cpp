
#include<stdio.h>
#include<conio.h>
#define MAX 100
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
void lietkevitrichuasonguyento(int a[MAX],int n)
{
	int f,vitri=0;
	printf("\nCac vi tri trong mang co chua so nguyen to la:");
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
			vitri=i;
			printf("%4d",vitri);
		}
	}
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietkevitrichuasonguyento(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}
