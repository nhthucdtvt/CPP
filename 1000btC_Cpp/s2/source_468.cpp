
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
void InPut(LIST &l)
{
	int n;
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
		printf("\nPhan so thu %d La:%d/%d",dem,p->Data);
	}
}
void main()
{
	LIST lst;
	int tieptuc;
	quaylai:printf("\n>>>>>>>>>>>>>>>>>>>>>Nhap List:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	InPut(lst);
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
