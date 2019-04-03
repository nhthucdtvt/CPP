
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập ma trận các số nguyên .
void NhapMaTran(int a[MAX][MAX],int &m,int &n)
{
	quaylai:printf("\nNhap vao so dong cua ma tran:");
	scanf("%d",&m);
	if(m<1||m>MAX)
	{
		printf("\nSo dong ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	quaylai1:printf("\nNhap vao so cot cua ma tran:");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo cot ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai1;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("\nNhap vao a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
// Hàm xuất ma trận các số nguyên .
void XuatMaTran(int a[MAX][MAX],int m,int n)
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
// Hàm hoán vị 2 số nguyên .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int a[MAX][MAX],int b[],int c[],int d[],int m,int n)
{
	int k=0,t,x=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			while(a[i][j]!=0)
			{
				b[k]=a[i][j]%10;
				a[i][j]=a[i][j]/10;
				k++;
			}
		}
	}
	// Đầu tiên là liệt kê ra các chữ số có trong ma trận và lưu vào mảng 1 chiều b .
	// Tiếp theo ta sẽ đi lọc ra các chữ số phân biệt có trong mảng b và lưu vào 1 mảng mới là mảng c .
	// Để làm được điều đó thì đầu tiên ta đi sắp xếp mảng b tăng dần
	for(int l=0;l<k;l++)
	{
		for(t=l+1;t<k;t++)
		{
			if(b[l]>b[t])
			{
				HoanVi(b[l],b[t]);
			}
		}
	}
	// Tiếp theo ta đưa các chữ số phân biệt vào trong mảng c .
	int dem=1,m=1;
	c[0]=b[0]; // Gán phần tử đầu tiên của mảng c bằng phần tử đầu tiên của mảng b .
	for(int l=1;l<k;l++)
	{
		if(b[l]!=b[l-1])
		{
			dem++;
			c[m++]=b[l];
		}
	}
	// Từ lúc này mảng c đã chứa các chữ số phân biệt của mảng b .
	// Bây giờ ta sẽ tiếp tục đem mảng c đã chứa các chữ số phân biệt đem so sánh với mảng b lúc đầu chứa tất cả các chữ số để ta tìm ra tần suất xuất hiện nhiều nhất .
	for(int m=0;m<dem;m++)
	{
		int dem1=0;
		for(int l=0;l<k;l++)
		{
			if(c[m]==b[l])
			{
				dem1++; // Mỗi lần bằng nhau thì tăng biến đếm lên .
			}
		}
		d[x++]=dem1; // Lưu các giá trị biến đếm vào trong 1 mảng d .
	}
	// Bây giờ ta sẽ đi xử lý trên mảng d để tìm ra số lần đếm xuất hiện nhiều nhất .
	int max=d[0]; // Khởi tạo max bằng phần tử đầu tiên của mảng d .
	for(int x=0;x<dem;x++)
	{
		if(d[x]>max)
		{
			max=d[x]; // Tìm ra tần suất xuất hiện lớn nhất .
		}
	}
	// Sau khi đã xác định được tần suất xuất hiện lớn nhất (max) thì ta chỉ cần đem tần suất xuất hiện lớn nhất vừa tìm được so sánh với các chữ số . Chữ số nào có tần suất như vậy thì in ra .
	// Khởi tạo lại vòng lặp cho các chữ số phân biệt của mảng c đi so sánh lại với các chữ số có trong mảng b 1 lần nữa với dữ liệu tần suất xuất hiện lớn nhất đã được tìm ra ở trên .
	for(int m=0;m<dem;m++)
	{
		int dem1=0;
		for(int l=0;l<k;l++)
		{
			if(c[m]==b[l])
			{
				dem1++; // Mỗi lần bằng nhau thì tăng biến đếm lên .
			}
		}
		if(dem1==max) // Nếu biến đếm bằng đúng max (tần suất xuất hiện nhiều nhất mà ta đã tìm ra ở trên ) thì sẽ in ra tất cả các chữ số có tần suất xuất hiện đó .
		{
			printf("%2d",c[m]);
		}
	}
}
// Hàm chính .
void main()
{
	int a[MAX][MAX],b[MAX],c[MAX],d[MAX],m,n,tieptuc;
	quaylai:NhapMaTran(a,m,n);
	printf("\n>>>>>>>>>>>>Ma Tran Vua Nhap La:<<<<<<<<<<<<<<<<\n");
	XuatMaTran(a,m,n);
	printf("\n");
	printf("\n>>>>>>>>>>>>Chu So Co Tan Suat Xuat Hien Lon Nhat Trong Ma Tran La:<<<<<<<<<<<<<\n");
	XuLyDuLieu(a,b,c,d,m,n);
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}