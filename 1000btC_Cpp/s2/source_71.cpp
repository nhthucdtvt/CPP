
#include<stdio.h>
#include<conio.h>
#include<math.h>
void xulydulieu(int &n)
{
		double pow(double x,double y);
		do{
			printf("Nhap vao so nguyen duong n(n>=0):n=");
			scanf("%d",&n);
			if(n<0)
				printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
			else
				break;
		}while(n<0);
		if(n>=0&&n<=9)
		{
			int v=pow(n,1);
			if(v==n)
				printf("\nSo %d la so Amstrong",n);
			else
				printf("\nSo %d khong phai la so Amstrong",n);
		}
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			int w=pow(a,2)+pow(b,2);
			if(w==n)
				printf("\nSo %d la so Amstrong",n);
			else
				printf("\nSo %d khong phai la so Amstrong",n);
		}
		if(n>=100&&n<=999)
		{
			int c=n%10;
			int d=n/10;
			int e=d/10;
			int f=d%10;
			int x=pow(e,3)+pow(f,3)+pow(c,3);
			if(x==n)
				printf("\nSo %d la so Amstrong",n);
			else
				printf("\nSo %d khong phai la so Amstrong",n);
		}
		if(n>=1000&&n<=9999)
		{
			int g=n%10;
			int h=n/10;
			int i=h%10;
			int j=h/10;
			int k=j%10;
			int l=j/10;
			int y=pow(l,4)+pow(k,4)+pow(i,4)+pow(g,4);
			if(y==n)
				printf("\nSo %d la so Amstrong",n);
			else
				printf("\nSo %d khong phai la so Amstrong",n);
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
			int z=pow(u,5)+pow(t,5)+pow(r,5)+pow(p,5)+pow(m,5);
			if(z==n)
				printf("\nSo %d la so Amstrong",n);
			else
				printf("\nSo %d khong phai la so Amstrong",n);
		}
		if(n>=100000&&n<=999999)
		{
			int ab=n%10;
			int bc=n/10;
			int cd=bc%10;
			int de=bc/10;
			int ef=de%10;
			int fg=de/10;
			int gh=fg%10;
			int hi=fg/10;
			int ij=hi%10;
			int jk=hi/10;
			int xyz=pow(jk,6)+pow(ij,6)+pow(gh,6)+pow(ef,6)+pow(cd,6)+pow(ab,6);
			if(xyz==n)
				printf("\nSo %d la so Amstrong",n);
			else
				printf("\nSo %d khong phai la so Amstrong",n);
		}
}
void main()
{
	int n,tieptuc;
	quaylai:xulydulieu(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}