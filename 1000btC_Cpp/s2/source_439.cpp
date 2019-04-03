
// Các thư viện sử dụng trong chương trình .
#include<stdio.h>
#include<conio.h>
#include<float.h>
#include<Windows.h>
#define bool
// Khai báo cấu trúc dữ liệu danh sách liên kết đơn các phân số .
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
// Khởi tạo danh sách liên kết đơn các phân số .
void INit(LIST &l)
{
	l.pHead=NULL;
	l.pTail=NULL;
}
// Tạo các Node trong danh sách liên kết đơn các phân số .
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
// Thêm vào cuối danh sách liên kết đơn các phân số .
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
// Nhập dữ liệu danh sách liên kết đơn các phân số .
void InPut(LIST &l)
{
	int n;
	quaylai:printf("\nNhap vao so luong cac phan so:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		PHANSO x;
		printf("\n>>>>>>>>>>>>>>>>>Nhap Vao Phan So Thu %d:<<<<<<<<<<<<<<<<<<<<<\n",i);
		printf("\n");
		printf("\nNhap vao tu so cua phan so thu %d:",i);
		scanf("%d",&x.tuso);
		do{
			printf("\nNhap vao mau so cua phan so thu %d:",i);
			scanf("%d",&x.mauso);
			if(x.mauso==0)
			{
				printf("\nMau so nhap vao khong hop le!Xin vui long nhap lai!");
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
// Xuất dữ liệu danh sách liên kết đơn các phân số .
void OutPut(LIST l)
{
	int dem=0;
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem++;
		printf("\nPhan So Thu %d La:%d/%d",dem,p->Data);
	}
}
// Tìm phân số Max,Min trong danh sách liên kết đơn các phân số .
void MaxMin(LIST l)
{
	int Co,Co1;
	bool Co=false;
	bool Co1=false;
	float max=FLT_MIN;
	float min=FLT_MAX;
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	// Vòng lặp đầu tiên là tìm ra giá trị min,max của danh sách các phân số ở dạng số thực . Sau đó tạo thêm 2 vòng lặp nữa đem giá trị min,max vừa tìm đc đem so sánh lại với danh sách => để chủ yếu in ra phân số có kết quả giống như vậy . Lưu ý : Ta chỉ in ra đúng 1 phân số có kết quả như vậy,nếu có nhiều hơn 1 thì ta sẽ in ra phân số đầu tiên trong danh sách mà có kết quả thỏa mãn .
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.ketqua>max)
		{
			max=pNode->Data.ketqua;
		}
		if(pNode->Data.ketqua<min)
		{
			min=pNode->Data.ketqua;
		}
	}
	printf("\n");
	printf("\nGia tri cua phan so lon nhat la:%f",max);
	printf("\n");
	printf("\nGia tri cua phan so nho nhat la:%f",min);
	printf("\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(max==pNode->Data.ketqua)
		{
			break ; // cốt để chỉ in ra 1 phần tử thôi cho nên khi phần tử đầu tiên thỏa điều kiện thì sẽ lập tức thoát ra khỏi vòng lặp .
		}
	}
	printf("\nPhan So Lon Nhat La:%d/%d",pNode->Data);
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(min==pNode->Data.ketqua)
		{
			break ; // cốt để chỉ in ra 1 phần tử thôi cho nên khi phần tử đầu tiên thỏa điều kiện thì sẽ lập tức thoát ra khỏi vòng lặp .
		}
	}
	printf("\nPhan So Nho Nhat La:%d/%d",pNode->Data);
}
// Hàm MeNu .
void MeNu()
{
	int tieptuc;
	LIST lst;
	quaylai:InPut(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>>Cac Phan So Co Trong Danh Sach La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>Tim Max Min Cua Cac Phan So Co Trong Danh Sach:<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	MaxMin(lst);
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh nua hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
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