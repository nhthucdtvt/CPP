
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
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void tinhtong(float a[MAX],int n)
{
	int dem=0;
	float s=0,Co;
	bool Co=false;
	printf("Cac gia tri lon hon gia tri dung lien truoc no la:");
	for(int i=1;i<n;i++)
	{	
		if(a[i]>a[i-1])
		{
			printf("%16f",a[i]);
			dem++;
			s+=a[i];
			Co=true;
		}
	}
	if(Co==true)
	{
		printf("\nCo %d gia tri trong mang thoa man yeu cau de bai",dem);
		printf("\nTong tat ca cac gia tri lon hon gia tri dung lien truoc no la:%f",s);
	}
	else
	printf("\nKhong co gia tri nao trong mang thoa yeu cau de bai");	
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	tinhtong(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}