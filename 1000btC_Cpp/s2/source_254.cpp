
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#define MAX 5000
void PhatSinhNgauNhienCacPhanTu(int a[], int &n)
{
	quaylai:printf ("\nNhap so luong phan tu cua mang:n= ");
	scanf ("%d", &n);
	if(n<1)
	{
		printf("\nSo phan tu ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	srand(time(0));
	for(int i=0;i<n;i++)
		a[i]=(rand()%41)-20;
}
void GhiFileNamSon(int a[], int n)
{
	FILE * pFile;
	pFile = fopen ("NamSon.txt","wt");
	fprintf(pFile,"So Luong Cac Phan Tu Trong Mang La:%d \n",n);
	for(int i=0;i<n;i++)
	{
		a[i]=(rand()%61)-30;
		fprintf (pFile, "a[%d]=%d\n",i,a[i]);
	}
	fclose (pFile);
}
void DocFileNamSon(int a[], int n)
{
	FILE * pFile;
	pFile = fopen("NamSon.txt", "r+t");
	if(pFile==NULL)
		printf("\nKhong Doc Duoc File NamSon.txt");
	else
	{
		for(int i=0; i<n; i++)
		{
			fscanf(pFile, "%d\t", &a[i]);
			printf ("a[%d]=%d\n",i,a[i]);
		}
	}
	fclose(pFile);
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
void SapXepGiamDanBangThuatToanInterchangeSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				HoanVi(a[i],a[j]);
			}
		}
	}
}
void SapXepGiamDanBangThuatToanQuickSort(int a[],int left,int right)
{
	int i,j,x;
	if(left>=right)
	{
		return;
	}
	x=a[(left+right)/2]; // Chọn phần tử giữa làm giá trị mốc .
	i=left;
	j=right;
	while(i<j)
	{
		while(a[i]>x) // ở đây là sắp giảm dần
		{
			i++;
		}
		while(a[j]<x) // ở đây là sắp giảm dần
		{
			j--;
		}
		if(i<=j)
		{
			HoanVi(a[i],a[j]);
			i++;
			j--;
		}
	}
	SapXepGiamDanBangThuatToanQuickSort(a,left,j);
	SapXepGiamDanBangThuatToanQuickSort(a,i,right);
}
void SapXepGiamDanBangThuatToanSelectionSort(int a[],int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			HoanVi(a[min],a[i]);
		}
	}
}
void SapXepGiamDanBangThuatToanBubbleSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				HoanVi(a[j],a[j-1]);
			}
		}
	}
}
void main ()
{
	int a[MAX],n,tieptuc;
	quaylai:PhatSinhNgauNhienCacPhanTu(a,n);
	GhiFileNamSon(a,n);
	DocFileNamSon(a,n);
	printf("\n>>>>>>>>>>>>>Mang Cac So Nguyen Doc Tu File: <<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapXepGiamDanBangThuatToanInterchangeSort(a,n);
	printf("\n>>>>>>>>Mang Sau Khi Sap Giam Dan Bang Thuat Toan Interchange Sort :<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapXepGiamDanBangThuatToanQuickSort(a,0,n-1);
	printf("\n>>>>>>>>Mang Sau Khi Sap Giam Dan Bang Thuat Toan Quick Sort :<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapXepGiamDanBangThuatToanSelectionSort(a,n);
	printf("\n>>>>>>>>Mang Sau Khi Sap Giam Dan Bang Thuat Toan Selection Sort :<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapXepGiamDanBangThuatToanBubbleSort(a,n);
	printf("\n>>>>>>>>Mang Sau Khi Sap Giam Dan Bang Thuat Toan Bubble Sort :<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	printf("\nBan muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}