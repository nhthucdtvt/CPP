
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
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
	float tich=1;
	int dem=0,Co;
	bool Co=false;
	printf("\nCac so duong co trong mang la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			printf("%16f",a[i]);
			dem++;
			tich*=a[i];
			Co=true;
		}
	}
	if(Co==true)
	{
		printf("\nSo luong cac so duong co trong mang la:%d",dem);
		float trungbinhnhan=tich/dem;
		printf("\nTrung binh nhan cac so duong co trong mang la:%f",trungbinhnhan);
	}
	else
		printf("\nTrong mang khong ton tai gia tri duong\n");
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
