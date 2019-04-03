
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
void NhapMang(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<3||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
void SapTangDan(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				HoanVi(a[i],a[j]);
			}
		}
	}
}
void TimSoLonThuBa(int a[],int n)
{
	int vt1=0,vt2=0,max1,max2,max3,dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			dem++;
		}
	}
	if(dem>=3)
	{
		for(int i=0;i<n;i++)
		{
			max1=a[n-1];
			if(max1==a[i])
			{
				vt1=i;
				break;
			}
		}
		for(int i=0;i<vt1;i++)
		{
			max2=a[vt1-1];
			if(max2==a[i])
			{
				vt2=i;
				break;
			}
		}
		max3=a[vt2-1];
		printf("\nPhan tu lon thu 3 trong mang la:%d",max3);
	}
	else
		printf("\nMang nay khong ton tai it nhat 3 phan tu khac nhau nen khong the tinh duoc!");
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>Mang Vua Nhap Vao La:<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapTangDan(a,n);
	TimSoLonThuBa(a,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}