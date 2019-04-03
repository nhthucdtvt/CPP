
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
void xulydulieu(float a[MAX],int n)
{
    int vitri=0,Co,dem=0;
    bool Co=false;
	printf("Vi tri thoa man yeu cau cua bai toan la:");
    for(int i=2;i<n;i++)
    {
       float b=a[i]*a[i-2];
        if(a[i-1]==b)
        {
			printf("%4d",i-1);
			dem++;
			Co=true;
        }
    }
    if(Co==true)
    printf("\nTrong mang co %d vi tri thoa man yeu cau cua bai toan",dem);
	else
	printf("\n-1");
}
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}