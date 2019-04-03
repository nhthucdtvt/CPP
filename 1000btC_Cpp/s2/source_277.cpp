
#include<stdio.h>
#include<conio.h>
#include<limits.h>
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
void biendoi(int a[MAX],int n)
{
	int min=INT_MAX,max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
	for(int i=0; i<n; i++)
	{
		if (a[i]==max)
		{
			a[i]=min;
		}
		else if (a[i]==min) // Cần phân biệt else if nó khác hoàn toàn với if.if là một trường hợp hoàn toàn khác,còn else if là một trường hợp khác nhưng vẫn bổ trợ với trường hợp trước đó,cùng kết hợp cho ra 1 kết quả chung của 2 cái.ví dụ nếu ở đây ta để riêng ra 2 cái if thì kết quả sẽ sai hoàn toàn.
		{
			a[i]=max;
		}
	}
} 
void main()
{
	int a[MAX],n,tieptuc,max,min;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	biendoi(a,n);
	printf("\n>>>>>>>>>>>>>MANG SAU KHI BIEN DOI LA:<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
