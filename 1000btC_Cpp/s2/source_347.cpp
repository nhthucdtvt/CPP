
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapmatran(float a[MAX][MAX],int &n,int &m)
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
			scanf("%f",&a[i][j]);
		}
	}
}
void xuatmatran(float a[MAX][MAX],int n,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%16f",a[i][j]);
		}
		printf("\n");
	}
}
void timlonnhattrendong(float a[MAX][MAX],int n,int m,int &x)
{
	float max;	// khai báo trước biến max.
	do{
		printf("\nNhap vao so dong can tim gia tri lon nhat:x=");
		scanf("%d",&x);
		if(x<0||x>m-1)
			printf("\nSo dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(x<0||x>m-1);
	for(int j=0;j<n;j++)
	{
		max=a[x][0];	// ở đây nếu ta mà khai báo theo kiểu max=FLT_MIN thì sẽ dẫn đến kết quả sai với kiểu số âm,ta phải để max=a[x][0] và bắt buộc phải để trong vòng lặp để mỗi lần tìm xong giá trị lớn nhất của 1 dòng nó lại trả về dòng mới,nếu không nó sẽ cứ lấy tiếp giá trị của dòng vừa tính ra.
		if(a[x][j]>max)
			max=a[x][j];
	}
	printf("\nGia tri lon nhat tren dong:%d la:%f",x,max);
}
void main()
{
	float a[MAX][MAX];
	int n,m,x,tieptuc;
	quaylai:nhapmatran(a,n,m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,n,m);
	timlonnhattrendong(a,n,m,x);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}