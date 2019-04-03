
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
void kiemtradoixung(float a[MAX],int n)
{
	int Co,dem=0;
	bool Co=false;
	for(int i=0;i<n/2;i++)
	{
		if(a[i]==a[n-i-1])
		{
			dem++;
			Co=true;
		}
	}
	if(Co==true)
	{
		if(dem==n/2)
			printf("\nYES");
		else
			printf("\nNO");
	}
	else
		printf("\nNO");
}
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>MANG CO DOI XUNG HAY KHONG ? <<<<<<<<<<<<<<<<<<\n");
	kiemtradoixung(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}