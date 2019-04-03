
#include<stdio.h>
#include<conio.h>
void chusolonnhatvanhonhat(int &n)
{
	int max,min;
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
			printf("\nChu so lon nhat cua so %d la:%d",n,n);
			printf("\nChu so be nhat cua so %d la:%d",n,n);
		}
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			printf("%4d",a);
			printf("%4d",b);
			max=a>b ? a:b;
			min=a<b ? a:b;
			printf("\nChu so lon nhat cua so %d la:%d",n,max);
			printf("\nChu so be nhat cua so %d la:%d",n,min);
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
			max=e>f ? e:f;
			max=max>c ? max:c;
			min=e<f ? e:f;
			min=min<c ? min:c;
			printf("\nChu so lon nhat cua so %d la:%d",n,max);
			printf("\nChu so be nhat cua so %d la:%d",n,min);
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
			max=l>k ? l:k;
			max=max>i ? max:i;
			max=max>g ? max:g;
			min=l<k ? l:k;
			min=min<i ? min:i;
			min=min<g ? min:g;
			printf("\nChu so lon nhat cua so %d la:%d",n,max);
			printf("\nChu so be nhat cua so %d la:%d",n,min);
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
			max=u>t ? u:t;
			max=max>r ? max:r;
			max=max>p ? max:p;
			max=max>m ? max:m;
			min=u<t ? u:t;
			min=min<r ? min:r;
			min=min<p ? min:p;
			min=min<m ? min:m;
			printf("\nChu so lon nhat cua so %d la:%d",n,max);
			printf("\nChu so be nhat cua so %d la:%d",n,min);
		}
}
void main()
{
	int n,tieptuc;
	quaylai:chusolonnhatvanhonhat(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}