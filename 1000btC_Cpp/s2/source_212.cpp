
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 100
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
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
	int max=INT_MIN,vitri=0,dem=0;
	printf("\nLUU Y:Doi voi cac gia tri thoa dieu kien lon hon tat ca cac gia tri dung truoc no thi ta se liet ke them vi tri cua no ngay ben canh gia tri do.vi du gia tri thoa la 5 va tai vi tri 1 thi ta se ghi ra la:(5,1)");
	printf("\nCac gia tri lon hon tat ca moi gia tri dung truoc no la:");
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]>max)
				max=a[j];
		}
			if(a[i]>max)
			{
				vitri=i;
				printf("(%d,%d)",a[i],vitri);
				dem++;
			}
	}
	if(dem!=0)
		printf("\nCo %d gia tri trong mang lon hon tat ca cac gia tri dung dang truoc no",dem);
	else
		printf("\nKhong co gia tri nao trong mang thoa dieu kien lon hon tat ca cac gia tri dung dang truoc no");
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