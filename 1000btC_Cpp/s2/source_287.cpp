
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
void xuatmang(int a[MAX],int b[MAX],int n,int m)
{
	printf("\n>>>>>>>>>>>>>>>>>>MANG A VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>>MANG B VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<\n");
	for(int j=0;j<m;j++)
	{
		printf("%4d",b[j]);
	}
	printf("\n");
}
int kiemtramangcon(int a[MAX], int b[MAX], int n, int m)
{
	int i,j,test = 0;
	for (i=0; i<m; i++)
	{
		if (b[i]==a[0])
		{
			int h = i;
			for (test=1, j=0; j<n;j++,h++)
			{
				if (a[j] != b[h])
				{
					test = 0;
					break;
				}
			}
			if (test == 1)
				return test;        //Mảng a là con mảng b
		}
	}
	return test;
} 
void main()
{
	int a[MAX],b[MAX],n,m,tieptuc;
	quaylai:nhapmang(a,b,n,m);
	xuatmang(a,b,n,m);
	printf("\n>>>>>>>>>>>>>MANG A CO PHAI LA MANG CON TRONG MANG B ?:<<<<<<<<<<<<<<<<<\n");
	int s=kiemtramangcon(a,b,n,m);
	if(s==1)
		printf("\nYES");
	else
		printf("\nNO");
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
