
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define bool
void lietke(int &n)
{
	int s=0,s1=1,dem=0,s2=1,s3=0,dem1=0,s4=0;
	int max=INT_MIN,Co;
	bool Co=false;
	do{
	printf("Nhap vao n(n>0):n=");
	scanf("%d",&n);
	if(n<=0)
	printf("So ban nhap khong hop le!Xin vui long nhap lai!\n");
	else
	break;
	}while(n<=0);
	printf("Cac uoc so cua %d la:",n);
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			printf("%4d",i);
			s+=i;
			s1*=i;
			dem++;
		}
	}
	printf("\nTong tat ca cac uoc so cua %d la:%d",n,s);
	printf("\nTich tat ca cac uoc so cua %d la:%d",n,s1);
	printf("\nSo luong tat ca cac uoc so cua %d la:%d",n,dem);
	printf("\nCac uoc so le cua %d la:",n);
	for(int i=1;i<=n;i++)
	{
		if(n%i==0&&i%2!=0)
		{
			printf("%4d",i);
			s2*=i;
		}			
	}
	printf("\nTich tat ca cac uoc so le cua %d la:%d",n,s2);
	printf("\nCac uoc so chan cua %d la:",n);
	for(int i=1;i<=n;i++)
	{
		if(n%i==0&&i%2==0)
		{
			printf("%4d",i);
			s3+=i;
			dem1++;
		}			
	}
	printf("\nTong tat ca cac uoc so chan cua %d la:%d",n,s3);
	printf("\nSo luong tat ca cac uoc so chan cua %d la:%d",n,dem1);
	printf("\nCac uoc so cua %d ma nho hon chinh no la:",n);
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			printf("%4d",i);
			s4+=i;
		}
	}
	printf("\nTong cac uoc so cua %d ma nho hon chinh no la:%d",n,s4);
	for(int i=1;i<=n;i++)
	{
		if(n%i==0&&i%2!=0)
		{
			if(i>max)
			{
				max=i;
				Co=true;
			}
		}
	}
	if(Co==true)
		printf("\nUoc so le lon nhat cua %d la:%d",n,max);
}
void main()
{
	int n,tieptuc;
	quaylai:lietke(n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}