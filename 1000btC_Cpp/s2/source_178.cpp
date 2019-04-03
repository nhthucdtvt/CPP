
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang (int a[MAX],int &n)
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
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[MAX],int n)
{
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			dem++;
		}
	}
	if(dem>(n-dem))	// ở đây sau khi ta đếm ra số lượng các giá trị chẵn trong mảng thì (n-dem) chính là số lượng các giá trị lẻ trong mảng.Ta khỏi phải mất công đặt thêm 1 biến để đi tìm ra số lượng các giá trị lẻ.
		printf("\n-1");
	else if(dem==(n-dem))
		printf("\n0");
	else if(dem<(n-dem))
		printf("\n1");
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
	goto quaylai;
}