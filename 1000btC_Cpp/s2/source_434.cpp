
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<Windows.h>
// Khai báo struct Node .
struct node
{
	int Data;
	struct node*pNext;
};
typedef struct node NODE;
// Khai báo struct List .
struct list
{
	NODE*pHead;
	NODE*pTail;
};
typedef struct list LIST;
// Khởi tạo List .
void INit(LIST &l)
{
	l.pHead=NULL;
	l.pTail=NULL;
}
// Duyệt List .
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
// Thêm vào đầu List .
void AddHead(LIST &l,NODE *new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead=new_ele;
		l.pTail=l.pHead;
	}
	else
	{
		new_ele->pNext=l.pHead;
		l.pHead=new_ele;
	}
}
// Thêm vào cuối List .
void AddTail(LIST &l,NODE *new_ele)
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
// Hàm nhập dữ liệu .
void InPut(LIST &l)
{
	int n;
	quaylai:printf("\nNhap vao so luong cac node:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		int x;
		printf("\nNhap vao node thu %d:",i);
		scanf("%d",&x);
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
// Hàm xuất dữ liệu .
void OutPut(LIST l)
{
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%4d",p->Data);
	}
}
// Hàm xử lý dữ liệu trên tất cả các Node .
void LietKeDemTinhTongTinhTichTimMaxTimMinCacNode(LIST l)
{
	int dem=0,tong=0,tich=1;
	int max=INT_MIN;
	int min=INT_MAX;
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%4d",p->Data);
		dem++;
		tong+=p->Data;
		tich*=p->Data;
		if(p->Data>max)
		{
			max=p->Data;
		}
		if(p->Data<min)
		{
			min=p->Data;
		}
	}
	printf("\n");
	printf("\nSo Luong Cac Node La:%d",dem);
	printf("\n");
	printf("\nTong Cac Node La:%d",tong);
	printf("\n");
	printf("\nTich Cac Node La:%d",tich);
	printf("\n");
	printf("\nNode Lon Nhat La:%d",max);
	printf("\n");
	printf("\nNode Nho Nhat La:%d",min);
}
// Hàm xử lý dữ liệu trên các Node dương .
void LietKeDemTinhTongTinhTichTimMaxTimMinCacNodeDuong(LIST l)
{
	int dem=0,tong=0,tich=1;
	int max=INT_MIN;
	int min=INT_MAX;
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		if(p->Data>=0)
		{
			printf("%4d",p->Data);
			dem++;
			tong+=p->Data;
			tich*=p->Data;
			if(p->Data>max)
			{
				max=p->Data;
			}
			if(p->Data<min)
			{
				min=p->Data;
			}
		}
	}
	printf("\n");
	printf("\nSo Luong Cac Node Duong La:%d",dem);
	printf("\n");
	printf("\nTong Cac Node Duong La:%d",tong);
	printf("\n");
	printf("\nTich Cac Node Duong La:%d",tich);
	printf("\n");
	printf("\nNode Duong Lon Nhat La:%d",max);
	printf("\n");
	printf("\nNode Duong Nho Nhat La:%d",min);
}
// Hàm xử lý dữ liệu trên các Node âm .
void LietKeDemTinhTongTinhTichTimMaxTimMinCacNodeAm(LIST l)
{
	int dem=0,tong=0,tich=1;
	int max=INT_MIN;
	int min=INT_MAX;
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		if(p->Data<0)
		{
			printf("%4d",p->Data);
			dem++;
			tong+=p->Data;
			tich*=p->Data;
			if(p->Data>max)
			{
				max=p->Data;
			}
			if(p->Data<min)
			{
				min=p->Data;
			}
		}
	}
	printf("\n");
	printf("\nSo Luong Cac Node Am La:%d",dem);
	printf("\n");
	printf("\nTong Cac Node Am La:%d",tong);
	printf("\n");
	printf("\nTich Cac Node Am La:%d",tich);
	printf("\n");
	printf("\nNode Am Lon Nhat La:%d",max);
	printf("\n");
	printf("\nNode Am Nho Nhat La:%d",min);
}
// Hàm thêm vào cuối danh sách liên kết đơn một giá trị nguyên .
void ThemVaoCuoi(LIST l)
{
	int x;
	printf("\nNhap Vao Gia Tri Can Them Vao Cuoi Danh Sach Lien Ket Don:");
	scanf("%d",&x);
	NODE*p=getnode(x);
	AddTail(l,p);
}
// Hàm hoán vị 2 Node .
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
// Hàm sắp danh sách tăng dần .
void SapTangDan(LIST l)
{
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(NODE*q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data>q->Data)
			{
				HoanVi(p->Data,q->Data);
			}
		}
	}
}
// Hàm sắp danh sách giảm dần .
void SapGiamDan(LIST l)
{
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(NODE*q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data<q->Data)
			{
				HoanVi(p->Data,q->Data);
			}
		}
	}
}
// Hàm tăng kích cỡ chiều rộng và chiều cao của khung CMD .
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm MeNu .
void MeNu()
{
	resizeConsole(2000,1000);
	int tieptuc;
	LIST lst;
	quaylai:printf("\n>>>>>>>>>>>>>>>>Nhap List:<<<<<<<<<<<<<<<<<\n");
	InPut(lst);
	printf("\n>>>>>>>>>>>>>>>>>>>>Xuat List:<<<<<<<<<<<<<<<<<<<<\n");
	OutPut(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>Xu Ly Cac Node:<<<<<<<<<<<<<<<<<<<<<\n");
	LietKeDemTinhTongTinhTichTimMaxTimMinCacNode(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>>>>Xu Ly Cac Node Duong:<<<<<<<<<<<<<<<<<<<<<<<\n");
	LietKeDemTinhTongTinhTichTimMaxTimMinCacNodeDuong(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>>>>Xu Ly Cac Node Am:<<<<<<<<<<<<<<<<<<<<<<\n");
	LietKeDemTinhTongTinhTichTimMaxTimMinCacNodeAm(lst);
	printf("\n");
	ThemVaoCuoi(lst);
	printf("\n>>>>>>>>>>>>>>Danh Sach Sau Khi Them Vao Cuoi La:<<<<<<<<<<<<<<<<<<<<\n");
	OutPut(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>Sap Danh Sach Tang Dan:<<<<<<<<<<<<<<<<<<<<<<\n");
	SapTangDan(lst);
	OutPut(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>Sap Danh Sach Giam Dan:<<<<<<<<<<<<<<<<<<<<<<\n");
	SapGiamDan(lst);
	OutPut(lst);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}
// Hàm chính .
void main()
{
	MeNu();
}