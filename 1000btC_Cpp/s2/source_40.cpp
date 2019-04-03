
#include<stdio.h>
#include<conio.h>
void chusodaonguoc(int &n)
{
	do{
		printf("Nhap vao so nguyen duong n(n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
	printf("\nChu so dao nguoc cua so %d la:",n); 
		if(n>=0&&n<=9)
			printf("%d",n);
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			printf("%d",b);
			printf("%d",a);
		}
		if(n>=100&&n<=999)
		{
			int c=n%10;
			int d=n/10;
			int e=d/10;
			int f=d%10;
			printf("%d",c);
			printf("%d",f);
			printf("%d",e);
		}
		if(n>=1000&&n<=9999)
		{
			int g=n%10;
			int h=n/10;
			int i=h%10;
			int j=h/10;
			int k=j%10;
			int l=j/10;
			printf("%d",g);
			printf("%d",i);
			printf("%d",k);
			printf("%d",l);
		}
		if(n>=10000&&n<=99999)
		{
			int m=n%10;
			int o=n/10;
			int p=o%10;
			int q=o/10;
			int r=q%10;
			int s=q/10;
			int t=s%10;
			int u=s/10;
			printf("%d",m);
			printf("%d",p);
			printf("%d",r);
			printf("%d",t);
			printf("%d",u);
		}
}
void main()
{
	int n,tieptuc;
	quaylai:chusodaonguoc(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}