
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmang(float a[MAX],int &n)
{
	do{
	printf("Nhap vao so phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	printf("So ban nhap vao khong hop le!Xin ban vui long nhap lai!\n");
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
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
float AmMax(float a[MAX], int n) 
{ 
   float max;  
   int dem=0,i,vitri=0; 
   for (i=0; i<n; i++) 
   { 
      if(a[i]<0) 
      { 
         dem++; 
         break; 
      } 
   } 
   if (dem==0) 
   { 
      return 0; 
   } 
   else 
   { 
      max=a[i];
      for (i=i+1; i<n; i++) 
      { 
          if((a[i]<0)&&(max<a[i])) 
          { 
              max = a[i];
          } 
	  }
      return max;
   }
} 
void main()
{
	float a[MAX];
	int n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	float s=AmMax(a,n);
	printf("\nSo am lon nhat co trong mang la:%f",s);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}