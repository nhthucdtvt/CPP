
#include<stdio.h>
#include<conio.h>
#define bool
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
void tongcacchuso(int n)
{
	printf("\nTong cac chu so cua so %d la:",n); 
		if(n>=0&&n<=9)
			printf("%4d",n);
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			int v=a+b;
			printf("%4d",v);
		}
		if(n>=100&&n<=999)
		{
			int c=n%10;
			int d=n/10;
			int e=d/10;
			int f=d%10;
			int w=e+f+c;
			printf("%4d",w);
		}
		if(n>=1000&&n<=9999)
		{
			int g=n%10;
			int h=n/10;
			int i=h%10;
			int j=h/10;
			int k=j%10;
			int l=j/10;
			int x=l+k+i+g;
			printf("%4d",x);
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
			int y=u+t+r+p+m;
			printf("%4d",y);
		}
}
void tichcacchuso(int n)
{
	printf("\nTich cac chu so cua so %d la:",n); 
		if(n>=0&&n<=9)
			printf("%4d",n);
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			int v=a*b;
			printf("%4d",v);
		}
		if(n>=100&&n<=999)
		{
			int c=n%10;
			int d=n/10;
			int e=d/10;
			int f=d%10;
			int w=e*f*c;
			printf("%4d",w);
		}
		if(n>=1000&&n<=9999)
		{
			int g=n%10;
			int h=n/10;
			int i=h%10;
			int j=h/10;
			int k=j%10;
			int l=j/10;
			int x=l*k*i*g;
			printf("%4d",x);
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
			int y=u*t*r*p*m;
			printf("%4d",y);
		}
}
void lietkevademcacchusole(int n)
{
	int dem=0,dem1=0,dem2=0,dem3=0,dem4=0,dem5=0,dem6=0,dem7=0,dem8=0,dem9=0,dem10=0,dem11=0,dem12=0,dem13=0,dem14=0;
	int Co,Co1,Co2,Co3,Co4;
	int tinh,tinh1,tinh2,tinh3;
	bool Co=false;
	bool Co1=false;
	bool Co2=false;
	bool Co3=false;
	bool Co4=false;
	printf("\nCac chu so le cua so %d la:",n);
		if(n>=0&&n<=9)
		{
			if(n%2!=0)
			{
			printf("%4d",n);
			dem++;
			Co=true;
			}
		}
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			if(a%2!=0)
			{
			printf("%4d",a);
			dem1++;
			Co1=true;
			}
			if(b%2!=0)
			{
			printf("%4d",b);
			dem2++;
			Co1=true;
			}
		}
		if(n>=100&&n<=999)
		{
			int c=n%10;
			int d=n/10;
			int e=d/10;
			int f=d%10;
			if(e%2!=0)
			{
			printf("%4d",e);
			dem3++;
			Co2=true;
			}
			if(f%2!=0)
			{
			printf("%4d",f);
			dem4++;
			Co2=true;
			}
			if(c%2!=0)
			{
			printf("%4d",c);
			dem5++;
			Co2=true;
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
			if(l%2!=0)
			{
			printf("%4d",l);
			dem6++;
			Co3=true;
			}
			if(k%2!=0)
			{
			printf("%4d",k);
			dem7++;
			Co3=true;
			}
			if(i%2!=0)
			{
			printf("%4d",i);
			dem8++;
			Co3=true;
			}
			if(g%2!=0)
			{
			printf("%4d",g);
			dem9++;
			Co3=true;
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
			if(u%2!=0)
			{
			printf("%4d",u);
			dem10++;
			Co4=true;
			}
			if(t%2!=0)
			{
			printf("%4d",t);
			dem11++;
			Co4=true;
			}
			if(r%2!=0)
			{
			printf("%4d",r);
			dem12++;
			Co4=true;
			}
			if(p%2!=0)
			{
			printf("%4d",p);
			dem13++;
			Co4=true;
			}
			if(m%2!=0)
			{
			printf("%4d",m);
			dem14++;
			Co4=true;
			}
		}
	tinh=dem1+dem2;
	tinh1=dem3+dem4+dem5;
	tinh2=dem6+dem7+dem8+dem9;
	tinh3=dem10+dem11+dem12+dem13+dem14;
	if(Co==true)
		printf("\nSo %d co %d chu so le",n,dem);
	if(Co1==true)
		printf("\nSo %d co %d chu so le",n,tinh);
	if(Co2==true)
		printf("\nSo %d co %d chu so le",n,tinh1);
	if(Co3==true)
		printf("\nSo %d co %d chu so le",n,tinh2);
	if(Co4==true)
		printf("\nSo %d co %d chu so le",n,tinh3);
}
void lietkevademcacchusochan(int n)
{
	int dem=0,dem1=0,dem2=0,dem3=0,dem4=0,dem5=0,dem6=0,dem7=0,dem8=0,dem9=0,dem10=0,dem11=0,dem12=0,dem13=0,dem14=0;
	int Co,Co1,Co2,Co3,Co4;
	int tinh,tinh1,tinh2,tinh3;
	bool Co=false;
	bool Co1=false;
	bool Co2=false;
	bool Co3=false;
	bool Co4=false;
	printf("\nCac chu so chan cua so %d la:",n);
		if(n>=0&&n<=9)
		{
			if(n%2==0)
			{
			printf("%4d",n);
			dem++;
			Co=true;
			}
		}
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			if(a%2==0)
			{
			printf("%4d",a);
			dem1++;
			Co1=true;
			}
			if(b%2==0)
			{
			printf("%4d",b);
			dem2++;
			Co1=true;
			}
		}
		if(n>=100&&n<=999)
		{
			int c=n%10;
			int d=n/10;
			int e=d/10;
			int f=d%10;
			if(e%2==0)
			{
			printf("%4d",e);
			dem3++;
			Co2=true;
			}
			if(f%2==0)
			{
			printf("%4d",f);
			dem4++;
			Co2=true;
			}
			if(c%2==0)
			{
			printf("%4d",c);
			dem5++;
			Co2=true;
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
			if(l%2==0)
			{
			printf("%4d",l);
			dem6++;
			Co3=true;
			}
			if(k%2==0)
			{
			printf("%4d",k);
			dem7++;
			Co3=true;
			}
			if(i%2==0)
			{
			printf("%4d",i);
			dem8++;
			Co3=true;
			}
			if(g%2==0)
			{
			printf("%4d",g);
			dem9++;
			Co3=true;
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
			if(u%2==0)
			{
			printf("%4d",u);
			dem10++;
			Co4=true;
			}
			if(t%2==0)
			{
			printf("%4d",t);
			dem11++;
			Co4=true;
			}
			if(r%2==0)
			{
			printf("%4d",r);
			dem12++;
			Co4=true;
			}
			if(p%2==0)
			{
			printf("%4d",p);
			dem13++;
			Co4=true;
			}
			if(m%2==0)
			{
			printf("%4d",m);
			dem14++;
			Co4=true;
			}
		}
	tinh=dem1+dem2;
	tinh1=dem3+dem4+dem5;
	tinh2=dem6+dem7+dem8+dem9;
	tinh3=dem10+dem11+dem12+dem13+dem14;
	if(Co==true)
		printf("\nSo %d co %d chu so chan",n,dem);
	if(Co1==true)
		printf("\nSo %d co %d chu so chan",n,tinh);
	if(Co2==true)
		printf("\nSo %d co %d chu so chan",n,tinh1);
	if(Co3==true)
		printf("\nSo %d co %d chu so chan",n,tinh2);
	if(Co4==true)
		printf("\nSo %d co %d chu so chan",n,tinh3);
}
void main()
{
	int n,tieptuc;
	quaylai:demchuso(n);
	lietkechuso(n);
	tongcacchuso(n);
	tichcacchuso(n);
	lietkevademcacchusole(n);
	lietkevademcacchusochan(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}