
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MAX 100
// Hàm Nhập Mảng .
void NhapMang(int a[],int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:n=");
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
// Hàm Xuất Mảng .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm Hoán Vị .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm Sắp Xếp Mảng Tăng Dần Bằng Thuật Toán Interchange Sort .
void SapXepMangTangDan(int a[],int n)
{
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
// Hàm xử lý dữ liệu bài toán .
void XuLyDuLieu(int a[],int b[],int n)
{
	int dem=1,j=1,f;
	int tong=0;
	printf("\nCac Gia Tri Phan Biet Trong Mang La:");
	printf("%4d",a[0]); // In ra trước phần tử gốc a[0] .
	for(int i=1;i<n;i++)
	{
		b[0]=a[0]; // Gán phần tử đầu tiên của mảng b là phần tử gốc giá trị phân biệt đầu tiên .
		if(a[i]!=a[i-1])
		{
			printf("%4d",a[i]); // In ra các giá trị phân biệt trong mảng a .
			dem++; // Đếm số lượng các giá trị phân biệt .
			b[j++]=a[i]; // Đưa các giá trị phân biệt trong mảng a vào mảng b .
		}
	}
	printf("\n");
	printf("\n");
	printf("\nCac phan tu la so nguyen to va co so lan xuat hien it nhat la 2 lan la:");
	for(j=0;j<dem;j++)
	{
		int dem1=0; // Khởi tạo biến dem1=0 .
		for(int i=0;i<n;i++)
		{
			if(b[j]==a[i])
			{
				dem1++; 
			}
		}
		// Liệt kê ra những phần tử phân biệt trong mảng và có số lần xuất hiện >=2 lần .
		if(dem1>=2)
		{
			// Kiểm tra số nguyên tố .
			f=1; // Khởi tạo giá trị biến đầu tiên là 1 tượng trưng cho giá trị đúng (toán rời rạc ^^) .
			if(b[j]<2)
			{
				f=0; // Những số nguyên tố là những số >=2 => những số <2 ko phải là nguyên tố cho nên ở đây ta khởi tạo điều kiện là 0 tức ngầm hiểu là sai .
			}
			for(int k=2;k<=b[j]/2;k++)
			{
				if(b[j]%k==0)
				{
					f=0; // Nếu chia hết => không phải là số nguyên tố => khởi tạo điều kiện là 0 .
				}
			}
			if(f==1) // gọi lại điều kiện đúng . Lúc này các số trong mảng là các số nguyên tố có số lần xuất hiện >=2 lần . => thực hiện công việc tính toán mà đề bài ra .
			{
				printf("%4d",b[j]); // Liệt kê ra các phần tử thỏa điều kiện .
				tong+=b[j]; // Tính tổng các phần tử đó .
			}
		}
	}
	printf("\n");
	printf("\nTong cac phan tu thoa la:%d",tong);
}
// Hàm Chính .
void main()
{
	int a[MAX],b[MAX],n,tieptuc;
	quaylai:NhapMang(a,n);
	printf("\n>>>>>>>>>>>>Mang Vua Nhap La:<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapXepMangTangDan(a,n);
	XuLyDuLieu(a,b,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); 
		goto quaylai;
	}
}
