
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
void xoa(int a[MAX],int &n,int k)
{
	for(int i=k;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}
void xoamang(int a[MAX], int &n)
{ 
	int test,i,j;
	for (i=0; i<n-1; i++)
	{
		for(test = 0,j=i+1; j<n;j++)   //xóa ptử tại j  
		{
			if (a[i]==a[j])
			{
				xoa(a,n,j);
				j--;
				test=1;
			}
		}
		if (test == 1)
		{
			xoa(a,n,i); //Xóa luôn chính nó
			i--;
		}
	} 
} 
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	xoamang(a,n);
	printf("\n>>>>>>>>>>>>>MANG VUA XOA LA:<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}