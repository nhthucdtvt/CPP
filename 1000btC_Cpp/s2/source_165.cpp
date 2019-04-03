
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
#define bool
void nhapmang(int a[MAX],int &n)
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
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
	double sqrt(double x);
	int dem=0,tong=0,Co;
	bool Co=false;
	printf("\nCac so chinh phuong co trong mang la:");
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<=a[i];k++)
		{
			if(sqrt (a[i])==k)
			{
				printf("%4d",a[i]);
				dem++;
				tong+=a[i];
				Co=true;
			}
		}
	}
	if(Co==true)
	{
		printf("\nTrong mang co %d so chinh phuong",dem);
		printf("\nTong cac so chinh phuong co trong mang la:%d",tong);
	}
	else
		printf("\nTrong mang khong ton tai so chinh phuong\n");
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}