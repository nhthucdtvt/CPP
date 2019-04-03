
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "Windows.h"
// Khai báo cấu trúc dữ liệu danh sách liên kết đơn các số nguyên dương lẻ .
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
	quaylai:printf("\nNhap vao so luong cac so nguyen duong le:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		int x;
		do{
			printf("\nNhap vao so nguyen duong le thu %d:",i);
			scanf("%d",&x);
			if(x<0||x%2==0)
			{
				printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
			}
		}while(x<0||x%2==0);
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
// Xuất dữ liệu danh sách liên kết đơn .
void OutPut(LIST l)
{
	printf("\n>>>>>>>>>>>>>>>>> Danh Sach Cac So Nguyen Duong Le <<<<<<<<<<<<<<<<<<\n");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%4d",p->Data);
	}
}
// Liệt kê và tính tổng tất cả các số chính phương có trong danh sách liên kết đơn .
void LietKeVaTinhTongCacSoChinhPhuong(LIST l)
{
	int tong=0;
	NODE*pNode;
	float sqrt(float x);
	printf("\nCac so chinh phuong co trong danh sach la:");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		float ketqua=sqrt(pNode->Data);
		if((float)ketqua==(int)ketqua)
		{
			printf("%4d",pNode->Data); // Liệt kê ra tất cả các số chính phương có trong danh sách .
			tong+=pNode->Data; // Tính tổng tất cả các số chính phương có trong danh sách .
		}
	}
	printf("\n");
	printf("\nTong cac so chinh phuong co trong danh sach la:%d",tong);
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
	LietKeVaTinhTongCacSoChinhPhuong(lst);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}