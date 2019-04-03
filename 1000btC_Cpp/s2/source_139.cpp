
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
void xuatmang(float a[MAX],int n)
{
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void xulydulieu(float a[MAX],int n)
{
	float max=a[0]; // gán max = a[0]:phần tử đầu tiên của mảng.
	int vitri=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	printf("\nGia tri lon nhat trong mang la:%f",max);
	printf("\nCac vi tri cua gia tri lon nhat la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]==max)
		{
			vitri=i;
			printf("%4d",vitri);
		}
	}
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}