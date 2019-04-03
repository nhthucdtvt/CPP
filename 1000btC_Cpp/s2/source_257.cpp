
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(int a[MAX],int &n,int &k)
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
	do{
		printf("\nNhap vao vi tri can xoa:k=");
		scanf("%d",&k);
		if(k<0||k>n-1)
			printf("\nVi tri can xoa khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(k<0||k>n-1);
}
void xuatmang(int a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xoa(int a[MAX],int &n,int k)
{
	for(int i=k;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}
void main()
{
	int a[MAX],n,k,tieptuc;
	quaylai:nhapmang(a,n,k);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	xoa(a,n,k);
	printf("\n>>>>>>>>>>>>>MANG VUA XOA LA:<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}