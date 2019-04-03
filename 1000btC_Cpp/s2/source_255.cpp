
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(int a[MAX],int &n,int &k,int &x)
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
		printf("\nNhap vao vi tri can them:k=");
		scanf("%d",&k);
		if(k<0||k>n-1)
			printf("\nVi tri can them khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(k<0||k>n-1);
	printf("Nhap vao gia tri x can them:x=");
	scanf("%d",&x);
}
void xuatmang(int a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void themgiatri(int a[MAX], int &n, int x, int k)
{
	for (int i=n; i>k; i--)
	{
		a[i] = a[i-1];
	}
	a[k] = x;
	n++;
} 
void main()
{
	int a[MAX],n,x,k,tieptuc;
	quaylai:nhapmang(a,n,k,x);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>MANG VUA THEM LA:<<<<<<<<<<<<<<<<<\n");
	themgiatri(a,n,x,k);
	xuatmang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
