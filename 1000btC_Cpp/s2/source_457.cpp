
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
// Hàm nhập mảng các số nguyên .
void NhapMang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nNhap vao Phan Tu[%d]=",i);
		scanf("%d",&a[i]);
	}
}
// Hàm xuất mảng các số nguyên .
void XuatMang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm xử lý dữ liệu .
void XuLyDuLieu(int *a,int *b,int *c,int n,int m)
{
	int k=0;
	// Trường hợp 1 : 2 mảng a & b có độ dài bằng nhau .
	// Ý tưởng thuật toán : Thiết lập vòng lặp cho chạy từ 0 -> <n hay <m tùy ý (do lúc này n = m) rồi ta tiến hành cộng từng phần tử của 2 mảng và lưu chúng vào trong mảng c .
	if(n==m)
	{
		for(int i=0;i<n;i++) // Có thể để điều kiện i<m cũng được vì lúc này do n = m .
		{
			c[k++]=a[i]+b[i];
		}
	}
	// Trường hợp 2 : mảng a có chiều dài lớn hơn mảng b .
	// Ý tưởng thuật toán : Cần 2 vòng lặp . Vòng lặp đầu tiên ta cho chạy từ 0 -> <m (do mảng b có chiều dài bé hơn mảng a) rồi tiến hành cộng từng phần tử của 2 mảng và lưu chúng vào trong mảng c . Tiếp theo vòng lặp thứ 2 ta cho chạy từ m -> <n (lúc này các phần tử dư ra chỉ là của mảng a),ta đem các phần tử đó ghép vào mảng c . 
	else if(n>m)
	{
		for(int i=0;i<m;i++)
		{
			c[k++]=a[i]+b[i];
		}
		for(int i=m;i<n;i++)
		{
			c[k++]=a[i];
		}
	}
	// Trường hợp 3 : mảng b có chiều dài lớn hơn mảng a .
	// Ý tưởng thuật toán : Cần 2 vòng lặp . Vòng lặp đầu tiên ta cho chạy từ 0 -> <n (do mảng a có chiều dài bé hơn mảng b) rồi tiến hành cộng từng phần tử của 2 mảng và lưu chúng vào trong mảng c . Tiếp theo vòng lặp thứ 2 ta cho chạy từ n -> <m (lúc này các phần tử dư ra chỉ là của mảng b),ta đem các phần tử đó ghép vào mảng c . 
	else if(n<m)
	{
		for(int i=0;i<n;i++)
		{
			c[k++]=a[i]+b[i];
		}
		for(int i=n;i<m;i++)
		{
			c[k++]=b[i];
		}
	}
}
// Hàm chính .
void main()
{
	int *a,*b,*c,n,m,d,tieptuc;
	quaylai:printf("\nNhap vao so luong phan tu cua mang A:");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nSo luong phan tu cua mang A khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ - chức năng nhảy đến nhãn "quaylai" để nhập lại số lượng phần tử của mảng A .
	}
	quaylai1:printf("\nNhap vao so luong phan tu cua mang B:");
	scanf("%d",&m);
	if(m<1)
	{
		printf("\nSo luong phan tu cua mang B khong hop le!Xin vui long nhap lai!");
		goto quaylai1; // Dùng hợp ngữ - chức năng nhảy đến nhãn "quaylai1" để nhập lại số lượng phần tử của mảng B .
	}
	d=n>m?n:m; // Gán d = giá trị lớn nhất giữa n & m . Mục đích d chính là số lượng phần tử của mảng c .
	a=(int *)malloc(n*sizeof(int)); // Cấp phát động bộ nhớ cho mảng a . 
	b=(int *)malloc(m*sizeof(int)); // Cấp phát động bộ nhớ cho mảng b . 
	c=(int *)malloc(d*sizeof(int)); // Cấp phát động bộ nhớ cho mảng c . 
	printf("\n>>>>>>>>>>>> Nhap Mang A <<<<<<<<<<<<<<<<<\n");
	NhapMang(a,n);
	printf("\n>>>>>>>>>>>> Nhap Mang B <<<<<<<<<<<<<<<<<\n");
	NhapMang(b,m);
	printf("\n>>>>>>>>>>>> Xuat Mang A <<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	printf("\n>>>>>>>>>>>> Xuat Mang B <<<<<<<<<<<<<<<<<\n");
	XuatMang(b,m);
	printf("\n");
	XuLyDuLieu(a,b,c,n,m);
	printf("\n>>>>>>>>>>>> Xuat Mang C <<<<<<<<<<<<<<<<<\n");
	XuatMang(c,d);
	free(a); // Giải phóng bộ nhớ cho mảng a .
	free(b); // Giải phóng bộ nhớ cho mảng b .
	free(c); // Giải phóng bộ nhớ cho mảng c .
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C') // Đặt điều kiện nếu người dùng nhấn vào phím C thì yêu cầu sẽ được thực hiện .
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng xóa đi mọi dữ liệu đã thực thi trước đó để bắt đầu cho lần thực thi mới .
		goto quaylai; // Dùng hợp ngữ - Chức năng nhảy đến nhãn "quaylai" và bắt đầu chạy lại chương trình .
	}
}