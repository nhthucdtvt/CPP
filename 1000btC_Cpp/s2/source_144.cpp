
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 100
#define bool
void nhapmang(int a[MAX],int &n)
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
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void lietkegiatrivavitri(int a[MAX],int n)
{
	int vitri=0,Co;
	bool Co=false;
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0&&a[i]>max)
		{
			max=a[i];
			Co=true;
		}
	}
	if(Co==true)
		printf("\nGia tri chan lon nhat la:%d",max);
	else
		printf("\nTrong mang khong ton tai gia tri chan");
	printf("\nGia tri chan lon nhat ton tai o cac vi tri la:");
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
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	lietkegiatrivavitri(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}