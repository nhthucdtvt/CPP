
#include<stdio.h>
#include<conio.h>
#define MAX 100
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
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
int kiemtramanggiam(float b[MAX], int nb)
{
	for(int i=0; i<nb-1; i++)
	{
		if (b[i]<b[i+1])
			return 0;
	}
	return 1;
}
void xuatmangcon(float b[MAX], int nb)
{
	for(int i=0; i<nb; i++)
	{
		printf("%16f", b[i]);
	}
	printf("\n");
}
void lietkecongiam(float a[MAX], int n)
{
	int ChieuDai;
	int  nb;
	int dem=0;
	float b[MAX];
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
			if (kiemtramanggiam(b,nb)==1)
			{
				xuatmangcon(b,nb);
				dem++;
			}
		}
	}
	printf("\nCo %d mang con giam",dem);
} 
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>CAC MANG CON GIAM LA:<<<<<<<<<<<<<<<<<\n");
	lietkecongiam(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
