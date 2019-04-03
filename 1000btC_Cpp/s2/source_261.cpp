
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(int a[MAX],int &n)
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
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xoa(int a[MAX],int &n,int k) // phải truyền n theo kiểu tham biến : &n.
{
	for(int i=k;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--; // giảm n xuống =>phải có
}
int ktcp(int k)
{
	for(int i=0;i<=k;i++)
	{
		if(i*i==k)
			return 1;
	}
	return 0;
}
void xoachinhphuong(int a[MAX],int &n) // phải truyền n theo kiểu tham biến : &n thì lúc xóa mới xuất ra đúng được.
{
	for(int i=0;i<n;i++)
	{
		if(ktcp(a[i])==1)
		{
			xoa(a,n,i);
			i--; // i giảm dần xuống => phải có .
		}
	}
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	xoachinhphuong(a,n);
	printf("\n>>>>>>>>>>>>MANG SAU KHI XOA LA:<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
