
#include<stdio.h>
#include<conio.h>
void lietkevakiemtra(int &n)
{
	do{
		printf("Nhap vao so nguyen duong n(n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
	printf("\nCac chu so cua so %d la:",n); 
		if(n>=0&&n<=9)
		{
			printf("%4d",n);
			printf("\nSo %d la so doi xung",n);
		}
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			printf("%4d",a);
			printf("%4d",b);
			if(a==b)
				printf("\nSo %d la so doi xung",n);
			else
				printf("\nSo %d khong phai la so doi xung",n);
		}
		if(n>=100&&n<=999)
		{
			int c=n%10;
			int d=n/10;
			int e=d/10;
			int f=d%10;
			printf("%4d",e);
			printf("%4d",f);
			printf("%4d",c);
			if(e==c)
				printf("\nSo %d la so doi xung",n);
			else
				printf("\nSo %d khong phai la so doi xung",n);
		}
		if(n>=1000&&n<=9999)
		{
			int g=n%10;
			int h=n/10;
			int i=h%10;
			int j=h/10;
			int k=j%10;
			int l=j/10;
			printf("%4d",l);
			printf("%4d",k);
			printf("%4d",i);
			printf("%4d",g);
			if(l==g&&k==i)
				printf("\nSo %d la so doi xung",n);
			else
				printf("\nSo %d khong phai la so doi xung",n);
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
			printf("%4d",u);
			printf("%4d",t);
			printf("%4d",r);
			printf("%4d",p);
			printf("%4d",m);
			if(u==m&&t==p)
				printf("\nSo %d la so doi xung",n);
			else
				printf("\nSo %d khong phai la so doi xung",n);
		}
}
void main()
{
	int n,tieptuc;
	quaylai:lietkevakiemtra(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}