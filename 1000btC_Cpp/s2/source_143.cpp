
#include<stdio.h>
#include<conio.h>
#include<float.h>
#define MAX 100
#define bool
void nhapmang(float a[MAX],int &n)
{
	do{
		printf("Nhap vao so phan tu cua mang:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("So phan tu ban nhap vao khong hop le!Xin vui long nhap lai!\n");
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
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void lietkegiatrivavitri(float a[MAX],int n)
{
	int vitri=0,Co;
	bool Co=false;
	float min=FLT_MAX;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0&&a[i]<min)
		{
			min=a[i];
			Co=true;
		}
	}
	if(Co==true)
		printf("\nGia tri duong nho nhat la:%f",min);
	else
		printf("\nTrong mang khong ton tai gia tri duong");
	printf("\nGia tri duong nho nhat ton tai o cac vi tri la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]==min)
		{
			vitri=i;
			printf("%4d",vitri);
		}
	}
}
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	lietkegiatrivavitri(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}