
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(int a[MAX],int b[MAX],int &n,int &m)
{
	do{
		printf("Nhap vao so phan tu cua mang A:n=");
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
		printf("Nhap vao so phan tu cua mang B:m=");
		scanf("%d",&m);
		if(m<1||m>MAX)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(m<1||m>MAX);
	for(int j=0;j<m;j++)
	{
		printf("Nhap vao b[%d]=",j);
		scanf("%d",&b[j]);
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
void sapxep(int a[MAX],int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (a[i]>a[j])
			{
				int temp=a[i];
				a[i] = a[j];
				a[j]=temp;
			}
		}
	}
} 
void TronMang(int a[MAX],int b[MAX],int c[MAX],int n,int m,int &d)
{
	d= n + m;
	sapxep(a,n);    //Sap xep tang mang A
	sapxep(b,m);   //Sap xep tang mang B
	int vta=0,vtb=0;
	for (int i=0;i<d;i++)
	{
		if (vta < n && vtb < m)
		{
			if (a[vta] < b[vtb])
			{
				c[i] = a[vta];
				vta++;
			}
			else
			{
				c[i] = b[vtb];
				vtb++;
			}
		}
		else if (vtb == m)
		{
			c[i] = a[vta];
			vta++;
		}
		else
		{
			c[i] = b[vtb];
			vtb++;
		}
	}
} 
void main()
{
	int a[MAX],b[MAX],c[MAX],n,m,d,tieptuc;
	quaylai:nhapmang(a,b,n,m);
	printf("\n>>>>>>>>>>>>>MANG A VUA NHAP LA:<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>MANG B VUA NHAP LA:<<<<<<<<<<<<<<<<<\n");
	xuatmang(b,m);
	printf("\n>>>>>>>>>>>>>MANG C SAU KHI DUOC TRON BOI 2 MANG A VA B VA SAP XEP TANG DAN LA:<<<<<<<<<<<<<<<<<\n");
	TronMang(a,b,c,n,m,d);
	xuatmang(c,d);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
