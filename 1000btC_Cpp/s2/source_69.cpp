
#include<stdio.h>
#include<conio.h>
#include<math.h>
void xulydulieu(int &i)
{
	double pow(double x,double y);
	printf("\nCac so Amstrong co trong doan [1,1000000] la:");
	for(i=1;i<=1000000;i++)
	{
		if(i>=0&&i<=9)
		{
			int v=pow(i,1);
			if(v==i)
				printf("%10d",i);
		}
		if(i>=10&&i<=99)
		{
			int a=i/10;
			int b=i%10;
			int w=pow(a,2)+pow(b,2);
			if(w==i)
				printf("%10d",i);
		}
		if(i>=100&&i<=999)
		{
			int c=i%10;
			int d=i/10;
			int e=d/10;
			int f=d%10;
			int x=pow(e,3)+pow(f,3)+pow(c,3);
			if(x==i)
				printf("%10d",i);
		}
		if(i>=1000&&i<=9999)
		{
			int g=i%10;
			int h=i/10;
			int q=h%10;
			int j=h/10;
			int k=j%10;
			int l=j/10;
			int y=pow(l,4)+pow(k,4)+pow(q,4)+pow(g,4);
			if(y==i)
				printf("%10d",i);
		}
		if(i>=10000&&i<=99999)
		{
			int m=i%10;
			int o=i/10;
			int p=o%10;
			int q=o/10;
			int r=q%10;
			int s=q/10;
			int t=s%10;
			int u=s/10;
			int z=pow(u,5)+pow(t,5)+pow(r,5)+pow(p,5)+pow(m,5);
			if(z==i)
				printf("%10d",i);
		}
		if(i>=100000&&i<=999999)
		{
			int ab=i%10;
			int bc=i/10;
			int cd=bc%10;
			int de=bc/10;
			int ef=de%10;
			int fg=de/10;
			int gh=fg%10;
			int hi=fg/10;
			int ij=hi%10;
			int jk=hi/10;
			int xyz=pow(jk,6)+pow(ij,6)+pow(gh,6)+pow(ef,6)+pow(cd,6)+pow(ab,6);
			if(xyz==i)
				printf("%10d",i);
		}
		//ở đây lẽ ra còn phải xét đến trường hợp 1000000 nhưng dễ dàng nhận thấy 1000000 không bao giờ thỏa là số Amstrong => khỏi cần xét.
	}
}
void main()
{
	int i,tieptuc;
	quaylai:xulydulieu(i);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}