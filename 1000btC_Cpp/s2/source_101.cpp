
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
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void duongcuoicung(int a[MAX],int n)
{
	int tam,Co,dem=0,vitri=0;
	bool Co=false;
	printf("\nCac so duong co trong mang la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			printf("%4d",a[i]);
			dem++;
			tam=i;
			vitri=i;
			Co=true;
		}
	}
	if(Co==true)
	{
	printf("\nTrong mang co %d gia tri duong",dem);
	printf("\nSo duong cuoi cung trong mang la:%d tai vi tri:%d",a[tam],vitri);
	}
	else
	printf("\n-1");
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	duongcuoicung(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}