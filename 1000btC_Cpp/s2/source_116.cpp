
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
void nhapmang (float a[MAX],int &n)
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
		scanf("%f",&a[i]);
	}
}
void xuatmang(float a[MAX],int n)
{
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void lietke(float a[MAX],int n)
{
	float x,y,Co;
	bool Co=false;
	int dem=0,vitri=0,Co1,i;
	bool Co1=false;
	do{
	printf("LUU Y:O DAY KHOANG (X,Y) THI YEU CAU X<Y MOI HOP LE!\n");
	printf("Nhap vao x=");
	scanf("%f",&x);
	printf("Nhap vao y=");
	scanf("%f",&y);
	if(x>y)
	printf("\nKhoang (%f,%f) nay khong hop le!Xin vui long nhap lai!\n",x,y);
	else
	break;
	}while(x>y);
	printf("Cac gia tri trong mang nam trong khoang (%f,%f) la:",x,y);
	for(i=0;i<n;i++)
	{
		if(a[i]>x&&a[i]<y)
		{
		printf("%16f",a[i]);
		dem++;
		Co=true;
		}
	}
	if(Co==true)
	printf("\nTrong mang co %d gia tri nam trong khoang (%f,%f)\n",dem,x,y);
	else
	printf("\nTrong mang khong co ton tai gia tri nao nam trong khoang (%f,%f)\n",x,y);
	for(i=0;i<n;i++)
	{
		if(a[i]>x&&a[i]<y)
		{
			Co1=true;
			vitri=i;
			break;
		}
	}
	if(Co1==true)
		printf("\nGia tri dau tien nam trong khoang (%f,%f) la:%f tai vi tri:%d",x,y,a[i],vitri);
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietke(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}