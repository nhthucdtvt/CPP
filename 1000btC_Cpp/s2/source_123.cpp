
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<limits.h>
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
	printf("\n>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void lietketatca(int a[MAX],int n)
{
    int Co,dem=0;
	bool Co=false;
	printf("\nCac gia tri thoa man yeu cau de bai la:");
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
			float log(float(x)); //Khai báo trước hàm log thì mới dùng được và ta gán đại cho nó 1 biến bất kỳ.ví dụ :biến x. Điều này khác với C (chuẩn) không cần khai báo.
            float c= log(a[i])/log (5);
            if(c==floor(c))
            {
				printf("%4d",a[i]);
				dem++;
				Co=true;
            }
        }
    }
    if(Co==true)
    printf("\nTrong mang co %d gia tri thoa man yeu cau de bai",dem);
	else
	printf("\n0");
}
void giatrilonnhat(int a[MAX],int n)
{
	int i,Co,max=INT_MIN;
	bool Co=false;
	for(i=0;i<n;i++)
    {
        if(a[i]>0)
        {
			float log(float(x)); //Khai báo trước hàm log thì mới dùng được và ta gán đại cho nó 1 biến bất kỳ.ví dụ :biến x. Điều này khác với C (chuẩn) không cần khai báo.
            float c= log(a[i])/log (5);
            if(c==floor(c))
            {
				if(a[i]>max)
				{
					max=a[i];
					Co=true;
				}
            }
        }
    }
    if(Co==true)
    printf("\nGia tri lon nhat thoa dieu kien la:%d",max);
}
void main()
{
	int a[MAX],n,NAMSON;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	lietketatca(a,n);
	giatrilonnhat(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky phim nao khac de ket thuc\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}