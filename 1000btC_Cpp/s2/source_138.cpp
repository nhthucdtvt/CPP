
#include<stdio.h>
#include<conio.h>
#define MAX 100
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
	printf("\nO DAY TA SE KHONG XET TRUONG HOP SO 0 VI SO 0 KHONG PHAI LA SO AM HAY LA SO DUONG!NEN DIEU KIEN CAC PHAN TU TRONG MANG PHAI KHAC 0!\n");
	for(int i=0;i<n;i++)
	{
		quaylai1:printf("Nhap vao a[%d]=",i);
		scanf("%f",&a[i]);
		if(a[i]==0)
		{
			printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
			goto quaylai1;
		}
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
void lietke(float a[MAX],int n)
{
	printf("\nCac gia tri trong mang co it nhat mot lan can trai dau voi no la:");
	for(int i=1;i<n-1;i++)
	{
		int b=a[i]*a[i-1];
		int c=a[i]*a[i+1];
		if(b<0||c<0)
			printf("%16f",a[i]);
	}
}
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	lietke(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}