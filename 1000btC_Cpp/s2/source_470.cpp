
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
struct phanso
{
	int tuso;
	int mauso;
};
typedef struct phanso PHANSO;
struct node
{
	PHANSO Data;
	struct node*pNext;
};
typedef struct node NODE;
struct list
{
	NODE*pHead;
	NODE*pTail;
};
typedef struct list LIST;
void INit(LIST &l)
{
	l.pHead=NULL;
	l.pTail=NULL;
}
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
void RutGonPhanSo(LIST &l)
{
	int n,dem=0;
	quaylai:printf("\nNhap so luong cac phan so:");
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
		printf("\n>>>>>>>>>>>>>>>>>>Moi ban nhap vao phan so thu:%d<<<<<<<<<<<<<<<<<",i);
		printf("\n");
		printf("\nNhap vao tu so cua phan so thu %d:",i);
		scanf("%d",&x.tuso);
		do{
			printf("\nNhap vao mau so cua phan so thu %d:",i);
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
		// Trường hợp rút gọn cả tử và mẫu đều là số dương .
		if(x.tuso>=0&&x.mauso>0)
		{
			int min;
			min=x.tuso;
			if(min>x.mauso)
			{
				min=x.mauso;
			}
			for(int i=min;i>=1;i--)
			{
				if(x.tuso%i==0&&x.mauso%i==0)
				{
					x.tuso=x.tuso/i;
					x.mauso=x.mauso/i;
				}
			}
		}
		// Trường hợp rút gọn tử số là số âm,mẫu số là số dương .
		if(x.tuso<0&&x.mauso>0)
		{
			x.tuso=x.tuso*-1;
			int min;
			min=x.tuso;
			if(min>x.mauso)
			{
				min=x.mauso;
			}
			x.tuso=x.tuso*-1;
			for(int i=min;i>=1;i--)
			{
				if(x.tuso%i==0&&x.mauso%i==0)
				{
					x.tuso=x.tuso/i;
					x.mauso=x.mauso/i;
				}
			}
		}
		// Trường hợp cả tử và mẫu đều là số âm & trường hợp tử là số dương,mẫu là số âm thì không cần làm do khi nhập phân số ta đã đặt điều kiện để xuất ra là nếu mẫu số < 0 thì đồng thời nhân -1 cho cả tử & mẫu .
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
void OutPut(LIST l)
{
	int dem=0;
	printf("\n>>>>>>>>>>>>>>>>>>Xuat Ra Cac Phan So:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem++;
		printf("\nPhan so thu %d Rut Gon La:%d/%d",dem,p->Data);
	}
}
void main()
{
	LIST lst;
	int tieptuc;
	quaylai:printf("\n>>>>>>>>>>>>>>>>>>>>>Nhap List:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	RutGonPhanSo(lst);
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Xuat List:<<<<<<<<<<<<<<<<<<<<<<<<\n");
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
