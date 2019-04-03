
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
#include<math.h>
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
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%8d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
	int s=0,s1=0,s2=0,s3=0,s4,Co;
	bool Co=false;
	int dem,demb=0,demd=0,demf=0,demh=0;
	printf("Cac gia tri co chu so hang chuc la 5:");
	for(int i=0;i<n;i++)
	{	
		if(a[i]>=-99&&a[i]<=-10||a[i]>=10&&a[i]<=99)
		{
			int b=a[i]/10; // những số âm mà có 2 chữ số thì chắc chắn chữ số hàng chục không bao giờ là chữ số 5 (bởi vì 5>0).
			if(b==5)
			{
				printf("%8d",a[i]);
				demb++;
				s+=a[i];
				Co=true;
			}
		}
		if(a[i]>=-999&&a[i]<=-100||a[i]>=100&&a[i]<=999)
		{
			 int c=abs(a[i])/10; // Ta phải dùng thuật toán trị tuyệt đối ở đây nếu không thì các số âm nhưng có hàng chục là chữ số 5 máy sẽ không liệt kê ra.
			 int d=c%10;
			if(d==5)
			{
				printf("%8d",a[i]);
				demd++;
				s1+=a[i];
				Co=true;
			}
		}
		if(a[i]>=-9999&&a[i]<=-1000||a[i]>=1000&&a[i]<=9999)
		{
			 int e=abs(a[i])/10; // Ta phải dùng thuật toán trị tuyệt đối ở đây nếu không thì các số âm nhưng có hàng chục là chữ số 5 máy sẽ không liệt kê ra.
			 int f=e%10;
			if(f==5)
			{
				printf("%8d",a[i]);
				demf++;
				s2+=a[i];
				Co=true;
			}
		}
		if(a[i]>=-99999&&a[i]<=-10000||a[i]>=10000&&a[i]<=99999)
		{
			 int g=abs(a[i])%100; // Ta phải dùng thuật toán trị tuyệt đối ở đây nếu không thì các số âm nhưng có hàng chục là chữ số 5 máy sẽ không liệt kê ra.
			 int h=g/10;
			if(h==5)
			{
				printf("%8d",a[i]);
				demh++;
				s3+=a[i];
				Co=true;
			}
		}
	}
	dem=demb+demd+demf+demh;
	s4=s+s1+s2+s3;
	if(Co==true)
	{
		printf("\nTrong mang co %d gia tri co chu so hang chuc la 5",dem);
		printf("\nTong tat ca cac gia tri co chu so hang chuc la 5 co trong mang la:%d",s4);
	}
	else
	printf("\nKhong co gia tri nao trong mang co chu so hang chuc la 5");	
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}