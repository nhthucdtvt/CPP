
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<Windows.h>
#define MAX 100
#define bool
void NhapMang(int a[MAX],int &n)
{
	quaylai:printf("\nNhap vao so phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void XuatMang(int a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void PhanTuLonNhat(int a[MAX],int n)
{
	int max=INT_MIN,Co;
	bool Co=false;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			Co=true;
		}
	}
	if(Co==true)
		printf("\nSo lon nhat la:%d",max);
}
void HoanVi(int &x,int &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void SapXepTangDan(int a[MAX],int n)
{
	// Coppy lại mảng nguyên thủy lúc đầu bằng cách gán 1 mảng b = nó xong rồi ta sử dụng mảng b ở câu này,để dành mảng a ở câu sau thì ở câu sau nó sẽ xóa các phần tử trùng nhau dựa trên nền tảng mảng lúc đầu (mảng a) chứ không đụng đến mảng vừa sắp xếp (mảng b).
	int b[MAX];
	for(int i=0;i<n;i++)
		b[i]=a[i];
	printf("\n>>>>>>>>>>>>Mang Sau Khi Sap Xep Tang Dan:<<<<<<<<<<<<<<<\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[i]>b[j])
				HoanVi(b[i],b[j]);
		}
		printf("%4d",b[i],b[j]);
	}
}
void TinhTong5SoLeDauTien(int a[MAX],int n)
{
	int dem=0,tong=0,Co,Co1;
	bool Co=false;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			dem++;
			if(dem<=5)
			{
				Co=true;
				tong+=a[i];
			}
		}
	}
	if(Co==true)
		printf("\nTong 5 so le dau tien la:%d",tong);
	else
		printf("\nTrong mang khong ton tai so le nen khong the tinh duoc!\n");	
}
void Xoa(int a[MAX],int &n,int k)
{
	for(int i=k;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}
void XoaPhanTuTrungNhau(int a[MAX],int &n) 
{
	for (int i=0; i<n-1; i++) 
	{
		for(int j=i+1; j<n;j++) 
		{
			if (a[i]==a[j]) 
			{
				Xoa(a,n,j);
				j--; 
			} 
		} 
	}
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n");
	printf("\n>>>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	PhanTuLonNhat(a,n);
	printf("\n");
	TinhTong5SoLeDauTien(a,n);
	printf("\n");
	SapXepTangDan(a,n);
	printf("\n");
	XoaPhanTuTrungNhau(a,n);
	printf("\n>>>>>>>>>>>Mang Sau Khi Xoa Cac Phan Tu Trung Nhau La:<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}