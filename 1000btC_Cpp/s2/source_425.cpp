
#include<stdio.h>
#include<conio.h>
void nhapdulieu(float &x,int &n)
{
	printf("\nNhap vao gia tri x=");
	scanf("%f",&x);
	printf("\nNhap vao gia tri n=");
	scanf("%d",&n);
}
float tinh(float x,int n)
{
	if(n==1)
		return x;
	if(n<1)
		return (tinh(x,n+1)*(1/x));
	return (tinh(x,n-1)*x);
}
void main()
{
	int n,tieptuc;
	float x;
	quaylai:nhapdulieu(x,n);
	float s=tinh(x,n);
	printf("\nKet qua la:%f",s);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}