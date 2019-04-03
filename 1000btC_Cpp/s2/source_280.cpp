
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(int a[MAX],int &n)
{
	do{
		printf("Nhap vao so phan tu cua mang:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1||n>MAX);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void lietkecon(int a[MAX],int n)
{
	int ChieuDai;
	for (int i=0; i<n; i++)
	{
		for (ChieuDai = 3+i; ChieuDai<=n; ChieuDai++) //=> mảng con lớn hơn 2 phần tử => bắt đầu bằng 3 => với i bắt đầu từ 0 thì chiều dài phải = 3 + i.
		{
			for(int j=i; j<ChieuDai; j++)
			{
				printf("%4d", a[j]);
			}
			printf("\n");
		}
	}
} 
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>CAC MANG CON CO DO DAI LON HON 2 PHAN TU LA:<<<<<<<<<<<<<<<<<\n");
	lietkecon(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}