
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
void nhapvaox(float &x)
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
	float tong=0,Co;
	int dem=0;
	bool Co=false;
	printf("\nCac gia tri trong mang lon hon gia tri x la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]>x)
		{
			printf("%16f",a[i]);
			dem++;
			tong+=a[i];
			Co=true;
		}
	}
	if(Co==true)
	{
		printf("\nSo luong cac gia tri trong mang lon hon gia tri x la:%d",dem);
		float trungbinhcong=tong/dem;
		printf("\nTrung binh cong cac gia tri trong mang lon hon gia tri x la:%f",trungbinhcong);
	}
	else
		printf("\nTrong mang khong co gia tri nao lon hon x");
}
void main()
{
	float a[MAX],x;
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	nhapvaox(x);
	xuatmang(a,n);
	xulydulieu(a,n,x);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}