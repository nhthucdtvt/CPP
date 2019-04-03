
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
	printf("\n>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void lietke(int a[MAX],int n)
{
	int x,y,Co,dem=0;
	bool Co=false;
	do{
	printf("LUU Y:O DAY DOAN [X,Y] THI YEU CAU X<Y MOI HOP LE!\n");
	printf("Nhap vao x=");
	scanf("%d",&x);
	printf("Nhap vao y=");
	scanf("%d",&y);
	if(x>y)
	printf("Doan [%d,%d] nay khong hop le!Xin vui long nhap lai!\n",x,y);
	else
	break;
	}while(x>y);
	printf("\nCac gia tri chan trong mang nam trong doan [%d,%d] la:",x,y);
	for(int i=0;i<n;i++)
	{
		if(a[i]>=x&&a[i]<=y)
		{
			if(a[i]%2==0)
			{
			printf("%4d",a[i]);
			dem++;
			Co=true;
			}
		}
	}	
	if(Co==true)
	printf("\nTrong mang co ton tai %d gia tri chan nam trong doan [%d,%d]\n",dem,x,y);
	else
	printf("\nTrong mang khong ton tai gia tri chan nao nam trong doan [%d,%d]",x,y);
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietke(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}