
#include<stdio.h>
#include<conio.h>
#include<math.h>
double giaithua(double n)
{
	if(n==0||n==1)	return 1;
	return n*giaithua(n-1);
}
void tinh(float &x,int &n)
{
	int i;
	float s1=0;
	printf("Nhap vao x=");
	scanf("%f",&x);
	do{
	printf("Nhap vao n(n>=0):n=");
	scanf("%d",&n);
	if(n<0)
		printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
	else
		break;
	}while(n<0);
	for(i=0;i<=n;i++)
	{
		s1+=pow(x,2*i+1)/giaithua(2*i+1);
	}
	printf("Ket qua la:%f",s1);
}
void main()
{
	int n,tieptuc;
	float x;
	quaylai:tinh(x,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}