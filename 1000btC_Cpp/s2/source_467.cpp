
// Khai báo các thư viện cần sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#define MAX 10000
// Hàm nhập số lượng phần tử của mảng .
void NhapVaoSoLuongPhanTuCuaMang(int &n)
{
	quaylai:printf ("\nNhap so luong phan tu cua mang:n= ");
	scanf ("%d", &n);
	if(n<1||n>MAX)
	{
		printf("\nSo phan tu ban nhap vao khong hop le!Xin vui long nhap lai!"); // Báo lỗi .
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp,tác dụng quay lại nếu nhập vào số không thỏa .
	}
}
// Hàm tạo ra file.txt có tên NamSon.txt để truyền dữ liệu số phần tử ngẫu nhiên vào,khỏi mất công tạo ra file rồi nhập tay vào .
void GhiFileNamSon(int a[], int n)
{
	FILE * pFile;
	pFile = fopen ("C:\\NamSon.txt","wt"); // Tạo ra file có tên là NamSon.txt chứa dữ liệu là số lượng các phần tử cần tạo và giá trị ngẫu nhiên của các phần tử ở trong ổ C .
	fprintf(pFile,"So Luong Cac Phan Tu Trong Mang La:%d \n",n);
	for(int i=0;i<n;i++)
	{
		a[i]=(rand()%41)-20;// Tạo ngẫu nhiên các số nằm trong đoạn [-20,20] .
		fprintf (pFile, "a[%d]=%d\n",i,a[i]); // Ghi các giá trị ngẫu nhiên do chương trình tạo ra vào file NamSon.txt  .
	}
	fclose (pFile); // Đóng file lại .
}
// Theo đúng yêu cầu đề bài sau khi đã ghi dữ liệu lên file NamSon.txt thì sẽ đọc dữ liệu từ file đó vào chương trình bao gồm số lượng phần tử trong mảng các số nguyên và giá trị của các phần tử trong mảng .
void DocFileNamSon(int a[], int n)
{
	FILE * pFile;
	pFile = fopen("C:\\NamSon.txt", "r+t"); // Tìm kiếm và mở file NamSon.txt ở trong ổ C để đọc dữ liệu trong file vào lại chương trình .
	if(pFile==NULL)
	{
		printf("\nKhong Doc Duoc File NamSon.txt"); // Báo lỗi không đọc được file NamSon.txt
	}
	else
	{
		printf("\n>>>>>>>>>>>Du Lieu Doc Tu File NamSon.txt :<<<<<<<<<<<<<<<<<<<\n");
		for(int i=0; i<n; i++)
		{
			fscanf(pFile, "%d\t", &a[i]); // Đọc dữ liệu từ file vào chương trình .
			printf ("a[%d]=%d\n",i,a[i]); // Xuất ra màn hình .
		}
	}
	fclose(pFile); // Đóng file lại .
}
// Hàm xuất mảng các số nguyên .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm hoán vị 2 số nguyên .
void HoanVi(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
// Hàm sắp xếp mảng số nguyên giảm dần bằng thuật toán Interchange Sort .
void SapXepGiamDanBangThuatToanInterchangeSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				HoanVi(a[i],a[j]); // Gọi lại hàm hoán vị 2 số nguyên .
			}
		}
	}
}
// Hàm sắp xếp mảng số nguyên giảm dần bằng thuật toán Quick Sort .
void SapXepGiamDanBangThuatToanQuickSort(int a[],int left,int right)
{
	int i,j,x;
	if(left>=right)
	{
		return;
	}
	x=a[(left+right)/2]; // Chọn phần tử giữa làm giá trị mốc .
	i=left;
	j=right;
	while(i<j)
	{
		while(a[i]>x) 
		{
			i++;
		}
		while(a[j]<x)
		{
			j--;
		}
		if(i<=j)
		{
			HoanVi(a[i],a[j]); // Gọi lại hàm hoán vị 2 số nguyên .
			i++;
			j--;
		}
	}
	SapXepGiamDanBangThuatToanQuickSort(a,left,j);
	SapXepGiamDanBangThuatToanQuickSort(a,i,right);
}
// Hàm sắp xếp mảng số nguyên giảm dần bằng thuật toán Selection Sort .
void SapXepGiamDanBangThuatToanSelectionSort(int a[],int n)
{
	int max;
	for(int i=0;i<n-1;i++)
	{
		max=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>a[max])
			{
				max=j;
			}
		}
		if(max!=i)
		{
			HoanVi(a[max],a[i]); // Gọi lại hàm hoán vị 2 số nguyên .
		}
	}
}
// Hàm sắp xếp mảng số nguyên giảm dần bằng thuật toán Bubble Sort .
void SapXepGiamDanBangThuatToanBubbleSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				HoanVi(a[j],a[j-1]); // Gọi lại hàm hoán vị 2 số nguyên .
			}
		}
	}
}
// Hàm MeNu .
void MeNu()
{
	int a[MAX],b[MAX],c[MAX],d[MAX],w,n; // Khai báo 4 mảng a,b,c,d ứng với 4 thuật toán sắp xếp .
	do{
		// Bảng MeNu đưa ra các sự lựa chọn .
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");
		printf("\n Moi ban lua chon cac yeu cau !");
		printf("\n");
		printf("\nNhap so ban chon roi nhan Enter de xac nhan!");
		printf("\n");
		printf("\n 1 - Nhap Vao So Luong Phan Tu Can Sap Xep ");
		printf("\n");
		printf("\n 2 - Tinh Thoi Gian Sap Xep Cua Thuat Toan Interchange Sort ");
		printf("\n");
		printf("\n 3 - Tinh Thoi Gian Sap Xep Cua Thuat Toan Quick Sort ");
		printf("\n");
		printf("\n 4 - Tinh Thoi Gian Sap Xep Cua Thuat Toan Selection Sort ");
		printf("\n");
		printf("\n 5 - Tinh Thoi Gian Sap Xep Cua Thuat Toan Bubble Sort ");
		printf("\n");
		printf("\n 0 - Thoat Chuong Trinh ");
		printf("\n");
		printf("\n--------------------------------------------------------------------------------\n");
		printf("\n");
		printf("\n Moi ban nhap vao lua chon cua ban o day:");
		scanf("%d",&w);
		// Ở đây nếu ngay từ đầu người dùng không lựa chọn nhập vào số lượng phần tử cần sắp xếp thì các lựa chọn tính toán thời gian của các thuật toán sắp xếp 2-3-4-5 sẽ không thể thực thi,báo lỗi và thoát chương trình .
		// Cấu trúc switch-case .
		switch(w)
		{
		case 1: // Nhập vào số lượng phần tử cần tạo ra để thực thi sắp xếp bởi 4 thuật toán .
			{
				NhapVaoSoLuongPhanTuCuaMang(n);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 2: // Đo thời gian chạy của bước sắp giảm dần và bước xuất ra kết quả của Thuật Toán Interchange Sort .
			{
				GhiFileNamSon(a,n);
				DocFileNamSon(a,n);
				// Đoạn code đo thời gian chạy của đoạn lệnh  .
				int i=1000; 
				clock_t start1 = clock(); 
				while( i--> 0 )
				SapXepGiamDanBangThuatToanInterchangeSort(a,n);
				printf("\n>>>>>>Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Interchange Sort La:<<<<<<\n");
				XuatMang(a,n);
				printf("\n");
				clock_t finish1 = clock(); 
				double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC; 
				printf("\n");
				printf("Thoi gian thuc thi cua thuat toan Interchange Sort la: %.2lf giay", duration1); // Trả về thời gian sắp xếp của Thuật Toán Interchange Sort.
				printf("\n");
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 3: // Đo thời gian chạy của bước sắp giảm dần và bước xuất ra kết quả của Thuật Toán Quick Sort .
			{
				GhiFileNamSon(b,n);
				DocFileNamSon(b,n);
				// Đoạn code đo thời gian chạy của đoạn lệnh  .
				int j=1000; 
				clock_t start2 = clock(); 
				while( j--> 0 )
				SapXepGiamDanBangThuatToanQuickSort(b,0,n-1);
				printf("\n>>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Quick Sort La:<<<<<<<\n");
				XuatMang(b,n);
				printf("\n");
				clock_t finish2 = clock(); 
				double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
				printf("\n");
				printf("Thoi gian thuc thi cua thuat toan Quick Sort la: %.2lf giay", duration2);// Trả về thời gian sắp xếp của Thuật Toán Quick Sort.
				printf("\n");
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 4: // Đo thời gian chạy của bước sắp giảm dần và bước xuất ra kết quả của Thuật Toán Selection Sort .
			{
				GhiFileNamSon(c,n);
				DocFileNamSon(c,n);
				// Đoạn code đo thời gian chạy của đoạn lệnh  .
				int k=1000; 
				clock_t start3 = clock(); 
				while( k--> 0 )
				SapXepGiamDanBangThuatToanSelectionSort(c,n);
				printf("\n>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Selection Sort La:<<<<<<<\n");
				XuatMang(c,n);
				printf("\n");
				clock_t finish3 = clock(); 
				double duration3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;
				printf("\n");
				printf("Thoi gian thuc thi cua thuat toan Selection Sort la: %.2lf giay", duration3);// Trả về thời gian sắp xếp của Thuật Toán Selection Sort.
				printf("\n");
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 5: // Đo thời gian chạy của bước sắp giảm dần và bước xuất ra kết quả của Thuật Toán Bubble Sort .
			{
				GhiFileNamSon(d,n);
				DocFileNamSon(d,n);
				// Đoạn code đo thời gian chạy của đoạn lệnh  .
				int l=1000; 
				clock_t start4 = clock(); 
				while( l--> 0 )
				SapXepGiamDanBangThuatToanBubbleSort(d,n);
				printf("\n>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Bubble Sort La:<<<<<<<\n");
				XuatMang(d,n);
				printf("\n");
				clock_t finish4 = clock(); 
				double duration4 = (double)(finish4 - start4) / CLOCKS_PER_SEC;
				printf("\n");
				printf("Thoi gian thuc thi cua thuat toan Bubble Sort la: %.2lf giay", duration4);// Trả về thời gian sắp xếp của Thuật Toán Bubble Sort.
				printf("\n");
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 0: // Thoát khỏi chương trình .
			{
				printf("\nThanks You For Using The Program ! Goodbye And See You Later !\n"); // Khi người dùng thoát chương trình sẽ hiển thị lời chào !
				getch(); // Dừng màn hình lại .
			}
		}
	}while(w!=0); // vòng lặp sẽ tiếp tục thực hiện khi nhận lệnh của người dùng nhập vào giá trị khác 0 . Nếu nhập vào giá trị 0 thì chương trình sẽ kết thúc .
}
// Hàm chính
void main ()
{
	MeNu(); // Gọi lại hàm MeNu .
}