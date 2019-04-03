
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(float a[MAX],int &n)
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
		scanf("%f",&a[i]);
	}
}
void xuatmang(float a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
float timlonnhat(float a[MAX],int n)
{
	if(n==1)
		return a[0];
	float lonnhat=timlonnhat(a,n-1);
	if(a[n-1]>lonnhat)
		lonnhat=a[n-1];
	return lonnhat;
}
void main()
{
	int n,tieptuc;
	float a[MAX];
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<\n");
	xuatmang(a,n);
	float s=timlonnhat(a,n);
	printf("\nGia tri lon nhat co trong mang la:%f",s);
	printf("\nBan co muon tiep tuc chay chuong trinh nua khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}