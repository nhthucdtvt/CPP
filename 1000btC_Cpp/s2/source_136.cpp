
#include<stdio.h>
#include<conio.h>
#include<math.h>
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
	printf("\n>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
	int Co,dem=0;
	bool Co=false;
	printf("Cac gia tri thoa yeu cau de bai la:");
	for(int i=1;i<n-1;i++)
	{
		if(a[i]<abs(a[i+1])&&a[i]>a[i-1])
		{
			printf("%4d",a[i]);
			dem++;		
			Co=true;
		}
	}
	if(Co==true)
	printf("\nTrong mang co %d gia tri thoa yeu cau de bai",dem);
	else
	printf("\nKhong co gia tri nao trong mang thoa yeu cau de bai");
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