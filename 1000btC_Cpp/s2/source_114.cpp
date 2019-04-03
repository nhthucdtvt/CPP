
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
void nhapmang(float a[MAX],int &n)
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
void timtatcagiatrilonhon2003(float a[MAX],int n)
{
	printf("Cac gia tri lon hon 2003 co trong mang la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]>2003)
		{
			printf("%16f",a[i]);
		}
	}
}	
void timgiatridautien(float a[MAX],int n)
{
	int i,Co;
	bool Co=false;
	for(i=0;i<n;i++)
	{
		if(a[i]>2003)
		{
			Co=true;
			break;
		}
	}
	if(Co==true)
		printf("\nGia tri dau tien lon hon 2003 co trong mang la:%f",a[i]);
	else
		printf("\n0");
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	timtatcagiatrilonhon2003(a,n);
	timgiatridautien(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}