
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<math.h>
#define MAX 100
// Hàm hoán vị 2 số nguyên .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm sắp mảng tăng dần bằng thuật toán Selection Sort .
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
// Hàm xuất mảng .
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
// Hàm tìm số lớn thứ 3 .
void TimSoLonThuBa(int a[],int n)
{
	int vt1=0,vt2=0,max1,max2,max3,dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			dem++;
		}
	}
	if(dem>=3)
	{
		for(int i=0;i<n;i++)
		{
			max1=a[n-1];
			if(max1==a[i])
			{
				vt1=i;
				break;
			}
		}
		for(int i=0;i<vt1;i++)
		{
			max2=a[vt1-1];
			if(max2==a[i])
			{
				vt2=i;
				break;
			}
		}
		max3=a[vt2-1];
		printf("\nPhan tu lon thu 3 trong mang la:%d",max3);
	}
	else
		printf("\nMang nay khong ton tai it nhat 3 phan tu khac nhau nen khong the tinh duoc!");
}
// Hàm đếm số lượng phần tử lớn nhất có trong mảng .
void DemSoLuongPhanTuLonNhat(int a[],int n)
{
	int max=a[0],dem=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==max)
		{
			dem++;
		}
	}
	printf("\nSo luong phan tu lon nhat trong day la:%d",dem);
}
// Hàm Sắp mảng tăng dần theo trị tuyệt đối .
void SapTangDanTriTuyetDoi(int a[],int b[],int n)
{
	for(int i=0;i<n;i++)
	{
		b[i]=abs(a[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(b[i]>b[j])
			{
				HoanVi(b[i],b[j]);
			}
		}
	}
}
// Hàm tách ra phần tử dương lưu vào mảng C,phần tử âm lưu vào mảng D
void TachDuongVaAm(int a[],int c[],int d[],int n)
{
	int j=0,k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			c[j++]=a[i];
		}
		else
		{
			d[k++]=a[i];
		}
	}
}
// Hàm trả về số lượng các phần tử dương trong mảng C .
int SoLuongPhanTuMangC(int a[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			dem++;
		}
	}
	return dem;
}
// Hàm trả về số lượng các phần tử âm trong mảng D .
int SoLuongPhanTuMangD(int a[],int n)
{
	int dem1=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			dem1++;
		}
	}
	return dem1;
}
// Hàm sắp mảng C chứa các phần tử dương giảm dần .
void SapMangCGiamDan(int c[],int dem)
{
	for(int i=0;i<dem-1;i++)
	{
		for(int j=i+1;j<dem;j++)
		{
			if(c[i]<c[j])
			{
				HoanVi(c[i],c[j]);
			}
		}
	}
}
// Hàm sắp mảng D chứa các phần tử âm tăng dần .
void SapMangDTangDan(int d[],int dem1)
{
	for(int i=0;i<dem1-1;i++)
	{
		for(int j=i+1;j<dem1;j++)
		{
			if(d[i]>d[j])
			{
				HoanVi(d[i],d[j]);
			}
		}
	}
}
// Hàm ghép chung 2 mảng C & D vào chung 1 mảng F theo đúng trình tự thì ghép mảng C vào trước & mảng D vào sau .
void MangF(int f[],int c[],int d[],int dem,int dem1)
{
	int l=0;
	for(int j=0;j<dem;j++)
	{
		f[l++]=c[j];
	}
	for(int k=0;k<dem1;k++)
	{
		f[l++]=d[k];
	}
}
// Hàm tách ra phần tử chẵn lưu vào mảng G,phần tử lẻ lưu vào mảng H
void TachChanVaLe(int a[],int g[],int h[],int n)
{
	int j=0,k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			g[j++]=a[i];
		}
		else
		{
			h[k++]=a[i];
		}
	}
}
// Hàm trả về số lượng các phần tử chẵn trong mảng G .
int SoLuongPhanTuMangG(int a[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			dem++;
		}
	}
	return dem;
}
// Hàm trả về số lượng các phần tử lẻ trong mảng H .
int SoLuongPhanTuMangH(int a[],int n)
{
	int dem1=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			dem1++;
		}
	}
	return dem1;
}
// Hàm sắp mảng G chứa các phần tử chẵn tăng dần .
void SapMangGTangDan(int g[],int dem)
{
	for(int i=0;i<dem-1;i++)
	{
		for(int j=i+1;j<dem;j++)
		{
			if(g[i]>g[j])
			{
				HoanVi(g[i],g[j]);
			}
		}
	}
}
// Hàm sắp mảng H chứa các phần tử lẻ giảm dần .
void SapMangHGiamDan(int h[],int dem1)
{
	for(int i=0;i<dem1-1;i++)
	{
		for(int j=i+1;j<dem1;j++)
		{
			if(h[i]<h[j])
			{
				HoanVi(h[i],h[j]);
			}
		}
	}
}
// Hàm ghép chung 2 mảng G & H vào chung 1 mảng X theo đúng trình tự thì ghép mảng G vào trước & mảng H vào sau .
void MangX(int x[],int g[],int h[],int dem,int dem1)
{
	int l=0;
	for(int j=0;j<dem;j++)
	{
		x[l++]=g[j];
	}
	for(int k=0;k<dem1;k++)
	{
		x[l++]=h[k];
	}
}
// Hàm chính .
void main()
{
	quaylai:int a[14]={12,2,15,-3,8,5,1,-8,6,0,4,15}; // xây dựng mảng A theo như đề bài cho trước.
	int b[MAX],c[MAX],d[MAX],f[MAX],g[MAX],h[MAX],x[MAX]; // xây dựng các mảng cần thiết .
	int n=12,tieptuc; // Khởi tạo mảng A ban đầu có 12 phần tử .
	printf("\n>>>>>>>>>>Mang Ban Dau La:<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	SapTangDan(a,n);
	printf("\n>>>>>>>>>>Mang Sau Khi Sap Tang Dan:<<<<<<<<<<<<<<<<<<\n");
	XuatMang(a,n);
	printf("\n");
	TimSoLonThuBa(a,n);
	printf("\n");
	DemSoLuongPhanTuLonNhat(a,n);
	printf("\n");
	SapTangDanTriTuyetDoi(a,b,n);
	printf("\n>>>>>>>>>Mang Sau Khi Sap Tang Dan Tri Tuyet Doi:<<<<<<<<<<<<<\n");
	XuatMang(b,n);
	printf("\n");
	int s=SoLuongPhanTuMangC(a,n);
	int s1=SoLuongPhanTuMangD(a,n);
	TachDuongVaAm(a,c,d,n);
	SapMangCGiamDan(c,s);
	SapMangDTangDan(d,s1);
	MangF(f,c,d,s,s1);
	printf("\nMang Sau Khi Sap Xep Cac So Duong O Dau Mang Va Co Thu Tu Giam Dan,Cac So Am O Cuoi Mang Va Co Thu Tu Tang Dan:\n");
	XuatMang(f,n);
	printf("\n");
	int s2=SoLuongPhanTuMangG(a,n);
	int s3=SoLuongPhanTuMangH(a,n);
	TachChanVaLe(a,g,h,n);
	SapMangGTangDan(g,s2);
	SapMangHGiamDan(h,s3);
	MangX(x,g,h,s2,s3);
	printf("\nMang Sau Khi Sap Xep Cac So Chan O Dau Mang Va Co Thu Tu Tang Dan,Cac So Le O Cuoi Mang Va Co Thu Tu Giam Dan:\n");
	XuatMang(x,n);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); // xóa đi hết tất cả dữ liệu trước đó để bắt đầu thực thi dữ liệu mới .
		goto quaylai; // Trở lại thực thi lại từ đầu chương trình .
	}
}