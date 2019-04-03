
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
// Khai báo cấu trúc dữ liệu cho danh sách liên kết đơn các phân số .
struct phanso
{
	int tuso;
	int mauso;
	float ketqua;
};
typedef struct phanso PHANSO;
struct node
{
	PHANSO Data;
	node*pNext;
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
// Tạo Node trong danh sách liên kết đơn các phân số .
NODE*getnode(PHANSO x)
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
// Hàm nhập dữ liệu danh sách liên kết đơn các phân số .
void InPut(LIST &l)
{
	int n;
	quaylai:printf("\nNhap vao so luong cac phan so:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		PHANSO x;
		printf("\n>>>>>>>>>>>>>>>>Moi Ban Nhap Vao Phan So Thu %d:<<<<<<<<<<<<<<<<<<<<<<<\n",i);
		printf("\n");
		printf("\nNhap vao tu so cua phan so %d:",i);
		scanf("%d",&x.tuso);
		do{
			printf("\nNhap vao mau so cua phan so %d:",i);
			scanf("%d",&x.mauso);
			if(x.mauso==0)
			{
				printf("\nMau so khong hop le!Xin vui long nhap lai!");
			}
		}while(x.mauso==0);
		if(x.mauso<0)
		{
			x.tuso=x.tuso*-1;
			x.mauso=x.mauso*-1;
		}
		x.ketqua=(x.tuso*1.0)/x.mauso;
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
// Hàm xuất dữ liệu danh sách liên kết đơn các phân số .
void OutPut(LIST l)
{
	int dem=0;
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem++;
		printf("\nPhan So Thu %d La:%d/%d",dem,p->Data);
	}
}
// Hàm liệt kê và đếm số lượng các phân số dương .
void LietKeVaDemSoLuongCacPhanSoDuong(LIST l)
{
	int dem=0;
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.ketqua>=0)
		{
			dem++;
			printf("\nPhan So Duong Thu %d La:%d/%d",dem,pNode->Data);
		}
	}
	printf("\n");
	printf("\nCo %d Phan So Duong Trong Danh Sach",dem);
}
// Hàm liệt kê và đếm số lượng các phân số âm .
void LietKeVaDemSoLuongCacPhanSoAm(LIST l)
{
	int dem=0;
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.ketqua<0)
		{
			dem++;
			printf("\nPhan So Am Thu %d La:%d/%d",dem,pNode->Data);
		}
	}
	printf("\n");
	printf("\nCo %d Phan So Am Trong Danh Sach",dem);
}
// Hàm MeNu .
void MeNu()
{
	int tieptuc;
	LIST lst;
	quaylai:InPut(lst);
	printf("\n>>>>>>>>>>>>>>Xuat Ra Danh Sach Cac Phan So:<<<<<<<<<<<<<<<<\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>Cac Phan So Duong:<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	LietKeVaDemSoLuongCacPhanSoDuong(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>Cac Phan So Am:<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	LietKeVaDemSoLuongCacPhanSoAm(lst);
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