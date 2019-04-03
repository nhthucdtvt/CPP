
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(float a[MAX],int &n)
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
		scanf("%f",&a[i]);
	}
}
void xuatmang(float a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void lietkeconduong(float a[MAX],int n)
{
	int ChieuDai;
	for (int i=0; i<n; i++)
	{
		for (ChieuDai = 2+i; ChieuDai<=n; ChieuDai++) //=> mảng con lớn hơn 1 phần tử => bắt đầu bằng 2 => với i bắt đầu từ 0 thì chiều dài phải = 2 + i.
		{
			for(int j=i; j<ChieuDai; j++)
			{
				if(a[j]>=0) // điều kiện dương.
					printf("%16f", a[j]);
			}
			printf("\n");
		}
	}
} 
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\n>>>>>>>>>>>>>CAC DAY CON TOAN DUONG CO DO DAI LON HON 1 PHAN TU LA:<<<<<<<<<<<<<<<<<\n");
	lietkeconduong(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
