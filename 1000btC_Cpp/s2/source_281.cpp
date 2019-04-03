
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
int kiemtramangtang(int b[MAX], int nb)
{
	for(int i=0; i<nb-1; i++)
	{
		if (b[i]>b[i+1])
			return 0;
	}
	return 1;
}
void xuatmangcon(int b[MAX], int nb)
{
	for(int i=0; i<nb; i++)
	{
		printf("%4d", b[i]);
	}
	printf("\n");
}
void lietkecontang(int a[MAX], int n)
{
	int ChieuDai;
	int b[100], nb;
	for (int i=0; i<n; i++)
	{
		for (ChieuDai = 1+i; ChieuDai<=n; ChieuDai++)
		{
			nb=0;
			for(int j=i; j<ChieuDai; j++)
			{
				b[nb]=a[j];
				nb++;
			}
			if (kiemtramangtang(b,nb)==1)
			{
				xuatmangcon(b,nb);
			}
		}
	}
} 
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>CAC MANG CON TANG LA:<<<<<<<<<<<<<<<<<\n");
	lietkecontang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}