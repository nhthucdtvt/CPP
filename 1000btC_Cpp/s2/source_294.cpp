
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
void TaoMangB(int a[MAX], int n)
{
	int b[MAX], nb=0,f;
	for (int i=0; i<n;i++)
	{
		f=1;
		if(a[i]<2)
			f=0;
		for(int k=2;k<=a[i]/2;k++)
		{
			if(a[i]%k==0)
				f=0;
		}
		if(f==1)
		{
			b[nb]=a[i];
			nb++;
		}
	}
	xuatmang(b,nb);
} 
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>MANG B CHUA CAC SO NGUYEN TO TRONG MANG A LA:<<<<<<<<<<<<<<<<<\n");
	TaoMangB(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}