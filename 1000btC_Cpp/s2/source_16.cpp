
#include<stdio.h>
#include<conio.h>
#include<math.h>
void tinh(float &x,int &n)
{
	int i;
	float s=0,s1=0;
	printf("Nhap vao x=");
	scanf("%f",&x);
	do{
	printf("Nhap vao n(n>=1):n=");
	scanf("%d",&n);
	if(n<1)
		printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
	else
		break;
	}while(n<1);
	for(i=1;i<=n;i++)
	{
		 s+=i;
		s1+=pow(x,i)/s;
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