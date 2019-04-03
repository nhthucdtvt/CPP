
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập mảng các số nguyên .
void NhapMang(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp . Chức năng tương tự như vòng lặp .
	}
	for(int i=0;i<n;i++)
	{
		quaylai1:printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
		if(a[i]==0)
		{
			printf("\nGia tri khong hop le!Xin nhap lai!");
			goto quaylai1;
		}
	}
}
// Hàm xuất mảng các số nguyên .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm hoán vị .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int a[],int b[],int c[],int d[],int n)
{
	int j=0,l,k;
	int t=0;
	for(int i=0;i<n;i++)
	{
		while(a[i]!=0)
		{
			b[j]=a[i]%10;
			a[i]=a[i]/10;
			j++;
		}
	}
	// Lúc này các chữ số của các phần tử trong mảng a đã được đưa vào mảng b.
	// Đi tìm ra các chữ số phân biệt trong mảng b .
	// Bước 1: Sắp mảng b tăng dần .
	for(l=0;l<j;l++)
	{
		for(k=l+1;k<j;k++)
		{
			if(b[l]>b[k])
			{
				HoanVi(b[l],b[k]);
			}
		}
	}
	// Bước 2: Liệt kê ra các chữ số phân biệt bằng cách đưa các chữ số có trong mảng b vào 1 mảng mới là mảng c và xử lý trên mảng c .
	int dem=1,m=1;
	c[0]=b[0]; // Gán phần tử đầu tiên của mảng c chính là phần tử đầu tiên của mảng b .
	for(l=1;l<j;l++) // Bắt đầu duyệt từ phần tử thứ 2 của mảng b .
	{
		if(b[l]!=b[l-1])
		{
			dem++;
			c[m++]=b[l];
		}
	}
	// Từ lúc này mảng c đã chứa các chữ số phân biệt .
	for(int m=0;m<dem;m++)
	{
		int dem1=0;
		for(int l=0;l<j;l++)
		{
			if(c[m]==b[l])
			{
				dem1++; // Mỗi lần bằng nhau thì tăng biến đếm lên .
			}
		}
		d[t++]=dem1; // Lưu giá trị biến đếm vào mảng d .
	}
	int min=d[0]; // Khởi tạo min là giá trị đầu tiên của mảng d .
	for(int t=0;t<dem;t++) // Số lượng phần tử của mảng d chính là số lượng các phần tử phân biệt của mảng b hay nói cách khác bằng đúng số lượng phần tử của mảng c nên ta đặt điều kiện t<dem .
	{
		if(d[t]<min)
		{
			min=d[t]; // Tìm ra tần suất xuất hiện ít nhất .
		}
	}
	// Khởi tạo lại vòng lặp cho phần tử của mảng c so sánh lại với mảng b với tần suất xuất hiện ít nhất đã được tìm ra ở trên .
	for(int m=0;m<dem;m++)
	{
		int dem1=0;
		for(int l=0;l<j;l++)
		{
			if(c[m]==b[l])
			{
				dem1++; // Mỗi lần bằng nhau thì tăng biến đếm lên .
			}
		}
		if(dem1==min) // Nếu biến đếm bằng đúng min (tần suất xuất hiện ít nhất mà ta đã tìm ra ở trên ) thì sẽ in ra tất cả các chữ số có tần suất xuất hiện đó .
		{
			printf("%4d",c[m]); // in ra các chữ số có số lần xuất hiện ít nhất trong mảng .
		}
	}
}
// Hàm chính .
void main()
{
	int a[MAX],b[MAX],c[MAX],d[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>>>Mang Ban Dau La:<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	XuatMang(a,n);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>Chu So Xuat Hien It Nhat Trong Mang La:<<<<<<<<<<<<\n");
	XuLyDuLieu(a,b,c,d,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); 
		goto quaylai; 
	}
}