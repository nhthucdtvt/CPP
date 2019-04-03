
#include<stdio.h>
#include<conio.h>
void demchuso(int &n)
{
	do{
		printf("Nhap vao so nguyen duong n(n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
	if(n>=0&&n<=9)
		printf("\nSo %d co 1 chu so",n);
	if(n>=10&&n<=99)
		printf("\nSo %d co 2 chu so",n);
	if(n>=100&&n<=999)
		printf("\nSo %d co 3 chu so",n);
	if(n>=1000&&n<=9999)
		printf("\nSo %d co 4 chu so",n);
	if(n>=10000&&n<=99999)
		printf("\nSo %d co 5 chu so",n);
}
void lietkechuso(int n)
{
	printf("\nCac chu so cua so %d la:",n); 
		if(n>=0&&n<=9)
			printf("%4d",n);
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			printf("%4d",a);
			printf("%4d",b);
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
		}
}
void tichcacchusole(int n)
{
	printf("\nTich cac chu so le so %d la:",n); 
		if(n>=0&&n<=9)
		{
			if(n%2!=0)
			printf("%4d",n);
		}
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			if(a%2!=0&&b%2!=0)
			{
				int ab=a*b;
				printf("%4d",ab);
			}
			if(a%2!=0&&b%2==0)
				printf("%4d",a);
			if(b%2!=0&&a%2==0)
				printf("%4d",b);
		}
		if(n>=100&&n<=999)
		{
			int c=n%10;
			int d=n/10;
			int e=d/10;
			int f=d%10;
			if(e%2!=0&&f%2!=0&&c%2!=0)
			{
				int w=e*f*c;
				printf("%4d",w);
			}
			// xét lần lượt từng chữ số
			if(e%2!=0&&f%2==0&&c%2==0)
				printf("%4d",e);
			if(e%2==0&&f%2!=0&&c%2==0)
				printf("%4d",f);
			if(e%2==0&&f%2==0&&c%2!=0)
				printf("%4d",c);
				// xét lần lượt 2 chữ số
			if(e%2!=0&&f%2!=0&&c%2==0)
			{
				int ab=e*f;
				printf("%4d",ab);
			}
			if(e%2==0&&f%2!=0&&c%2!=0)
			{
				int bc=f*c;
				printf("%4d",bc);
			}
			if(e%2!=0&&f%2==0&&c%2!=0)
			{
				int cd=e*c;
				printf("%4d",cd);
			}
		}
		if(n>=1000&&n<=9999)
		{
			int g=n%10;
			int h=n/10;
			int i=h%10;
			int j=h/10;
			int k=j%10;
			int l=j/10;
			if(l%2!=0&&k%2!=0&&i%2!=0&&g%2!=0)
			{
				int x=l*k*i*g;
				printf("%4d",x);
			}
			// xét lần lượt từng chữ số
			if(l%2!=0&&k%2==0&&i%2==0&&g%2==0)
				printf("%4d",l);
			if(l%2==0&&k%2!=0&&i%2==0&&g%2==0)
				printf("%4d",k);
			if(l%2==0&&k%2==0&&i%2!=0&&g%2==0)
				printf("%4d",i);
			if(l%2==0&&k%2==0&&i%2==0&&g%2!=0)
				printf("%4d",g);
			// xét lần lượt 2 chữ số
			if(l%2!=0&&k%2!=0&&i%2==0&&g%2==0)
			{
				int de=l*k;
				printf("%4d",de);
			}
			if(l%2==0&&k%2!=0&&i%2!=0&&g%2==0)
			{
				int ef=k*i;
				printf("%4d",ef);
			}
			if(l%2==0&&k%2==0&&i%2!=0&&g%2!=0)
			{
				int fg=i*g;
				printf("%4d",fg);
			}
			if(l%2!=0&&k%2==0&&i%2==0&&g%2!=0)
			{
				int gh=l*g;
				printf("%4d",gh);
			}
			if(l%2!=0&&k%2==0&&i%2!=0&&g%2==0)
			{
				int hi=l*i;
				printf("%4d",hi);
			}
			if(l%2==0&&k%2!=0&&i%2==0&&g%2!=0)
			{
				int ij=k*g;
				printf("%4d",ij);
			}
			// xét lần lượt 3 chữ số
			if(l%2!=0&&k%2!=0&&i%2!=0&&g%2==0)
			{
				int jk=l*k*i;
				printf("%4d",jk);
			}
			if(l%2!=0&&k%2!=0&&i%2==0&&g%2!=0)
			{
				int kl=l*k*g;
				printf("%4d",kl);
			}
			if(l%2!=0&&k%2==0&&i%2!=0&&g%2!=0)
			{
				int lm=l*i*g;
				printf("%4d",lm);
			}
			if(l%2==0&&k%2!=0&&i%2!=0&&g%2!=0)
			{
				int mn=k*i*g;
				printf("%4d",mn);
			}
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
			if(u%2!=0&&t%2!=0&&r%2!=0&&p%2!=0&&m%2!=0)
			{
				int y=u*t*r*p*m;
				printf("%4d",y);
			}
				// xét lần lượt từng chữ số 
			if(u%2!=0&&t%2==0&&r%2==0&&p%2==0&&m%2==0)
				printf("%4d",u);
			if(u%2==0&&t%2!=0&&r%2==0&&p%2==0&&m%2==0)
				printf("%4d",t);
			if(u%2==0&&t%2==0&&r%2!=0&&p%2==0&&m%2==0)
				printf("%4d",r);
			if(u%2==0&&t%2==0&&r%2==0&&p%2!=0&&m%2==0)
				printf("%4d",p);
			if(u%2==0&&t%2==0&&r%2==0&&p%2==0&&m%2!=0)
				printf("%4d",m);
				// xét lần lượt 2 chữ số
			if(u%2!=0&&t%2!=0&&r%2==0&&p%2==0&&m%2==0)
			{
				int no=u*t;
				printf("%4d",no);
			}
			if(u%2!=0&&t%2==0&&r%2!=0&&p%2==0&&m%2==0)
			{
				int op=u*r;
				printf("%4d",op);
			}
			if(u%2!=0&&t%2==0&&r%2==0&&p%2!=0&&m%2==0)
			{
				int pq=u*p;
				printf("%4d",pq);
			}
			if(u%2!=0&&t%2==0&&r%2==0&&p%2==0&&m%2!=0)
			{
				int qr=u*m;
				printf("%4d",qr);
			}
			if(u%2==0&&t%2!=0&&r%2!=0&&p%2==0&&m%2==0)
			{
				int rs=t*r;
				printf("%4d",rs);
			}
			if(u%2==0&&t%2!=0&&r%2==0&&p%2!=0&&m%2==0)
			{
				int st=t*p;
				printf("%4d",st);
			}
			if(u%2==0&&t%2!=0&&r%2==0&&p%2==0&&m%2!=0)
			{
				int tu=t*m;
				printf("%4d",tu);
			}
			if(u%2==0&&t%2==0&&r%2!=0&&p%2!=0&&m%2==0)
			{
				int uv=r*p;
				printf("%4d",uv);
			}
			if(u%2==0&&t%2==0&&r%2!=0&&p%2==0&&m%2!=0)
			{
				int vw=r*m;
				printf("%4d",vw);
			}
			if(u%2==0&&t%2==0&&r%2==0&&p%2!=0&&m%2!=0)
			{
				int wx=p*m;
				printf("%4d",wx);
			}
				// xét lần lượt 3 chữ số
			if(u%2!=0&&t%2!=0&&r%2!=0&&p%2==0&&m%2==0)
			{
				int xy=u*t*r;
				printf("%4d",xy);
			}
			if(u%2!=0&&t%2!=0&&r%2==0&&p%2!=0&&m%2==0)
			{
				int yz=u*t*p;
				printf("%4d",yz);
			}
			if(u%2!=0&&t%2!=0&&r%2==0&&p%2==0&&m%2!=0)
			{
				int abc=u*t*m;
				printf("%4d",abc);
			}
			if(u%2!=0&&t%2==0&&r%2!=0&&p%2!=0&&m%2==0)
			{
				int bcd=u*r*p;
				printf("%4d",bcd);
			}
			if(u%2!=0&&t%2==0&&r%2!=0&&p%2==0&&m%2!=0)
			{
				int cde=u*r*m;
				printf("%4d",cde);
			}
			if(u%2!=0&&t%2==0&&r%2==0&&p%2!=0&&m%2!=0)
			{
				int def=u*p*m;
				printf("%4d",def);
			}
			if(u%2==0&&t%2!=0&&r%2!=0&&p%2!=0&&m%2==0)
			{
				int efg=t*r*p;
				printf("%4d",efg);
			}
			if(u%2==0&&t%2!=0&&r%2!=0&&p%2==0&&m%2!=0)
			{
				int fgh=t*r*m;
				printf("%4d",fgh);
			}
			if(u%2==0&&t%2==0&&r%2!=0&&p%2!=0&&m%2!=0)
			{
				int ghi=r*p*m;
				printf("%4d",ghi);
			}
			//	xét lần lượt 4 chữ số
			if(u%2!=0&&t%2!=0&&r%2!=0&&p%2!=0&&m%2==0)
			{
				int hij=u*t*r*p;
				printf("%4d",hij);
			}
			if(u%2!=0&&t%2!=0&&r%2!=0&&p%2==0&&m%2!=0)
			{
				int ijk=u*t*r*m;
				printf("%4d",ijk);
			}
			if(u%2!=0&&t%2!=0&&r%2==0&&p%2!=0&&m%2!=0)
			{
				int jkl=u*t*p*m;
				printf("%4d",jkl);
			}
			if(u%2==0&&t%2!=0&&r%2!=0&&p%2!=0&&m%2!=0)
			{
				int klm=t*r*p*m;
				printf("%4d",klm);
			}
			if(u%2!=0&&t%2==0&&r%2!=0&&p%2!=0&&m%2!=0)
			{
				int lmn=u*r*p*m;
				printf("%4d",lmn);
			}
		}
}
void main()
{
	int n,tieptuc;
	quaylai:demchuso(n);
	lietkechuso(n);
	tichcacchusole(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
