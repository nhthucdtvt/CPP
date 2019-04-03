
#include<stdio.h>
#include<conio.h>
#include<limits.h>
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
void xulydulieu(int a[MAX],int n)
{
	int max=INT_MIN,Co,f,i,Co1;
	bool Co=false;
	bool Co1=false;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			Co=true;
		}
	}
	if(Co==true)
	{
		for(i=max+1;i<30000;i++) // => 30000 là xấp xĩ giá trị lớn nhất của kiểu int
		{
			f=1;
			if(i<2)
				f=0;
			for(int k=2;k<=i/2;k++)
			{
				if(i%k==0)
					f=0;
			}
			if(f==1)
			{
				Co1=true;
				break;
			}
		}
		if(Co1==true)
			printf("\nSo nguyen to nho nhat lon hon moi gia tri co trong mang la:%d",i);
	}
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}