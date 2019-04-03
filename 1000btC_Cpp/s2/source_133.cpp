
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
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void lietke(float a[MAX],int n)
{
	float x,y,Co;
	bool Co=false;
	do{
	printf("LUU Y:O DAY DOAN [X,Y] THI YEU CAU X<Y MOI HOP LE!\n");
	printf("Nhap vao x=");
	scanf("%f",&x);
	printf("Nhap vao y=");
	scanf("%f",&y);
	if(x>y)
	printf("\nDoan [%f,%f] nay khong hop le!Xin vui long nhap lai!\n",x,y);
	else
	break;
	}while(x>y);
	printf("Cac gia tri trong mang nam trong doan [%f,%f] la:",x,y);
	for(int i=0;i<n;i++)
	{
		if(a[i]>=x&&a[i]<=y)
		{
		printf("%16f",a[i]);
		Co=true;
		}
	}
	if(Co==true)
	printf("\nTrong mang co ton tai gia tri nam trong doan [%f,%f]\n",x,y);
	else
	printf("\nTrong mang khong co ton tai gia tri nao nam trong doan [%f,%f]\n",x,y);
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietke(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}