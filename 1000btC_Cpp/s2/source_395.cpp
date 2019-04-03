
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatran(int a[MAX][MAX],int &m,int &n)
{
	do{
		printf("Nhap vao so dong:m=");
		scanf("%d",&m);
		if(m<1||m>MAX)
			printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(m<1||m>MAX);
	do{
		printf("Nhap vao so cot:n=");	
		scanf("%d",&n);
		if(n!=m)
			printf("So cot ban nhap vao khong thoa tinh chat la ma tran vuong!Xin vui long nhap lai!\n");
		else
			break;
	}while(n!=m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Nhap vao a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatmatran(int a[MAX][MAX],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%8d",a[i][j]);
		}
		printf("\n");
	}
}
void kiemtra(int a[MAX][MAX],int m,int n)
{
	int dem=0;
	for(int i=0;i<m-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int c=a[i][j]-a[j][i];
			if(c==0)
				dem++;
		}
	}
	int d=n*(n-1)/2; // n*(n-1)/2 la so phan tu cua tam giac tren duong cheo chinh (chinh la so phan tu doi xung ma ta dang xet)
	if(dem==d) // Moi lan ket qua = 0 thi dem se tang len 1.Neu dem ma bang dung voi so phan tu thi co nghia la tat ca cac phan tu deu bang nhau =>doi xung.
	printf("Ma tran nay doi xung qua duong cheo chinh\n");
	else
	printf("Ma tran nay khong co doi xung qua duong cheo chinh\n");
}
void main()
{
	int a[MAX][MAX],m,n,tieptuc;
	quaylai:nhapmatran(a,m,n);
	xuatmatran(a,m,n);
	kiemtra(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}