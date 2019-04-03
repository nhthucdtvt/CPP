
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define MAX 100
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
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void xulydulieu(float a[MAX],int n)
{
    int i,m;
    float dm,d,x;
    printf("Nhap vao x:");
    scanf("%f",&x);
    m=0;
    dm=fabs(x-a[0]);
    for(i=1;i<n;i++)
    {
        d=fabs(x-a[i]); // fabs là hàm xác định trị tuyệt đối của số thực,nếu là số nguyên thì là abs
        if(d>dm) //nếu muốn gần giá trị x nhất thì: d<dm
        {
            dm=d;
            m=i;
        }
    }
    printf("\nGia tri trong mang xa gia tri x nhat la:%f tai vi tri:%d",a[m],m); // ở đây do ta đã gán m=i cho nên ta phải để là a[m],nếu để a[i] sẽ sai.
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