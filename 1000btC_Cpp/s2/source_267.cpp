
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
void duachanvedau(int a[MAX], int k)
{
	int tam = a[k];
	for(int i = k ; i>0; i--)
	{
		a[i] = a[i-1];
	}
	a[0] = tam;
}
void dua0(int a[MAX], int k, int vitrichancuoi)
{
	for(int i = k ; i>vitrichancuoi; i--)
	{
		a[i] = a[i-1];
	}
	a[vitrichancuoi] = 0;
}
void sapxep(int a[MAX], int n)
{
	int i;
	int vitrichancuoi;
	for (i=0; i<n; i++)
	{
		if (a[i] %2 == 0 && a[i]!=0)
		{
			duachanvedau(a,i); //vi tri i
		}
	}
	for (i=0; i<n; i++)
	{
		if (a[i]%2!=0)
		{
			vitrichancuoi = i;
			break;
		}
	}
	for (i; i<n; i++)
	{
		if (a[i] == 0 )
		{
			dua0(a,i,vitrichancuoi); //vi tri i
		}
	}
} 
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	sapxep(a,n);
	printf("\n>>>>>>>>>>>>>MANG VUA SAP XEP LA:<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}