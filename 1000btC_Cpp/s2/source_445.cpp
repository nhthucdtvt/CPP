
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
#define  MAX 100
struct sach
{
	char TenSach[50];
	char TenTacGia[30];
	int NamXuatBan;
};
typedef struct sach SACH;
struct node
{
	SACH Data;
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
NODE*getnode(SACH x)
{
	NODE*p;
	p=new NODE;
	if(p==NULL)
		return NULL;
	p->Data=x;
	p->pNext=NULL;
	return p;
}
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
void InPut(LIST &l)
{
	int n;
	quaylai:printf("\nNhap vao so luong cac quyen sach:");
	scanf("%d",&n);
	if(n<0||n>MAX)
	{
		printf("\nSo luong ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		SACH x;
		printf("\n>>>>>>> Nhap Vao Du Lieu Quyen Sach Thu %d <<<<<<<<<\n",i);
		fflush(stdin);	
		printf("\nNhap vao Ten Sach:");
		gets(x.TenSach);
		printf("\nNhap vao Ten Tac Gia:");
		gets(x.TenTacGia);
		do{
			printf("\nNhap vao Nam Xuat Ban:");
			scanf("%d",&x.NamXuatBan);
			if(x.NamXuatBan<0)
			{
				printf("\nNam Xuat Ban khong hop le!Xin vui long nhap lai!");
			}
		}while(x.NamXuatBan<0);
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
void OutPut(LIST l)
{
	int dem=0;
	printf("So Thu Tu  \t");
	printf("Ten Quyen Sach\t\t");
	printf("Ten Tac Gia\t\t");
	printf("Nam Xuat Ban  \n\n");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem++;
		printf("%8d  ",dem);
		printf("%20s  ",p->Data.TenSach);
		printf("%30s  ",p->Data.TenTacGia);
		printf("%8d  \n\n",p->Data.NamXuatBan);
	}
}
void TimQuyenSachCuNhat(LIST l)
{
	NODE*pNode;
	int dem=0;
	int min=INT_MAX;
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.NamXuatBan<min)
		{
			min=pNode->Data.NamXuatBan;
		}
	}
	printf("\nQuyen Sach Co Nam Xuat Ban Cu Nhat La Nam:%d",min);
	printf("\n");
	printf("\n>>>>>>>>>>>>>> Thong Tin Ve Quyen Sach Xuat Ban Nam %d <<<<<<<<<<<<<\n",min);
	printf("\n");
	printf("So Thu Tu  \t");
	printf("Ten Quyen Sach\t\t");
	printf("Ten Tac Gia\t\t");
	printf("Nam Xuat Ban  \n\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.NamXuatBan==min)
		{
			dem++;
			printf("%8d  ",dem);
			printf("%20s  ",pNode->Data.TenSach);
			printf("%30s  ",pNode->Data.TenTacGia);
			printf("%8d  \n\n",pNode->Data.NamXuatBan);
		}
	}	
}
void SapTangDan(LIST &l)
{
	NODE *p,*q; // Khai báo 2 con trỏ p,q .
	SACH temp;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data.NamXuatBan>q->Data.NamXuatBan)
			{
				temp=p->Data;
				p->Data=q->Data;
				q->Data=temp;
			}
		}
	}
}
void TimRaNamCoNhieuSachXuatBanNhatVaLietKeCacSachXuatBanTrongNamDo(LIST l,int a[])
{
	int i=0,dem=0,d;
	NODE*pNode;
	SapTangDan(l); // sắp danh sách tăng dần .
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		dem++; // Tăng biến đếm lên .
		a[i++]=pNode->Data.NamXuatBan; // đưa dữ liệu năm xuất bản sách vào mảng 1 chiều a .
	}
	int max=0,dem1=0,nam=a[0];
	for(int i=0;i<dem;i++)
	{
		if(a[i]!=a[i-1])
		{
			dem1=0;
		}
		dem1++;
		if(dem1>max)
		{
			max=dem1;
			nam=a[i];
		}
	}
	int dem2=0; // Khởi tạo biến đếm .
	printf("\nNam Co So Sach Xuat Ban Nhieu Nhat La Nam:%d",nam);
	printf("\n");
	printf("\nSo Luong Sach Xuat Ban Trong Nam %d La:%d Quyen Sach",nam,max);
	printf("\n");
	printf("\n>>>>>>>>>>>>>> Thong Tin Ve Cac Quyen Sach Xuat Ban Nam %d <<<<<<<<<<<<<\n",nam);
	printf("\n");
	printf("So Thu Tu  \t");
	printf("Ten Quyen Sach\t\t");
	printf("Ten Tac Gia\t\t");
	printf("Nam Xuat Ban  \n\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.NamXuatBan==nam)
		{
			dem2++;
			printf("%8d  ",dem2);
			printf("%20s  ",pNode->Data.TenSach);
			printf("%30s  ",pNode->Data.TenTacGia);
			printf("%8d  \n\n",pNode->Data.NamXuatBan);
		}
	}
}
// Hàm tăng kích cỡ của khung CMD .
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm lấy tọa độ vị trí .
void gotoxy(int x,int y)
{
	HANDLE hstdout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x,y};
	SetConsoleCursorPosition(hstdout,position);
}
// Hàm tô màu .
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
// Hàm đồ họa cho tên tác giả .
void NguyenVietNamSon()
{
	textcolor(14); // Tô màu vàng .
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\t\t\tDesigned By : Nguyen Viet Nam Son              \n");
	printf("\n--------------------------------------------------------------------------------\n");
	textcolor(7); // Trả lại màu chữ bình thường .
}
void Thanks()
{
	system("cls"); // Xóa đi mọi dữ liệu đã làm trước đó .
	srand(time(NULL));
	for(int j=1;j<=20;j++)
	{
		int color=rand()%15+1; // Khởi tạo màu chạy ngẫu nhiên trong đoạn thang màu [1,15].
		Sleep(300);
		gotoxy(j-1,40);
		printf("			");
		gotoxy(j,40);
		textcolor(color);
		printf("\nThanks You For Using The Program ! Goodbye And See You Later !\n"); // Khi người dùng thoát chương trình sẽ hiển thị lời chào !
	}
	textcolor(15);
	getch();
	gotoxy(3,42);
}
void MeNu()
{
	LIST lst;
	resizeConsole(800,600); // Tăng kích cỡ của khung CMD lên thành chiều rộng 800,chiều cao 600 .
	int w;
	int a[MAX];
	printf("\n");
	quaylai:NguyenVietNamSon();
	InPut(lst);
	printf("\n>>>>>>>>>>>>>>>>>>>>> Xuat Ra Danh Sach Cac Quyen Sach <<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	do{
		// Bảng MeNu đưa ra cho người dùng các sự lựa chọn .
		textcolor(2); // Tô màu xanh nhạt cho MeNu
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");		
		printf("\n 1.Tim Quyen Sach Cu Nhat ");
		printf("\n");
		printf("\n 2.Tim 1 Nam Co Nhieu Sach Xuat Ban Nhat Va In Ra Cac Quyen Sach Xuat Ban Nam Do ");
		printf("\n 3.Cap Nhat Lai Danh Sach Cac Quyen Sach ");
		printf("\n");
		printf("\n 0.Thoat chuong trinh ");
		printf("\n");
		printf("\n--------------------------------------------------------------------------------\n");
		printf("\n");
		textcolor(7); // Trả về lại màu bình thường .
		printf("\nChon:");
		scanf("%d",&w);
		printf("\nKet qua:\n");
		printf("\n");		
		// Cấu trúc switch-case .
		switch(w)
		{								
		case 1:
			{
				TimQuyenSachCuNhat(lst);
				break; 
			}
		case 2: 
			{
				TimRaNamCoNhieuSachXuatBanNhatVaLietKeCacSachXuatBanTrongNamDo(lst,a);
				break;
			}
		case 3:
			{
				goto quaylai;
				break;
			}
		case 0: 
			{
				Thanks();
			}
		}
	}while(w!=0);
}
void main()
{
	MeNu();
}
