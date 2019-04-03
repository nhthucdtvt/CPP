
#include<stdio.h>
#include<conio.h>
#define MAX 100
#define bool
void nhapmang(float a[MAX],int &n)
{
	do{
		printf("Nhap vao so phan tu cua mang:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1||n>MAX);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao a[%d]=",i);
		scanf("%f",&a[i]);
	}
}
void xuatmang(float a[MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%16f",a[i]);
	}
	printf("\n");
}
void tinhtongcacgiatriduongtrongmang(float a[MAX],int n)
{
	float tong=0,Co;	// vì mảng đang ở dạng số thực nên phải khai báo tong ở dạng số thực,nếu để dạng số nguyên sẽ ra kết quả sai.
	bool Co=false;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			tong+=a[i];
			Co=true;	// ta gán biến bool Co=true để lúc in ra nếu không tồn tại giá trị dương,chương trình sẽ hiển thị ra không tồn tại dương,ở đây nếu không dùng biến bool cũng được.
		}
	}
	if(Co==true)
	printf("\nTong cac gia tri duong co trong mang la:%f",tong);
	else
	printf("\nTrong mang khong ton tai gia tri duong\n");
}
void main()
{
	float a[MAX];
	int n,tieptuc;
	quaylai:nhapmang(a,n);
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmang(a,n);
	tinhtongcacgiatriduongtrongmang(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}