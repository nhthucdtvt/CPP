
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
void LietKe(float a[MAX],float b[MAX], int n,int m) 
{  
	  printf("\nCac phan tu cung nam trong ca 2 mang A va mang B la:\n");
      for (int i=0; i<n; i++) 
      { 
        for (int j=0; j<m; j++) 
        { 
           if (a[i]==b[j]) 
           { 						  
              printf("%16f",a[i]); 
           }   
        } 
      } 
} 
void main()
{
	float a[MAX],b[MAX];
	int n,m,tieptuc;
	quaylai:nhap2mang(a,b,n,m);
	xuat2mang(a,b,n,m);
	LietKe(a,b,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}