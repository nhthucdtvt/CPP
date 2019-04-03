
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập mảng.
void NhapMang(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang A:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
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
// Hàm xuất mảng.
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm hoán vị.
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm tách ra phần tử chẵn lưu vào mảng C,phần tử lẻ lưu vào mảng D
void TachChanVaLe(int a[],int c[],int d[],int n)
{
	int j=0,k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			c[j++]=a[i];
		}
		else
		{
			d[k++]=a[i];
		}
	}
}
// Hàm trả về số lượng các phần tử chẵn trong mảng C .
int SoLuongPhanTuMangC(int a[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			dem++;
		}
	}
	return dem;
}
// Hàm trả về số lượng các phần tử lẻ trong mảng D .
int SoLuongPhanTuMangD(int a[],int n)
{
	int dem1=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			dem1++;
		}
	}
	return dem1;
}
// Hàm sắp mảng C chứa các phần tử chẵn tăng dần .
void SapMangCTangDan(int c[],int dem)
{
	for(int i=0;i<dem-1;i++)
	{
		for(int j=i+1;j<dem;j++)
		{
			if(c[i]>c[j])
			{
				HoanVi(c[i],c[j]);
			}
		}
	}
}
// Hàm sắp mảng D chứa các phần tử lẻ giảm dần .
void SapMangDGiamDan(int d[],int dem1)
{
	for(int i=0;i<dem1-1;i++)
	{
		for(int j=i+1;j<dem1;j++)
		{
			if(d[i]<d[j])
			{
				HoanVi(d[i],d[j]);
			}
		}
	}
}
// Hàm ghép chung 2 mảng C & D vào chung 1 mảng F theo đúng trình tự thì ghép mảng C vào trước & mảng D vào sau .
void MangF(int f[],int c[],int d[],int dem,int dem1)
{
	int l=0;
	for(int j=0;j<dem;j++)
	{
		f[l++]=c[j];
	}
	for(int k=0;k<dem1;k++)
	{
		f[l++]=d[k];
	}
}
// Hàm chính .
void main()
{
	int a[MAX],c[MAX],d[MAX],f[MAX];
	int n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>Mang A ban dau la:<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	int s=SoLuongPhanTuMangC(a,n);
	int s1=SoLuongPhanTuMangD(a,n);
	TachChanVaLe(a,c,d,n);
	SapMangCTangDan(c,s);
	printf("\n>>>>>>>>>>Mang C chua cac phan tu chan cua mang A va sap tang dan :<<<<<<<<<<<<<<<<<<\n");
	XuatMang(c,s);
	printf("\n");
	SapMangDGiamDan(d,s1);
	printf("\n>>>>>>>>>Mang D chua cac phan tu le cua mang A va sap giam dan :<<<<<<<<<<<<<<<<<<\n");
	XuatMang(d,s1);
	printf("\n");
	MangF(f,c,d,s,s1);
	printf("\n>>>>>>>>>>Mang F ghep cac phan tu cua 2 mang C & D :<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(f,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}