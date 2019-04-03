
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#define MAX 10
// Hàm phát Sinh ngẫu nhiên các số nguyên với giới hạn MAX là số tùy ý điều chỉnh Ở Mục define .
void PhatSinhNgauNhien(int a[])
{
	srand(time(0));
	for(int i=0;i<MAX;i++)
	{
		a[i]=(rand()%61)-30; // Ở đây các giá trị ngẫu nhiên sẽ nằm trong đoạn [-30,30] .
	}
}
// Hàm xuất mảng các số nguyên ngẫu nhiên .
void XuatMang(int a[])
{
	for(int i=0;i<MAX;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm hoán vị 2 số nguyên.
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm sắp xếp mảng các số nguyên giảm dần bằng thuật toán Interchange Sort .
void SapXepGiamDanBangThuatToanInterchangeSort(int a[])
{
	for(int i=0;i<MAX-1;i++)
	{
		for(int j=i+1;j<MAX;j++)
		{
			if(a[i]<a[j])
			{
				HoanVi(a[i],a[j]);
			}
		}
	}
}
// Hàm sắp xếp mảng các số nguyên giảm dần bằng thuật toán Quick Sort .
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
		while(a[i]>x) // ở đây là sắp giảm dần
		{
			i++;
		}
		while(a[j]<x) // ở đây là sắp giảm dần
		{
			j--;
		}
		if(i<=j)
		{
			HoanVi(a[i],a[j]);
			i++;
			j--;
		}
	}
	SapXepGiamDanBangThuatToanQuickSort(a,left,j);
	SapXepGiamDanBangThuatToanQuickSort(a,i,right);
}
// Hàm sắp xếp mảng các số nguyên giảm dần bằng thuật toán Selection Sort .
void SapXepGiamDanBangThuatToanSelectionSort(int a[])
{
	int min;
	for(int i=0;i<MAX-1;i++)
	{
		min=i;
		for(int j=i+1;j<MAX;j++)
		{
			if(a[j]>a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			HoanVi(a[min],a[i]);
		}
	}
}
// Hàm sắp xếp mảng các số nguyên giảm dần bằng thuật toán Bubble Sort .
void SapXepGiamDanBangThuatToanBubbleSort(int a[])
{
	for(int i=0;i<MAX-1;i++)
	{
		for(int j=MAX-1;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				HoanVi(a[j],a[j-1]);
			}
		}
	}
}
// Hàm MeNu .
void MeNu()
{
	printf("\n>>>>>>>>>>>>>>>>Chuong Trinh Do Time Cua Cac Thuat Toan Sap Xep:<<<<<<<<<<<<<<\n");
	int a[MAX],b[MAX],c[MAX],d[MAX],w; // Khai báo 4 mảng a,b,c,d ứng với 4 thuật toán sắp xếp .
	do{
		printf("\n");
		printf("\n");
		printf("\n Moi ban lua chon cac yeu cau !");
		printf("\n");
		printf("\nNhap so ban chon roi nhan Enter de xac nhan!");
		printf("\n");
		printf("\n 1 - Tinh Thoi Gian Sap Xep Cua Thuat Toan Interchange Sort ");
		printf("\n");
		printf("\n 2 - Tinh Thoi Gian Sap Xep Cua Thuat Toan Quick Sort ");
		printf("\n");
		printf("\n 3 - Tinh Thoi Gian Sap Xep Cua Thuat Toan Selection Sort ");
		printf("\n");
		printf("\n 4 - Tinh Thoi Gian Sap Xep Cua Thuat Toan Bubble Sort ");
		printf("\n");
		printf("\n 0 - Thoat Chuong Trinh ");
		printf("\n");
		printf("\n Moi ban nhap vao lua chon cua ban o day:");
		scanf("%d",&w);
		switch(w)
		{
		case 1:
			{
				// Lần sắp xếp đầu tiên - Thuật Toán Interchange Sort .
				int i=1000; 
				clock_t start1 = clock(); 
				while( i--> 0 )
					PhatSinhNgauNhien(a);
				printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Cua Lan Thu 1 La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
				XuatMang(a);
				printf("\n");
				SapXepGiamDanBangThuatToanInterchangeSort(a);
				printf("\n>>>>>>>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Interchange Sort La:<<<<<<<\n");
				XuatMang(a);
				printf("\n");
				clock_t finish1 = clock(); 
				double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC; 
				printf("\n");
				printf("Thoi gian thuc thi cua thuat toan Interchange Sort la: %.2lf", duration1); // Trả về thời gian sắp xếp của Thuật Toán Interchange Sort.
				break;
			}
		case 2:
			{
				// Lần sắp xếp thứ hai - Thuật Toán Quick Sort .
				int j=1000; 
				clock_t start2 = clock(); 
				while( j--> 0 )
					PhatSinhNgauNhien(b);
				printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan Thu 2 La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
				XuatMang(b);
				printf("\n");
				SapXepGiamDanBangThuatToanQuickSort(b,0,MAX-1);
				printf("\n>>>>>>>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Quick Sort La:<<<<<<<\n");
				XuatMang(b);
				printf("\n");
				clock_t finish2 = clock(); 
				double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
				printf("\n");
				printf("Thoi gian thuc thi cua thuat toan Quick Sort la: %.2lf", duration2);// Trả về thời gian sắp xếp của Thuật Toán Quick Sort.
				break;
			}
		case 3:
			{
				// Lần sắp xếp thứ ba - Thuật Toán Selection Sort .
				int k=1000; 
				clock_t start3 = clock(); 
				while( k--> 0 )
					PhatSinhNgauNhien(c);
				printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan Thu 3 La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
				XuatMang(c);
				printf("\n");
				SapXepGiamDanBangThuatToanSelectionSort(c);
				printf("\n>>>>>>>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Selection Sort La:<<<<<<<\n");
				XuatMang(c);
				printf("\n");
				clock_t finish3 = clock(); 
				double duration3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;
				printf("\n");
				printf("Thoi gian thuc thi cua thuat toan Selection Sort la: %.2lf", duration3);// Trả về thời gian sắp xếp của Thuật Toán Selection Sort.
				break;
			}
		case 4:
			{
				// Lần sắp xếp thứ tư - Thuật Toán Bubble Sort .
				int l=1000; 
				clock_t start4 = clock(); 
				while( l--> 0 )
					PhatSinhNgauNhien(d);
				printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan Thu 4 La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
				XuatMang(d);
				printf("\n");
				SapXepGiamDanBangThuatToanBubbleSort(d);
				printf("\n>>>>>>>>>>>>>>>Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Bubble Sort La:<<<<<<<\n");
				XuatMang(d);
				printf("\n");
				clock_t finish4 = clock(); 
				double duration4 = (double)(finish4 - start4) / CLOCKS_PER_SEC;
				printf("\n");
				printf("Thoi gian thuc thi cua thuat toan Bubble Sort la: %.2lf", duration4);// Trả về thời gian sắp xếp của Thuật Toán Bubble Sort.
				break;
			}
		}
	}while(w!=0);
}
// Hàm Chính .
void main()
{
	MeNu();
}