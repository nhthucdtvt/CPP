
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
void DayConToanDuongDaiNhat(float a[MAX],int n)
{
	int i,l,k,test,vt,pt=0;
	for (i=0;i<n;i++)
	{
		for (l=i; l<=n;l++)
		{
			for (test = 1,k=0; k<l ; k++)
			{
				if (a[k]<0)
				{
					test = 0; break;
				}
			}
			if (test == 1)
			{
				if (pt<k)
				{
					pt=k;
					vt=i;
				}
			}
		}
	}
	for (vt; vt<pt; vt++)
		printf("%16f",a[vt]);
}
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>DAY CON TOAN DUONG DAI NHAT LA:<<<<<<<<<<<<<<<<<\n");
	DayConToanDuongDaiNhat(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}