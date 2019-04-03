
#include<stdio.h>
#include<conio.h>
#define MAX 100
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
void hoanvi(int &a, int &b)
{
	int tam = a;
	a = b;
	b =tam;
} 
void daonguocchanle(int  a[MAX], int n)
{
	int i, j;
	for (i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if (a[i]%2==0 && a[j]%2 == 0)
				hoanvi(a[i],a[j]);
			else if (a[i]%2!=0 && a[j]%2!=0)
				hoanvi(a[i],a[j]);
		}
	}
} 
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	daonguocchanle(a,n);
	printf("\n>>>>>>>>>>>>>MANG SAU KHI DAO LA:<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}