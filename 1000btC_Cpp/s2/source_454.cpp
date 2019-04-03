
// Khai báo các thư viện sử dụng trong chương trình .
#include<stdio.h>				
#include<conio.h>
#include<time.h>
#include<Windows.h>
#define MAX 100
// Hàm nhập số lượng phần tử của mảng .
void NhapN(int &n)
{
	quaylai:printf("\nNhap vao so luong phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp chức năng nếu người dùng nhập vào số không thỏa thì chương trình cho phép nhập lại đến khi nào nhập đúng thì thôi .
	}
}
// Hàm ghi File INPUT.TXT
void GhiFile(int a[],int n)
{
	FILE*pFile;
	pFile=fopen("C:\\INPUT.TXT","wt"); // File được tạo nằm trong ổ C .
	fprintf(pFile,"So Luong Cac Phan Tu:%d\n",n); // Ghi giá trị số lượng phần tử vào file .
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%101; // tạo ngẫu nhiên trong đoạn [0,100] .
		fprintf(pFile,"%4d",a[i]); // Ghi giá trị các phần tử trong mảng vào file .
	}
	fclose(pFile); // Đóng file .
}
// Hàm đọc file INPUT.TXT vào chương trình
void DocFile(int a[],int n)
{
	FILE*pFile;
	pFile=fopen("C:\\INPUT.TXT","r+t"); // Mở file ra .
	if(pFile==NULL)
	{
		printf("\nKhong doc duoc File INPUT.TXT");
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			fscanf(pFile,"%d\t",&a[i]); // Đọc các giá trị phần tử trong file vào chương trình .
			printf("a[%d]=%d\n",i,a[i]); // Xuất các giá trị ra màn hình .
		}
	}
	fclose(pFile); // Đóng file .
}
// Hàm tìm giá trị lớn nhất trong mảng và ghi vào file .
void TimMax(int a[],int n)
{
	int max=a[0]; // khởi tạo max = phần tử đầu tiên trong mảng .
	FILE*pFile;
	pFile=fopen("C:\\OUTPUT.TXT","wt"); // Mở file ra .
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	fprintf(pFile,"Cau a:%d\n",max); // Ghi giá trị max tìm được vào file .
	fclose(pFile); // Đóng file .
}
// Hàm đếm số lượng các phần tử chẵn,phần tử lẻ trong mảng và ghi vào file .
void DemChanLe(int a[],int n)
{
	int dem=0,dem1=0;
	FILE*pFile;
	pFile=fopen("C:\\OUTPUT.TXT","at"); // Mở file ra . Ở đây ta phải để định dạng file là "at" hay là để "a" cũng được . Chức năng là mở tập tin và ghi tiếp dữ liệu cần nạp vào cuối tập tin . Ta không thể xài lại định dạng "wt" vì khi dữ liệu mới vào thì tất cả dữ liệu cũ sẽ bị xóa đi hết .
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			dem++; // Đếm số lượng các giá trị chẵn trong mảng .
		}
		else
		{
			dem1++; // Đếm số lượng các giá trị lẻ trong mảng .
		}
	}
	fprintf(pFile,"Cau b:%d\t%d\n",dem,dem1); // Ghi dữ liệu vào file .
	fclose(pFile); // Đóng file .
}
// Hàm hoán vị 2 số nguyên .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm sắp xếp mảng tăng dần bằng thuật toán Interchange Sort .
void SapTangDan(int a[],int n)
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
// Hàm xuất mảng sau khi đã được sắp tăng dần và ghi vào file .
void XuatMang(int a[],int n)
{
	FILE*pFile;
	pFile=fopen("C:\\OUTPUT.TXT","at"); // Mở file ra . Ở đây ta phải để định dạng file là "at" hay là để "a" cũng được . Chức năng là mở tập tin và ghi tiếp dữ liệu cần nạp vào cuối tập tin . Ta không thể xài lại định dạng "wt" vì khi dữ liệu mới vào thì tất cả dữ liệu cũ sẽ bị xóa đi hết .
	fprintf(pFile,"Cau c:\n"); // Ghi vào file .
	for(int i=0;i<n;i++)
	{
		fprintf(pFile,"%4d",a[i]); // Ghi vào file .
	}
	fclose(pFile); // Đóng file .
}
// Hàm MeNu gom hết mọi dữ liệu làm ở trên vào .
void MeNu()
{
	int a[MAX],n,tieptuc;
	quaylai:NhapN(n);
	GhiFile(a,n);
	DocFile(a,n);
	TimMax(a,n);
	DemChanLe(a,n);
	SapTangDan(a,n);
	XuatMang(a,n);
	// Thông báo .
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch(); // Lấy key từ bàn phím .
	if(tieptuc=='c'||tieptuc=='C') // Xác nhận khi người dùng nhấn phím C thì sẽ quay lại chương trình .
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng để xóa hết mọi dữ liệu cũ cho phép người dùng nhập vào dữ liệu mới .
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp . Chức năng để bắt đầu lại chương trình mới . 
	}
}
// Hàm chính .
void main()
{
	MeNu(); // Gọi lại hàm MeNu.
}