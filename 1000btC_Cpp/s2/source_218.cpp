
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
void sapxep(float a[MAX],int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		if (a[i]>=0)
		{
			for (j=i+1;j<n;j++)
			{
				if (a[j]>=0 && a[i]>a[j])
				{
					int temp=a[i];
					a[i] = a[j];
					a[j]=temp;
				}
			}
		}
		printf("%16f",a[i],a[j]);
	}
} 
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>MANG VUA SAP XEP LA:<<<<<<<<<<<<<<<<<\n");
	sapxep(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}