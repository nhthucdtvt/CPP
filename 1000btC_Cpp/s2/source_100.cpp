
#include<stdio.h>
#include<conio.h>
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
void lietkeam(float a[MAX],int n)
{
	int dem=0,Co;
	bool Co=false;
	printf("\nCac gia tri am co trong mang la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			printf("%16f",a[i]);
			dem++;
			Co=true;
		}
	}
	if(Co==true)
	printf("\nTrong mang co %d gia tri am",dem);
	else
	printf("\n-1");
}
void amdautien(float a[MAX],int n)
{
	int i,vitri=0,Co;
	bool Co=false;
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			Co=true;
			vitri=i;
			break;
		}
	}
	if(Co==true)
	printf("\nGia tri am dau tien la:%f tai vi tri:%d",a[i],vitri);
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietkeam(a,n);
	amdautien(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}