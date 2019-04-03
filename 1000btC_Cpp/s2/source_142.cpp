
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
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void xulydulieu(float a[MAX],int n)
{
	int dem=0,dem1=0,vitri=0,vitri1=0,Co,Co1,i,Co2;
	bool Co=false;
	bool Co1=false;
	bool Co2=false;
	printf("Cac so am co trong mang la:");
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			printf("%16f",a[i]);
			dem++;
			Co=true;
		}
	}
	if(Co==true)
		printf("\nCo %d so am trong mang",dem);
	else
		printf("\nTrong mang khong co so am nao ca");
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			Co1=true;
			vitri=i;
			break;
		}
	}
	if(Co1==true)
	{
		float x=a[i]; // ta phải gán giá trị âm đầu tiên bằng 1 biến x để sau này ta xét tuần tự x==a[i] mới được.
		printf("\nSo am dau tien trong mang la:%f tai vi tri:%d",x,vitri);
		for(i=0;i<n;i++)
		{
			if(a[i]==x)
			{
				dem1++;
				Co2=true;
			}
		}
		if(Co2==true)
		{
			printf("\nCo %d gia tri trong mang bang gia tri am dau tien",dem1);
		}
		printf("\nCac vi tri cua gia tri trong mang bang voi gia tri am dau tien la:");
		for(i=0;i<n;i++)
		{
			if(a[i]==x)
			{
				vitri1=i;
				printf("%4d",vitri1);
			}
		}
	}
}
void main()
{
	float a[MAX];
	int n,tieptuc;
quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}