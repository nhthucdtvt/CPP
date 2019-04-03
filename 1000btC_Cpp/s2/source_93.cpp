
#include<stdio.h>
#include<conio.h>
#include<float.h>
#define MAX 100
#define bool
void nhapmang(float a[MAX],int &n)
{
	do{
	printf("Nhap vao so phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	printf("So ban nhap vao khong hop le!Xin ban vui long nhap lai!\n");
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
	printf("\n>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void timnhonhat(float a[MAX],int n)
{
	int Co,vitri=0;
	bool Co=false;
	float min=FLT_MAX; // cái này để tìm ra giá trị lớn nhất của kiểu float (số thực),nếu dùng theo double thì sẽ là min=DBL_MAX.
	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			vitri=i;
			Co=true;
		}
	}
	if(Co==true)
	printf("\nGia tri nho nhat trong mang la:%f tai vi tri:%d",min,vitri);
}
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	timnhonhat(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}