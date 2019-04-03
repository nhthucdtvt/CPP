
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
#include<math.h>
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
	printf("\n>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void tinhtong(float a[MAX],int n)
{
	float s=0,Co;
	bool Co=false;
	int dem=0;
	printf("Cac gia tri lon hon tri tuyet doi cua gia tri dung lien sau no la:");
	for(int i=0;i<n;i++)
	{	
		if(a[i]>fabs(a[i+1])) //fabs:trị tuyệt đối của số thực.
		{
			printf("%16f",a[i]);
			dem++;
			s+=a[i];
			Co=true;
		}
	}
	if(Co==true)
	{
		printf("\nTrong mang co %d gia tri thoa man yeu cau de bai",dem);
		printf("\nTong tat ca cac gia tri lon hon tri tuyet doi cua gia tri dung lien sau no la:%f",s);
	}
	else
	printf("\nKhong co gia tri nao trong mang thoa man yeu cau de bai");	
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	tinhtong(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}