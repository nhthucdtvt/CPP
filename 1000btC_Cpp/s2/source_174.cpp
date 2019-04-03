
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
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
void lietkevademduongchiahetcho7(int a[MAX],int n)
{
	int Co,dem=0;
	bool Co=false;
	printf("\nCac gia tri duong chia het cho 7 co trong mang la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0&&a[i]%7==0)
		{
			printf("%4d",a[i]);
			dem++;
			Co=true;
		}
	}
	if(Co==true)
		printf("\nSo luong cac gia tri duong chia het cho 7 co trong mang la:%d",dem);
	else
		printf("\nTrong mang khong ton tai gia tri duong chia het cho 7");
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietkevademduongchiahetcho7(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}