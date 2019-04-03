
// Khai báo các thư viện .
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "Windows.h"
// Hàm nhập dữ liệu bài 1 .
void NHAPBAI1(int &a,int &b)
{
	do
	{
		printf("NHAP CHIEU DAI: ");
		scanf("%d",&a);
		if(a<0)
		{
			printf("\nNHAP LAI: \n");
		}
	}while(a<0);
	do
	{
		printf("\nNHAP CHIEU RONG: \n");
		scanf("%d",&b);
		if(b<0)
		{
			printf("\nNHAP LAI: \n");
		}
	}while(b<0);
}
// Hàm xử lý dữ liệu bài 1 .
void YEUCAUBAI1(int a, int b)
{
	int dientich,chuvi;
	dientich=a*b;
	chuvi=(a+b)*2;
	printf("\nCHU VI: %d\n",chuvi);
	printf("\nDIEN TICH: %d\n",dientich);
}
// Hàm trả về kết quả bài 1 .
void BAI1()
{
	int a,b;
	printf("\n>>>>>>>>>>>>>>>>> Bai 1 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI1(a,b);
	YEUCAUBAI1(a,b);
}
// Hàm nhập dữ liệu bài 2 .
void NHAPBAI2(int &a)
{
	do
	{
		printf("\nNHAP CANH: ");
		scanf("%d",&a);
		if(a<0)
		{
			printf("\nNHAP LAI: ");
		}
	}while(a<0);
}
// Hàm xử lý dữ liệu bài 2 .
void YEUCAUBAI2(int a)
{
	int chuvi,dientich;
	float duongcheo;
	chuvi=4*a;
	dientich=a*a;
	float sqrt(float a);
	duongcheo=sqrt(2*a*a);
	printf("\nCHU VI: %d",chuvi);
	printf("\nDIEN TICH : %d",dientich);
	printf("\nDUONG CHEO: %f",duongcheo);
}
// Hàm trả về kết quả bài 2 .
void BAI2()
{
	int a;
	printf("\n>>>>>>>>>>>>>>>>> Bai 2 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI2(a);
	YEUCAUBAI2(a);
}
// Hàm nhập dữ liệu bài 3 .
void NHAPBAI3(int &a,int &b)
{
	do
	{
		printf("NHAP SO A: ");
		scanf("%d",&a);
		if(a<0)
		{
			printf("NHAP LAI");
		}
	}while(a<0);
	do
	{
		printf("NHAP SO B: ");
		scanf("%d",&b);
		if(b<0)
		{
			printf("NHAP LAI");
		}
	}while(b<0);
}
// Hàm xử lý dữ liệu bài 3 .
void YEUCAUBAI3(int a,int b)
{
	int UCLN;
	int BCNN;
	int tich;
	tich=a*b;
	if(a==0&&b!=0)
	{
		UCLN=b;
	}
	if(b==0&&a!=0)
	{
		UCLN=a;
	}
	if(a!=0&&b!=0)
	{
		while(a!=b)
		{
			if(a>b)
			{
				a=a-b;
			}
			else
			{
				b=b-a;
			}
		}
		UCLN=a;
	}
	printf("\nUOC CHUNG LON NHAT: %d",UCLN);
	BCNN=tich/UCLN;
	printf("\nBOI CHUNG NHO NHAT: %d",BCNN);
}
// Hàm trả về kết quả bài 3 .
void BAI3()
{
	int a,b;
	printf("\n>>>>>>>>>>>>>>>>> Bai 3 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI3(a,b);
	YEUCAUBAI3(a,b);
}
// Hàm nhập dữ liệu bài 4 .
void NHAPBAI4(float a[])
{
	for(int i=0;i<3;i++)
	{
		printf("NHAP a[%d]: ",i);
		scanf("%f",&a[i]);
	}
}
// Hàm sắp xếp tăng dần .
void SapTangDan(float a[])
{
	int i,j;
	printf("\n>>>>>>>>>>>>>>> Sap Tang Dan <<<<<<<<<<<<<<<<<<\n");
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(a[i]>a[j])
			{
				float temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%16f",a[i],a[j]);
	}
}
// Hàm sắp xếp giảm dần .
void SapGiamDan(float a[])
{
	int i,j;
	printf("\n>>>>>>>>>>>>>>> Sap Giam Dan <<<<<<<<<<<<<<<<<<\n");
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(a[i]<a[j])
			{
				float temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		printf("%16f",a[i],a[j]);
	}
}
// Hàm trả về kết quả bài 4 .
void BAI4()
{
	float a[3];
	printf("\n>>>>>>>>>>>>>>>>> Bai 4 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI4(a);
	SapTangDan(a);
	SapGiamDan(a);
}
// Hàm nhập dữ liệu bài 5 .
void NHAPBAI5(int &a,int &b,int &c)
{
	do
	{
		printf("NHAP A: ");
		scanf("%d",&a);
		if(a<1)
		{
			printf("NHAP LAI A: ");
		}
	}while(a<1);
	do
	{
		printf("NHAP B: ");
		scanf("%d",&b);
		if(b<1)
		{
			printf("NHAP LAI B: ");
		}
	}while(b<1);
	do
	{
		printf("NHAP C: ");
		scanf("%d",&c);
		if(c<1)
		{
			printf("NHAP LAI C: ");
		}
	}while(c<1);
}
// Hàm xử lý dữ liệu bài 5 .
void YEUCAUBAI5(int a,int b,int c)
{
	if(a==b)
	{
		if(b==c)
		{
			printf("tam giac deu");
		}
		else
		{
			printf("TAM GIAC CAN");
		}
	}
	if(a==c)
	{
		if(b==c)
		{
			printf("tam giac deu");
		}
		else
		{
			printf("TAM GIAC CAN");
		}
	}
	if(b==c)
	{
		if(a==c)
		{
			printf("tam giac deu");
		}
		else
		{
			printf("TAM GIAC CAN");
		}
	}
	if((a*a+b*b>c*c)||(a*a+c*c>b*b)||(b*b+c*c>a*a))
	{
		if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
		{
			if((a==b)||(a==c)||(b==c))
			{
				printf("tam giac vuong can");
			}
			else
			{
				printf("TAM GIAC VUONG");
			}
		}
		if(!((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a)||(a==b)||(a==c)||(b==c)))
		{
			printf("TAM GIAC THUONG");
		}
	}
}
// Hàm trả về kết quả bài 5 .
void BAI5()
{
	int a,b,c;
	printf("\n>>>>>>>>>>>>>>>>> Bai 5 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI5(a,b,c);
	YEUCAUBAI5(a,b,c);
}
// Hàm nhập dữ liệu bài 6 .
void NHAPBAI6(int &a,int &b,int &c,int &d,int &e)
{
	printf("NHAP A:");
	scanf("%d",&a);
	printf("NHAP B:");
	scanf("%d",&b);
	printf("NHAP C:");
	scanf("%d",&c);
	printf("NHAP D:");
	scanf("%d",&d);
	printf("NHAP E:");
	scanf("%d",&e);
}
// Hàm xử lý dữ liệu bài 6 .
void YEUCAUBAI6(int a,int b,int c,int d,int e)
{
	float TBC;
	TBC=float(a+b+c+d+e)/5;
	printf("Trung Binh Cong: %f",TBC);
}
// Hàm trả về kết quả bài 6 .
void BAI6()
{
	int a,b,c,d,e;
	printf("\n>>>>>>>>>>>>>>>>> Bai 6 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI6(a,b,c,d,e);
	YEUCAUBAI6(a,b,c,d,e);
}
// Hàm nhập dữ liệu bài 7 .
void NHAPBAI7(int &n)
{
	do
	{
		printf("NHAP N: ");
		scanf("%d",&n);
		if(n<1)
		{
			printf("nhap lai");
		}
	}while(n<1);
}
// Hàm tính S1 .
void S1(int n)
{
	int S1=0;
	for(int i=0;i<=n;i++)
	{
		S1=S1+i;
	}
	printf("\nS1= %d\n",S1);
}
// Hàm tính S2 .
void S2(int n)
{
	int S2=1;
	for(int i=1;i<=n;i++)
	{
		S2=S2*i;
	}
	printf("\nS2= %d\n",S2);
}
// Hàm tính S3 .
void S3(int n)
{
	float S3=0;
	for(int i=1;i<=n;i++)
	{
		S3=S3+float (1)/i;
	}
	printf("\nS3= %f\n",S3);
}
// Hàm tính S4 .
void S4(int n)
{
	int S4=0;
	float pow(float x,float y);
	for(int i=1;i<=n;i++)
	{
		S4=S4+pow(i,2);
	}
	printf("\nS4= %d\n",S4);
}
// Hàm trả về kết quả bài 7 .
void BAI7()
{
	int n;
	printf("\n>>>>>>>>>>>>>>>>> Bai 7 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI7(n);
	S1(n);
	S2(n);
	S3(n);
	S4(n);
}
// Hàm nhập dữ liệu bài 8 .
void NHAPBAI8(int &n)
{
	printf("NHAP N: ");
	scanf("%d",&n);
}
// Hàm kiểm tra nguyên tố .
void NGUYENTO(int n)
{
	int f;
	f=1;
	if(n<2)
	{
		f=0;
	}
	for(int j=2;j<=n/2;j++)
	{
		if(n%j==0)
		{
			f=0;
		}
	}
	printf("\nSo %d co phai la so nguyen to ? ",n);
	if(f==1)
		printf("YES");	
	else
		printf("NO");
}
// Hàm kiểm tra số hoàn thiện .
void HOANTHIEN(int n)
{
	int tong=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			tong+=i;
		}
	}
	printf("\nSo %d co phai la so hoan thien ? ",n);
	if(tong==n)
		printf("YES");
	else
		printf("NO");
}
// Hàm kiểm tra số chính phương .
void CHINHPHUONG(int n)
{
	float sqrt(float x);
	float ketqua=sqrt(n);
	printf("\nSo %d co phai la so chinh phuong ? ",n);
	if(ketqua==(int)ketqua)
		printf("YES");
	else
		printf("NO");
}
// Hàm trả về kết quả bài 8 .
void BAI8()
{
	int n;
	printf("\n>>>>>>>>>>>>>>>>> Bai 8 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI8(n);
	NGUYENTO(n);
	HOANTHIEN(n);
	CHINHPHUONG(n);
}
// Hàm nhập dữ liệu bài 9 .
void NHAPBAI9(int &n)
{
	do
	{
		printf("NHAP SO: ");
		scanf("%d",&n);
		if(n<0||n>10000)
		{
			printf("NHAP LAI");
		}
	}while(n<0||n>10000);
}
// Hàm liệt kê các số nguyên tố .
void NT(int n)
{
	int dem=0;
	printf("\n>>>>>>>>>> %d So Nguyen To Dau Tien <<<<<<<<<<<<<<<\n",n);
	for(int i=2;i<=10000;i++)
	{
		int f=1;
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				f=0;
			}
		}
		if(f==1)
		{
			dem++;
			if(dem<=n)
			{
				printf("%8d",i);
			}
		}
	}
}
// Hàm liệt kê các số chính phương .
void CP(int n)
{
	int dem=0;
	float sqrt(float x);
	printf("\n>>>>>>>>>> %d So Chinh Phuong Dau Tien <<<<<<<<<<<<<<<\n",n);
	for(int i=0;i<=10000;i++)
	{
		float kq=sqrt(i);
		if(kq==(int)kq)
		{
			dem++;
			if(dem<=n)
			{
				printf("%8d",i);
			}
		}
	}
}
// Hàm liệt kê các số chẵn .
void C(int n)
{
	int dem=0;
	printf("\n>>>>>>>>>> %d So Chan Dau Tien <<<<<<<<<<<<<<<\n",n);
	for(int i=0;i<=10000;i++)
	{
		if(i%2==0)
		{
			dem++;
			if(dem<=n)
			{
				printf("%8d",i);
			}
		}
	}
}
// Hàm trả về kết quả bài 9 .
void BAI9()
{
	int n;
	printf("\n>>>>>>>>>>>>>>>>> Bai 9 <<<<<<<<<<<<<<<<<<<<<<\n");
	NHAPBAI9(n);
	NT(n);
	CP(n);
	C(n);
}
// Hàm xử lý dữ liệu bài 10 .
void TONGCHAN(int &i)
{
	printf("\n>>>>>>>>>>>>>>>>>>> Cac So Thoa Yeu Cau La <<<<<<<<<<<<<<<<<<<<\n");
	for(i=100;i<=999;i++)
	{
		int temp=i;
		int tong=0;
		while(temp!=0)
		{
			tong+=temp%10;
			temp=temp/10;
		}
		if(tong%2==0)
		{
			printf("%8d",i);
		}
	}
}
// Hàm trả về kết quả bài 10 .
void BAI10()
{
	int i;
	printf("\n>>>>>>>>>>>>>>>>> Bai 10 <<<<<<<<<<<<<<<<<<<<<<\n");
	TONGCHAN(i);
}
// Hàm xử lý dữ liệu bài 11 .
void XuLyDuLieu(int &n)
{
	printf("\n>>>>>>> Cac So Nho Hon 10 000 Va Co Tong Cac Chu So = Tich Cac Chu So <<<<<<<<<\n");
	printf("\n");
	for(n=0;n<10000;n++)
	{
		int temp=n;
		int tong=0;
		int tich=1;
		while(temp!=0)
		{
			tong+=temp%10;
			tich*=temp%10;
			temp/=10;
		}
		if(tong==tich)
		{
			printf("%8d",n);
		}		
	}
	printf("\n");
}
// Hàm trả về kết quả bài 11 .
void BAI11()
{
	int n;
	printf("\n>>>>>>>>>>>>>>>>> Bai 11 <<<<<<<<<<<<<<<<<<<<<<\n");
	XuLyDuLieu(n);
}
// Hàm nhập dữ liệu bài 12 .
void NhapN(unsigned long &n)
{
	do{
		printf("\nNhap vao so nguyen N=");
		scanf("%lu",&n);
		if(n<=100000)
		{
			printf("\nGia tri N khong hop le!Xin vui long nhap lai!");
		}
	}while(n<=100000);
}
// Hàm xử lý dữ liệu bài 12 .
void PhuongAn(unsigned long n)
{
	unsigned long dem=0;
	unsigned long a,b,c;
	printf("\n--------------------------------------------------------------------------------");
	printf("Cach Thu \t");
	printf("So To 10 000 \t");
	printf("So To 20 000 \t");
	printf("So To 50 000 \t");
	printf("\n--------------------------------------------------------------------------------");
	for(a=0;a<=n/10000;a++)
	{
		for(b=0;b<=n/20000;b++)
		{
			for(c=0;c<=n/50000;c++)
			{
				if(a*10000+b*20000+c*50000==n)
				{
					dem++;
					printf("%lu\t\t\t",dem);
					printf("%lu\t\t",a);
					printf("%lu\t\t",b);
					printf("%lu\t",c);
					printf("\n--------------------------------------------------------------------------------");
				}
			}
		}
	}
	printf("\n");
	printf("\nTong cong ta co %lu cach de tra %lu dong",dem,n);
}
// Hàm trả về kết quả bài 12 .
void BAI12()
{
	unsigned long n;
	printf("\n>>>>>>>>>>>>>>>>> Bai 12 <<<<<<<<<<<<<<<<<<<<<<\n");
	NhapN(n);
	PhuongAn(n);
}
// Hàm nhập dữ liệu bài 13 .
void NhapN(int &n)
{
	do
	{
		printf("\nNhap vao so giay:");
		scanf("%d",&n);
		if(n<0)
		{
			printf("\nSo giay khong hop le!Xin vui long nhap lai!");
		}
	}while(n<0);
}
// Hàm xử lý dữ liệu bài 13 .
void ChuyenDoi(int n)
{
	int gio,phut,giay;
	gio=n/3600;
	phut=(n-(gio*3600))/60;
	giay=n-(gio*3600+phut*60);
	printf("\nChuyen doi ra thanh: %d:%d:%d",gio,phut,giay);
}
// Hàm trả về kết quả bài 13 .
void BAI13()
{
	int n;
	printf("\n>>>>>>>>>>>>>>>>> Bai 13 <<<<<<<<<<<<<<<<<<<<<<\n");
	NhapN(n);
	ChuyenDoi(n);
}
// Hàm nhập dữ liệu ngày-tháng-năm .
void NhapDuLieu(int &ngay,int & thang,int &nam)
{
	quaylai:printf("\nNhap vao nam:");
	scanf("%d",&nam);
	if(nam<1)
	{
		printf("\nNam khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	quaylai1:printf("\nNhap vao thang:");
	scanf("%d",&thang);
	if(thang<1||thang>12)
	{
		printf("\nThang khong hop le!Xin vui long nhap lai!");
		goto quaylai1;
	}
	quaylai2:printf("\nNhap vao ngay:");
	scanf("%d",&ngay);
	if(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10||thang==12)
	{
		if(ngay<1||ngay>31)
		{
			printf("\nNgay khong hop le!Xin vui long nhap lai!");
			goto quaylai2;
		}
	}
	else if(thang==4||thang==6||thang==9||thang==11)
	{
		if(ngay<1||ngay>30)
		{
			printf("\nNgay khong hop le!Xin vui long nhap lai!");
			goto quaylai2;
		}
	}
	// Năm nhuận => tháng 2 có 29 ngày .
	if(nam%400==0)
	{
		if(thang==2)
		{
			if(ngay<1||ngay>29)
			{
				printf("\nNgay khong hop le!Xin vui long nhap lai!");
				goto quaylai2;
			}
		}
	}
	// Năm không nhuận => tháng 2 có 28 ngày .
	else if(nam%4!=0)
	{
		if(thang==2)
		{
			if(ngay<1||ngay>28)
			{
				printf("\nNgay khong hop le!Xin vui long nhap lai!");
				goto quaylai2;
			}
		}
	}
}
// Hàm xuất dữ liệu ngày-tháng-năm vừa nhập .
void XuatDuLieu(int ngay,int thang,int nam)
{
	printf("\n>>>>>>>>>>>>>>>>>> Du Lieu Ngay,Thang,Nam Vua Nhap <<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngay);
	printf("%d \t\t",thang);
	printf("%d \t\t",nam);
	printf("\n-------------------------------------------------------------------\n");
}
// Hàm xuất ra dữ liệu ngày-tháng-năm kế tiếp .
void KeTiep(int ngay,int thang,int nam)
{
	int ngayketiep,thangketiep,namketiep;
	if(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10)
	{
		if(ngay>=1&&ngay<=30)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==31)
		{
			ngayketiep=1;
			thangketiep=thang+1;
			namketiep=nam;
		}
	}
	else if(thang==12)
	{
		if(ngay>=1&&ngay<=30)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==31)
		{
			ngayketiep=1;
			thangketiep=1;
			namketiep=nam+1;
		}
	}
	else if(thang==4||thang==6||thang==9||thang==11)
	{
		if(ngay>=1&&ngay<=29)
		{
			ngayketiep=ngay+1;
			thangketiep=thang;
			namketiep=nam;
		}
		else if(ngay==30)
		{
			ngayketiep=1;
			thangketiep=thang+1;
			namketiep=nam;
		}
	}
	else if(thang==2)
	{
		// Năm nhuận => tháng 2 có 29 ngày .
		if(nam%400==0)
		{
			if(ngay>=1&&ngay<=28)
			{
				ngayketiep=ngay+1;
				thangketiep=thang;
				namketiep=nam;
			}
			else if(ngay==29)
			{
				ngayketiep=1;
				thangketiep=thang+1;
				namketiep=nam;
			}
		}
		// Năm không nhuận => tháng 2 có 28 ngày .
		else if(nam%4!=0)
		{
			if(ngay>=1&&ngay<=27)
			{
				ngayketiep=ngay+1;
				thangketiep=thang;
				namketiep=nam;
			}
			else if(ngay==28)
			{
				ngayketiep=1;
				thangketiep=thang+1;
				namketiep=nam;
			}
		}
	}
	printf("\n>>>>>>>>>>>>>>>>>> Du Lieu Ngay,Thang,Nam Ke Tiep <<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngayketiep);
	printf("%d \t\t",thangketiep);
	printf("%d \t\t",namketiep);
	printf("\n-------------------------------------------------------------------\n");
}
// Hàm xuất ra dữ liệu ngày-tháng-năm trước đó .
void TruocDo(int ngay,int thang,int nam)
{
	int ngaytruocdo,thangtruocdo,namtruocdo;
	if(thang==2||thang==4||thang==6||thang==8||thang==9||thang==11)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=31;
			thangtruocdo=thang-1;
			namtruocdo=nam;
		}
	}
	else if(thang==1)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=31;
			thangtruocdo=12;
			namtruocdo=nam-1;
		}
	}
	else if(thang==5||thang==7||thang==10||thang==12)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			ngaytruocdo=30;
			thangtruocdo=thang-1;
			namtruocdo=nam;
		}
	}
	else if(thang==3)
	{
		if(ngay>=2)
		{
			ngaytruocdo=ngay-1;
			thangtruocdo=thang;
			namtruocdo=nam;
		}
		else if(ngay==1)
		{
			// Năm nhuận => tháng 2 có 29 ngày .
			if(nam%400==0)
			{
				ngaytruocdo=29;
				thangtruocdo=thang-1;
				namtruocdo=nam;
			}
			// Năm không nhuận => tháng 2 có 28 ngày .
			else if(nam%4!=0)
			{
				ngaytruocdo=28;
				thangtruocdo=thang-1;
				namtruocdo=nam;
			}
		}
	}
	printf("\n>>>>>>>>>>>>>>>>>> Du Lieu Ngay,Thang,Nam Truoc Do <<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nNgay \t\t");
	printf("Thang \t\t");
	printf("Nam \t\t");
	printf("\n");
	printf("\n%d \t\t",ngaytruocdo);
	printf("%d \t\t",thangtruocdo);
	printf("%d \t\t",namtruocdo);
	printf("\n-------------------------------------------------------------------\n");
}
// Hàm trả về kết quả bài 14 .
void BAI14()
{
	int ngay,thang,nam;
	printf("\n>>>>>>>>>>>>>>>>> Bai 14 <<<<<<<<<<<<<<<<<<<<<<\n");
	NhapDuLieu(ngay,thang,nam);
	XuatDuLieu(ngay,thang,nam);
	KeTiep(ngay,thang,nam);
	TruocDo(ngay,thang,nam);
}
// Hàm nhập dữ liệu bài 15 .
void Nhapn(int &n)
{
	do{
		printf("\nNhap vao thang:");
		scanf("%d",&n);
		if(n<1||n>12)
		{
			printf("\nThang ban nhap vao khong hop le!Xin vui long nhap lai!");
		}
	}while(n<1||n>12);
}
// Hàm xử lý dữ liệu bài 15 .
void XuLyDuLieuBai15(int n)
{
	if(n==1||n==3||n==5||n==7||n==8||n==10||n==12)
	{
		printf("\nThang %d co 31 ngay",n);
	}
	else if(n==4||n==6||n==9||n==11)
	{
		printf("\nThang %d co 30 ngay",n);
	}
	else if(n==2)
	{
		printf("\nThang %d co 28 hoac 29 ngay",n);
	}
}
// Hàm trả về kết quả bài 15 .
void BAI15()
{
	int n;
	printf("\n>>>>>>>>>>>>>>>>> Bai 15 <<<<<<<<<<<<<<<<<<<<<<\n");
	Nhapn(n);
	XuLyDuLieuBai15(n);
}
// Hàm MeNu .
void MeNu()
{
	int luachon;
	quaylai1:printf("\n------------------------- MeNu --------------------------\n");
	printf("\n1.  Bai 1 ");
	printf("\n2.  Bai 2 ");
	printf("\n3.  Bai 3 ");
	printf("\n4.  Bai 4 ");
	printf("\n5.  Bai 5 ");
	printf("\n6.  Bai 6 ");
	printf("\n7.  Bai 7 ");
	printf("\n8.  Bai 8 ");
	printf("\n9.  Bai 9 ");
	printf("\n10. Bai 10 ");
	printf("\n11. Bai 11 ");
	printf("\n12. Bai 12 ");
	printf("\n13. Bai 13 ");
	printf("\n14. Bai 14 ");
	printf("\n15. Bai 15 ");
	printf("\n0.  Thoat Chuong Trinh ");
	printf("\n---------------------------------------------------------\n");
	printf("\n");
	quaylai:printf("\nNhap Vao Lua Chon Cua Ban:");
	scanf("%d",&luachon);
	printf("\n");
	printf("\nKet Qua:");
	if(luachon==1)
	{
		system("cls"); 
		BAI1();
		goto quaylai1; 
	}
	else if(luachon==2)
	{
		system("cls"); 
		BAI2();
		goto quaylai1; 
	}
	else if(luachon==3)
	{
		system("cls"); 
		BAI3();
		goto quaylai1; 
	}
	else if(luachon==4)
	{
		system("cls"); 
		BAI4();
		goto quaylai1; 
	}
	else if(luachon==5)
	{
		system("cls"); 
		BAI5();
		goto quaylai1; 
	}
	else if(luachon==6)
	{
		system("cls"); 
		BAI6();
		goto quaylai1; 
	}
	else if(luachon==7)
	{
		system("cls"); 
		BAI7();
		goto quaylai1; 
	}
	else if(luachon==8)
	{
		system("cls"); 
		BAI8();
		goto quaylai1; 
	}
	else if(luachon==9)
	{
		system("cls"); 
		BAI9();
		goto quaylai1; 
	}
	else if(luachon==10)
	{
		system("cls"); 
		BAI10();
		goto quaylai1; 
	}
	else if(luachon==11)
	{
		system("cls"); 
		BAI11();
		goto quaylai1; 
	}
	else if(luachon==12)
	{
		system("cls"); 
		BAI12();
		goto quaylai1; 
	}
	else if(luachon==13)
	{
		system("cls"); 
		BAI13();
		goto quaylai1; 
	}
	else if(luachon==14)
	{
		system("cls"); 
		BAI14();
		goto quaylai1; 
	}
	else if(luachon==15)
	{
		system("cls"); 
		BAI15();
		goto quaylai1; 
	}
	else if(luachon==0)
	{
		system("cls"); 
		printf("\nThanks You For Using The Program ! Goodbye And See You Later !\n"); 
	}
	if(luachon!=1&&luachon!=2&&luachon!=3&&luachon!=4&&luachon!=5&&luachon!=6&&luachon!=7&&luachon!=8&&luachon!=9&&luachon!=10&&luachon!=11&&luachon!=12&&luachon!=13&&luachon!=14&&luachon!=15&&luachon!=0)
	{
		printf("\nLua chon ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; 
	}
}
// Hàm chính .
void main()
{
	MeNu();
}
