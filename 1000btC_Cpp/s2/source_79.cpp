
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void color(int a)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,a);
}
void NhapSoNguyenDuongN(int &n)
{
	quaylai:printf("\nNhap vao so nguyen duong N=");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylai;
	}
}
void DemSoLuongChuSo(int n)
{
	int dem=0,t=n;
	while(t!=0)
	{
		dem+=1;
		t=t/10;
	}
	printf("\nSo %d co %d chu so",n,dem);
}
void KiemTraNguyenTo(int n)
{
	int f=1;
	if(n<2)
		f=0;
	for(int k=2;k<=n/2;k++)
	{
		if(n%k==0)
			f=0;
	}
	if(f==1)
		printf("\nSo %d la so nguyen to!",n);
	else
		printf("\nSo %d khong phai la so nguyen to!",n);
}
void DemSoLuongChuSoLonNhat(int n)
{
	int max,dem=0,dem1=0,dem6=0,dem7=0,dem8=0,dem14=0,dem15=0,dem16=0,dem17=0,dem24=0,dem25=0,dem26=0,dem27=0,dem28=0;
	if(n>=0&&n<=9)
	{
		dem++;
		printf("\nChu so lon nhat cua so %d la:%d",n,n);
		printf("\n");
		printf("\nSo lan xuat hien chu so lon nhat la:%d",dem);
	}
	if(n>=10&&n<=99)
	{
		int a=n/10;
		int b=n%10;
		max=a>b ? a:b;
		if(max==a)
			dem++;
		if(max==b)
			dem1++;
		int dem2=dem+dem1;
		printf("\nChu so lon nhat cua so %d la:%d",n,max);
		printf("\n");
		printf("\nSo lan xuat hien chu so lon nhat la:%d",dem2);
	}
	if(n>=100&&n<=999)
	{
		int c=n%10;
		int d=n/10;
		int e=d/10;
		int f=d%10;
		max=e>f ? e:f;
		max=max>c ? max:c;
		if(max==e)
			dem6++;
		if(max==f)
			dem7++;
		if(max==c)
			dem8++;
		int dem9=dem6+dem7+dem8;
		printf("\nChu so lon nhat cua so %d la:%d",n,max);
		printf("\n");
		printf("\nSo lan xuat hien chu so lon nhat la:%d",dem9);
	}
	if(n>=1000&&n<=9999)
	{
		int g=n%10;
		int h=n/10;
		int i=h%10;
		int j=h/10;
		int k=j%10;
		int l=j/10;
		max=l>k ? l:k;
		max=max>i ? max:i;
		max=max>g ? max:g;
		if(max==l)
			dem14++;
		if(max==k)
			dem15++;
		if(max==i)
			dem16++;
		if(max==g)
			dem17++;
		int dem18=dem14+dem15+dem16+dem17;
		printf("\nChu so lon nhat cua so %d la:%d",n,max);
		printf("\n");
		printf("\nSo lan xuat hien chu so lon nhat la:%d",dem18);
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
		max=u>t ? u:t;
		max=max>r ? max:r;
		max=max>p ? max:p;
		max=max>m ? max:m;
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
		printf("\nChu so lon nhat cua so %d la:%d",n,max);
		printf("\n");
		printf("\nSo lan xuat hien chu so lon nhat la:%d",dem29);
	}
}
void main()
{
	int n,tieptuc;
	quaylai:color(14);
	NhapSoNguyenDuongN(n);
	color(7);
	printf("\n");
	color(10);
	DemSoLuongChuSo(n);
	color(7);
	printf("\n");
	color(2);
	KiemTraNguyenTo(n);
	color(7);
	printf("\n");
	color(9);
	DemSoLuongChuSoLonNhat(n);
	color(7);
	printf("\n");
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}