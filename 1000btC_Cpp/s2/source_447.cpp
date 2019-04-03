
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "Windows.h"
#define MAX 6
// Khai báo cấu trúc dữ liệu danh sách liên kết đơn các số nguyên .
struct node
{
	int Data;
	struct node*pNext;
};
typedef struct node NODE;
struct list
{
	NODE*pHead;
	NODE*pTail;
};
typedef struct list LIST;
// Khởi tạo danh sách liên kết đơn .
void INit(LIST &l)
{
	l.pHead=NULL;
	l.pTail=NULL;
}
// Tạo Node trong danh sách liên kết đơn .
NODE*getnode(int x)
{
	NODE*p;
	p=new NODE;
	if(p==NULL)
		return NULL;
	p->Data=x;
	p->pNext=NULL;
	return p;
}
// Thêm vào cuối danh sách liên kết đơn .
void AddTail(LIST &l,NODE*new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		l.pTail->pNext=new_ele;
		l.pTail=new_ele;
	}
}
// Nhập dữ liệu cho danh sách liên kết đơn .
void InPut(LIST &l)
{
	int n;
	quaylai:printf("\nNhap vao so luong cac so nguyen:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		int x;
		printf("\nNhap vao so nguyen thu %d:",i);
		scanf("%d",&x);
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
// Xuất dữ liệu của danh sách liên kết đơn .
void OutPut(LIST l)
{
	printf("\n>>>>>>>>>>>>>>> Danh Sach Cac So Nguyen <<<<<<<<<<<<<<<<<<<<<\n");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%10d",p->Data);
	}
}
// Liệt kê các số nguyên tố có trong danh sách liên kết đơn .
void NguyenTo(LIST l)
{
	int f;
	NODE*pNode;
	printf("\n>>>>>>>>>>>>>>>>> Cac So Nguyen To <<<<<<<<<<<<<<<<<<<<<\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		f=1;
		if(pNode->Data<2)
		{
			f=0;
		}
		for(int j=2;j<=(pNode->Data)/2;j++)
		{
			if(pNode->Data%j==0)
			{
				f=0;
			}
		}
		if(f==1)
		{
			printf("%4d",pNode->Data);
		}
	}
}
// Liệt kê các số chính phương có trong danh sách liên kết đơn .
void ChinhPhuong(LIST l)
{
	NODE*pNode;
	float sqrt(float x);
	printf("\n>>>>>>>>>>>>>>>>> Cac So Chinh Phuong <<<<<<<<<<<<<<<<<<<<<\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		float ketqua=sqrt(pNode->Data);
		if((float)ketqua==(int)ketqua) // Ép kiểu để kiểm tra xem số đó có phải là số chính phương hay không ? ví dụ : số 4 sẽ là số chính phương vì căn của 4 = 2 (giá trị nguyên) . ta thực hiện ép kiểu giá trị căn của 4 để kiểm tra . tính căn của 4 ở dạng thực sẽ ra là 2.00000 và ép về dạng nguyên sẽ ra là 2 . So sánh thấy chúng bằng nhau => số chính phương . Ngược lại ví dụ số 5 khai căn ra sẽ là 2.236067978 và khi ép về kiểu nguyên sẽ là 2 . So sánh thấy chúng không bằng nhau => không phải là số chính phương .
		{
			printf("%4d",pNode->Data);
		}
	}
}
// Liệt kê các số hoàn thiện có trong danh sách liên kết đơn .
void HoanThien(LIST l)
{
	NODE*pNode;
	printf("\n>>>>>>>>>>>>>>>>> Cac So Hoan Thien <<<<<<<<<<<<<<<<<<<<<\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		int tong=0;
		for(int j=1;j<pNode->Data;j++)
		{
			if(pNode->Data%j==0)
			{
				tong+=j;
			}
		}
		if(tong==pNode->Data)
		{
			printf("%4d",pNode->Data);
		}
	}
}
// Liệt kê các số đối xứng có trong danh sách liên kết đơn .
void DoiXung(LIST l)
{
	NODE*pNode;
	printf("\n>>>>>>>>>>>>>>>>> Cac So Doi Xung <<<<<<<<<<<<<<<<<<<<<\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		int reverse = 0; // Số đảo ngược của số đang cần xét .
		int temp = pNode->Data; // Copy giá trị của số đang cần xét vào biến temp để lưu trữ lại giá trị của số đó vì trong quá trình chạy thuật toán thì giá trị của số đó sẽ bị thay đổi .
		// 1. Đảo ngược số n
		while(temp>0)
		{
			int digit = temp % 10;
			reverse = reverse * 10 + digit;
			temp = temp / 10;
		}
		// 2. Kiểm số đảo ngược của số đang cần xét có bằng chính nó hay không?
		//	+ Nếu bằng, số đó chính là số đối xứng => in ra màn hình .
		//	+ Ngược lại,số đó không phải là số đối xứng .
		if(reverse == pNode->Data)
		{
			printf("%6d",pNode->Data);
		}
	}
}
// Liệt kê các số Amstrong có trong danh sách liên kết đơn .
void Amstrong(LIST l)
{
	int a[MAX];
	NODE*pNode;
	float pow(float x,float y);
	printf("\n>>>>>>>>>>>>>>>>> Cac So Amstrong <<<<<<<<<<<<<<<<<<<<<\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		int i=0;
		int temp = pNode->Data; // Copy giá trị của số đang cần xét vào biến temp để lưu trữ lại giá trị của số đó vì trong quá trình chạy thuật toán thì giá trị của số đó sẽ bị thay đổi .
		while(temp!=0)
		{
			a[i]=temp%10; // Lưu các chữ số vào mảng a .
			temp=temp/10;
			i++; // tăng biến i lên .
		}
		int tong=0; // khởi tạo tổng=0 .
		for(int k=i-1;k>=0;k--)
		{
			tong+=pow(a[k],i); // i lúc này chính là số lượng chữ số của số đang cần xét , còn mảng a[k] chính là từng chữ số của số đó .
		}
		if(tong==pNode->Data) // nếu tổng = đúng số ban đầu => đó là số Amstrong và in ra màn hình .
		{
			printf("%10d",pNode->Data);
		}
	}
}
// Hàm chính .
void main()
{
	int tieptuc;
	LIST lst;
	quaylai:InPut(lst);
	printf("\n");
	OutPut(lst);
	printf("\n");
	NguyenTo(lst);
	printf("\n");
	ChinhPhuong(lst);
	printf("\n");
	HoanThien(lst);
	printf("\n");
	DoiXung(lst);
	printf("\n");
	Amstrong(lst);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc! ");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}