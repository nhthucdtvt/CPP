
#include<stdio.h>
#include<conio.h>
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
	printf("\n>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void timratatcanguyento(int a[MAX],int n)
{
	int f;
	printf("Cac so nguyen to co trong mang la:");
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
			printf("%4d",a[i]); // dòng này để xác định ra tất cả các số nguyên tố có trong mảng.
		}
	}
}
void timnguyentodautien(int a[MAX],int n)
{
	int i,f,Co;
	bool Co=false;
	for(i=0;i<n;i++)
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
			Co=true; // dòng này để xác định số nguyên tố đầu tiên,khi gặp nó chương trình sẽ break (thoát ra khỏi vòng lặp) và in ra giá trị.
			break;
		}
	}
	if(Co==true)
	printf("\nSo nguyen to dau tien co trong mang la:%d",a[i]);
	else
	printf("\n-1");
}	
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	timratatcanguyento(a,n);
	timnguyentodautien(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}
