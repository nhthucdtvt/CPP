
#include<stdio.h>
#include<conio.h>
#define bool
#define MAX 100
void nhapmatran(int a[MAX][MAX],int &n,int &m)
{
	do{
		printf("Nhap vao so dong cua ma tran:m=");
		scanf("%d",&m);
		if(m<1||m>MAX)
			printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(m<1||m>MAX);
	do{
		printf("Nhap vao so cot cua ma tran:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("So cot ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1||n>MAX);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Nhap vao a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatmatran(int a[MAX][MAX],int n,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}
void xulydulieu(int a[MAX][MAX],int n,int m)
{
	int Co,Co1,i,j;
	bool Co=false;
	bool Co1=false;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]>=0)
			{
				Co=true;
				break;	// buộc phải có lệnh break ở đây để khi gặp đúng giá trị dương đầu tiên nó sẽ thoát ra khỏi vòng lặp gần nó nhất.
			}
		}
		if(Co==true) // sau khi thoát ra khỏi vòng lặp gần nhất ta gọi lại biến bool đó bằng 1 biến bool khác với mục đích đưa nó thoát ra nốt vòng lặp còn lại .
		{
			Co1=true; // đặt 1 biến bool mới.
			break;	// buộc phải có lệnh break ở đây để đưa giá trị dương đầu tiên thoát ra khỏi vòng lặp cuối cùng,lúc đó mới in ra được.
		}
	}
	if(Co1==true)	// ở đây ta gọi lại 1 trong 2 biến bool thì cái nào cũng đều đúng,tuy nhiên ta quyết định sẽ dùng theo biến bool gần nhất. 
		printf("\nGia tri duong dau tien trong ma tran la:%d",a[i][j]);
	else
		printf("\nTrong ma tran khong ton tai gia tri duong");
}
void main()
{
	int a[MAX][MAX],n,m,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	xulydulieu(a,n,m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}
