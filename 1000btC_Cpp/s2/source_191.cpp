
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhap2mang(float a[MAX],float b[MAX],int &n,int &m)
{
	do{
		printf("Nhap vao so phan tu cua mang a:n=");
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
	do{
		printf("Nhap vao so phan tu cua mang b:m=");
		scanf("%d",&m);
		if(m<1||m>MAX)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(m<1||m>MAX);
	for(int j=0;j<m;j++)
	{
		printf("Nhap vao b[%d]=",j);
		scanf("%f",&b[j]);
	}
}
void xuat2mang(float a[MAX],float b[MAX],int n,int m)
{
	printf("\n>>>>>>>>>>>>>>MANG A VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
	printf("\n>>>>>>>>>>>>>>MANG B VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int j=0;j<m;j++)
	{
		printf("%16f",b[j]);
	}
	printf("\n");
}
int Dem(float a[MAX],float b[MAX], int n,int m) 
{ 
              int i,j,test,DemTam=0; 
              for (i=0; i<n; i++) 
              { 
                          test=1; 
                          for (j=0; j<m; j++) 
                          { 
                                      if (a[i]==b[j]) 
                                      { 
                                                  test = 0;
												  break; 
                                      } 
                          } 
                          if (test==1) 
                          { 
                                      DemTam++; 
                          } 
              } 
              for (j=0;j<m;j++) 
              { 
                          test=1; 
                          for (i=0; i<n;i++) 
                          { 
                                      if (b[j]==a[i]) 
                                      { 
                                                  test=0; break; 
                                      } 
                          } 
                          if (test==1) 
                          { 
                                      DemTam++; 
                          } 
              } 
              return DemTam; 
} 
void main()
{
	float a[MAX],b[MAX];
	int n,m,tieptuc;
	quaylai:nhap2mang(a,b,n,m);
	xuat2mang(a,b,n,m);
	int s=Dem(a,b,n,m);
	printf("\nSo luong gia tri chi xuat hien 1 trong 2 mang la:%d",s);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}