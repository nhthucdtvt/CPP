
#include<stdio.h>
void nhap(int a[], int &n)
{
	printf("Nhap n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void hoanvi(int &a, int &b)
{
	int c=a;
	a=b;
	b=c;
}
void interchangesort(int a[], int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
		}
		hoanvi(a[i],a[min]);
	}
}
void xuat(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
int xuly(int a[],int n)
{
	int max=0,dem=0,nam=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			dem=0;
		}
		dem++;
		if(dem>max)
		{
			max=dem;
			nam=a[i];
		}
	}
	return nam;
}
void main()
{
	int a[100],n;
	nhap(a,n);
	printf("\n>>>>>>>>>> Mang Vua Nhap La: <<<<<<<<<<<<<<\n");
	xuat(a,n);
	interchangesort(a,n);
	printf("\n");
	printf("Gia Tri Co So Lan Xuat Hien Nhieu Nhat La:%d",xuly(a,n));
}