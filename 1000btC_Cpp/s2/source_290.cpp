
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(int a[MAX],int &n,int &M)
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
	printf("Nhap vao M=");
	scanf("%d",&M);
}
void xuatmang(int a[MAX],int n,int M)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void TongMangConBangM(int a[MAX], int n,int M)
{
	for (int vi_tri_goc = 0 ; vi_tri_goc < n ; vi_tri_goc++)
	{
		for (int chieu_dai_mang_con = vi_tri_goc + 1 ; chieu_dai_mang_con < n ; chieu_dai_mang_con++)
		{
			int tong = 0;
			for (int vi_tri_ptu= vi_tri_goc; vi_tri_ptu < chieu_dai_mang_con ; vi_tri_ptu++)
			{
				tong +=a[vi_tri_ptu];
			}
			if (tong == M)
			{
				//Xuất cái mảng vừa tìm được.
				for (int k = vi_tri_goc; k < chieu_dai_mang_con ; k++)
					printf("%4d",a[k]);
				printf("\n");
			}
		}
	}
} 
void main()
{
	int a[MAX],n,M,tieptuc;
	quaylai:nhapmang(a,n,M);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n,M);
	printf("\n>>>>>>>>>>>>>CAC DAY CON CO TONG BANG M LA:<<<<<<<<<<<<<<<<<\n");
	TongMangConBangM(a,n,M);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
