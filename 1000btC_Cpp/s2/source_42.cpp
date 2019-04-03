
#include<stdio.h>
#include<conio.h>
void chusolonnhatvanhonhat(int &n)
{
	int max,min,dem=0,dem1=0,dem3=0,dem4=0,dem6=0,dem7=0,dem8=0,dem10=0,dem11=0,dem12=0,dem14=0,dem15=0,dem16=0,dem17=0,dem19=0,dem20=0,dem21=0,dem22=0,dem24=0,dem25=0,dem26=0,dem27=0,dem28=0,dem30=0,dem31=0,dem32=0,dem33=0,dem34=0;
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
			dem++;
			printf("\nChu so lon nhat cua so %d la:%d",n,n);
			printf("\nSo lan xuat hien chu so lon nhat la:%d",dem);
			printf("\nChu so be nhat cua so %d la:%d",n,n);
			printf("\nSo lan xuat hien chu so nho nhat la:%d",dem);
		}
		if(n>=10&&n<=99)
		{
			int a=n/10;
			int b=n%10;
			printf("%4d",a);
			printf("%4d",b);
			max=a>b ? a:b;
			min=a<b ? a:b;
			if(max==a)
				dem++;
			if(max==b)
				dem1++;
			int dem2=dem+dem1;
			if(min==a)
				dem3++;
			if(min==b)
				dem4++;
			int dem5=dem3+dem4;
			printf("\nChu so lon nhat cua so %d la:%d",n,max);
			printf("\nSo lan xuat hien chu so lon nhat la:%d",dem2);
			printf("\nChu so be nhat cua so %d la:%d",n,min);
			printf("\nSo lan xuat hien chu so nho nhat la:%d",dem5);
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
			if(max==e)
				dem6++;
			if(max==f)
				dem7++;
			if(max==c)
				dem8++;
			int dem9=dem6+dem7+dem8;
			if(min==e)
				dem10++;
			if(min==f)
				dem11++;
			if(min==c)
				dem12++;
			int dem13=dem10+dem11+dem12;
			printf("\nChu so lon nhat cua so %d la:%d",n,max);
			printf("\nSo lan xuat hien chu so lon nhat la:%d",dem9);
			printf("\nChu so be nhat cua so %d la:%d",n,min);
			printf("\nSo lan xuat hien chu so nho nhat la:%d",dem13);
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
			if(max==l)
				dem14++;
			if(max==k)
				dem15++;
			if(max==i)
				dem16++;
			if(max==g)
				dem17++;
			int dem18=dem14+dem15+dem16+dem17;
			if(min==l)
				dem19++;
			if(min==k)
				dem20++;
			if(min==i)
				dem21++;
			if(min==g)
				dem22++;
			int dem23=dem19+dem20+dem21+dem22;
			printf("\nChu so lon nhat cua so %d la:%d",n,max);
			printf("\nSo lan xuat hien chu so lon nhat la:%d",dem18);
			printf("\nChu so be nhat cua so %d la:%d",n,min);
			printf("\nSo lan xuat hien chu so nho nhat la:%d",dem23);
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
			if(max==u)
				dem24++;
			if(max==t)
				dem25++;
			if(max==r)
				dem26++;
			if(max==p)
				dem27++;
			if(max==m)
				dem28++;
			int dem29=dem24+dem25+dem26+dem27+dem28;
			if(min==u)
				dem30++;
			if(min==t)
				dem31++;
			if(min==r)
				dem32++;
			if(min==p)
				dem33++;
			if(min==m)
				dem34++;
			int dem35=dem30+dem31+dem32+dem33+dem34;
			printf("\nChu so lon nhat cua so %d la:%d",n,max);
			printf("\nSo lan xuat hien chu so lon nhat la:%d",dem29);
			printf("\nChu so be nhat cua so %d la:%d",n,min);
			printf("\nSo lan xuat hien chu so nho nhat la:%d",dem35);
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