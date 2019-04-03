
#include<stdio.h>
#include<conio.h>
#include<cmath>
#define MAX 100
#define bool
void nhapmang(int a[MAX],int &n)
{
	do{
	printf("Nhap vao so phan tu cua mang:n=");
	scanf("%d",&n);
	if(n<1||n>MAX)
	printf("So ban nhap vao khong hop le!Xin ban vui long nhap lai!\n");
	else
	break;
	}while(n<1||n>MAX);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[MAX],int n)
{
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
    int i,j,Co,dem=0,Co1,vitri=0,Co2;
    bool Co=false;
	bool Co1=false; //	=> nhất thiết phải đặt bool Co1=false & bool Co2=false thì bài toán mới chạy được do 2 biến bool lúc này đã được xác định.
	bool Co2=false;
	float sqrt(float (x)); // =>Ở C chuẩn (Code Block) thì không cần dòng khai báo này nhưng vì visual studio là C++ nên ta phải khai báo trước hàm sqrt và gán đại nó cho 1 biến bất kỳ.ví dụ:biến x.
	printf("\nCac so chinh phuong co trong mang la:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=a[i];j++)
        {            
			if(sqrt(a[i])==j)
            {
               printf("%4d",a[i]);
			   dem++;
			   Co=true;
            }
        }
    }
    if(Co==true)
    printf("\nTrong mang co %d so chinh phuong",dem);
    else
    printf("\nTrong mang khong co so chinh phuong nao ca");
	for(i=0;i<n;i++)
    {
        for(j=0;j<=a[i];j++)
        {
            if(sqrt(a[i])==j)
            {
			   Co1=true; //Ở đây vì trong cùng 1 hàm cho nên ta không thể dùng lại biến Co=true được mà ta phải dùng biến khác là Co1 và Co2 thì kết quả mới đúng được.
            }
        }
		if(Co1==true)
		{
			Co2=true;	//Ở đây vì trong cùng 1 hàm cho nên ta không thể dùng lại biến Co=true được mà ta phải dùng biến khác là Co1 và Co2 thì kết quả mới đúng được.
			vitri=i;
			break;
		}
    }
	if(Co2==true)
		printf("\nSo chinh phuong dau tien la:%d tai vi tri:%d",a[i],vitri);
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}
