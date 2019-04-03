
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
#define bool
void nhapmang(int a[MAX],int &n)
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
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[MAX],int n)
{
	printf("\n>>>>>>>>>>>>>MANG VUA NHAP LA:<<<<<<<<<<<<<<<<<<\n");
	for(int i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}
void xulydulieu(int a[MAX],int n)
{
	int dem2=0,vitri=0,Co,dem1=0,dem;
	bool Co=false;
	printf("\nLUU Y:So 0 khong phai la so duong hay so am nen ta se khong xet tai vi tri co so 0");
	printf("\nCac so thoa dieu kien bai toan la:");
	for(int i=0;i<n;i=i+n)	// ở dòng lặp for thứ hai khởi tạo i chạy từ 1 cho nên khi xét thì chỉ xét từ a[1],điều này khiến kết quả không hợp lý lắm ví dụ như a[0]=1,a[1]=-2 thì lúc này cả 2 số a[0] và a[1] đều thỏa cho nên ta phải gán thêm vòng lặp này để xác định nó có rơi vào trường hợp đó hay không ? Nếu có thì lập tức in ra giá trị a[0] và đếm nó rồi sau đó cộng tiếp số đếm vào đếm của vòng lặp 2.
	{
		if(a[i]!=0)
		{
			int c=a[i]*a[i+1];
			if(c<0)
			{
				printf("%4d",a[i]);
				dem1++;
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]!=0)
		{
			int b=a[i]*a[i-1];
			if(b<0)
			{
				printf("%4d",a[i]);
				dem2++;
			}
		}
	}
	dem=dem1+dem2;
	if(dem!=0)
	printf("\nCo %d so thoa dieu kien bai toan",dem);
	else
		printf("\nKhong co so nao thoa dieu kien");
}
void main()
{
	int a[MAX],n,tieptuc;
	quaylai:nhapmang(a,n);
	xuatmang(a,n);
	xulydulieu(a,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}