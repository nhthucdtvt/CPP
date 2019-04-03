
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
#define bool
// Hàm nhập mảng .
void NhapMang(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
// Hàm xuất mảng .
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
// Hàm Copy ra mảng mới và sắp mảng tăng dần bằng thuật toán Interchange Sort .
void CopyVaSapMangTangDan(int a[],int d[],int n)
{
	// Copy mảng a ra thành mảng d để lúc cuối cùng đem đi so sánh với mảng gốc ban đầu là mảng d với dữ liệu các phần tử vẫn như vậy chứ không có sự thay đổi nào cả .
	int t=0;
	for(int i=0;i<n;i++)
	{
		d[t++]=a[i];
	}
	// Sắp xếp mảng a tăng dần .
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				HoanVi(a[i],a[j]);
			}
		}
	}
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int a[],int b[],int c[],int d[],int n)
{
	int dem=1,j=1;
	int l=0,Co,t,vitri=0;
	bool Co=false;
	b[0]=a[0]; // Khởi tạo phần tử đầu tiên của mảng b bằng phần tử đầu tiên của mảng a .
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			dem++;
			b[j++]=a[i]; // Đưa các giá trị phân biệt của mảng a vào trong mảng b .
		}
	}
	for(int j=0;j<dem;j++)
	{
		int dem1=0;
		for(int i=0;i<n;i++)
		{
			if(b[j]==a[i]) // So sánh các phần tử của mảng b với mảng a ban đầu .
			{
				dem1++; // Mỗi lần các phần tử trong mảng b bằng với mảng a thì tăng biến đếm lên . Mục đích liệt kê ra tần suất xuất hiện của các phần tử có trong mảng,mỗi phần tử liệt kê 1 lần .
			}
		}
		c[l++]=dem1; // Lưu các tần suất xuất hiện của các phần tử phân biệt vào trong một mảng c .
	}
	int max=c[0]; // Khởi tạo max = phần tử đầu tiên của mảng c .
	for(int l=1;l<dem;l++) // Số lượng phần tử của mảng c chính là số lượng các phần tử phân biệt của mảng a và cũng chính là số lượng phần của mảng b nên ta cho điều kiện l < dem .
	{
		if(c[l]>max)
		{
			max=c[l]; // Tìm ra tần suất xuất hiện lớn nhất .
		}
	}
	// Khởi tạo lại vòng lặp cho phần tử của mảng b so sánh lại với mảng a với dữ liệu tần suất xuất hiện nhiều nhất đã được xác định ở trên .
	for(int j=0;j<dem;j++)
	{
		int dem1=0;
		for(int i=0;i<n;i++)
		{
			if(b[j]==a[i])
			{
				dem1++; // Mỗi lần bằng nhau thì tăng biến đếm lên .
			}
		}
		if(dem1==max) // Nếu biến đếm bằng đúng max (tần suất xuất hiện nhiều nhất mà ta đã tìm ra ở trên ) thì sẽ đi in ra tất cả các phần tử thỏa điều kiện đó .
		{
			for(int t=0;t<n;t++)
			{
				if(d[t]==b[j]) // So sánh mảng chứa tất cả các phần tử có số lần xuất hiện nhiều nhất đó với mảng copy ra ban đầu để tìm ra phần tử đầu tiên trong mảng ban đầu có số lần xuất hiện nhiều nhất . Từ đó ta đi in ra vị trí của nó . 
				{
					Co=true;
					vitri=t;
					break; // Tìm được vị trí đầu tiên thì thoát ra khỏi vòng lặp thứ nhất .
				}
			}
		}
		if(Co==true)
		{
			break; // Thoát ra tiếp khỏi vòng lặp thứ hai .
		}
	}
	if(Co==true)
	{
		printf("\nGia Tri Dau Tien Trong Mang Co So Lan Xuat Hien Nhieu Nhat La:%d",d[vitri]);
		printf("\n");
		printf("\nTai Vi Tri La:%d",vitri);
		printf("\n");
		printf("\nSo Lan Xuat Hien La:%d",max);
	}
}
// Hàm chính .
void main()
{
	int a[MAX],b[MAX],c[MAX],d[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	CopyVaSapMangTangDan(a,d,n);
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
