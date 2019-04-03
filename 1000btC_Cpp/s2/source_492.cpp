
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
#include "time.h"
// Khai báo cấu trúc dữ liệu danh sách liên kết đơn .
struct sach
{
	int MaSoSach;
	char TenSach[40];
	char TacGia[30];
	short NamXuatBan;
};
typedef struct sach SACH;
struct node
{
	SACH Data;
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
// Tạo Node trong danh sách liên kết đơn .
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
// Nhập dữ liệu danh sách liên kết đơn .
void InPut(LIST &l)
{
	int n;
	quaylai:printf("\nNhap vao so luong sach co trong danh sach:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		SACH x;
		printf("\n>>>>>>>>>>>>>> Nhap Vao Thong Tin Cuon Sach Thu %d <<<<<<<<<<<<<<<<<<\n",i);
		printf("\n");
		printf("\nNhap vao Ma So Sach:");
		scanf("%d",&x.MaSoSach);
		fflush(stdin);
		printf("\nNhap vao Ten Sach:");
		gets(x.TenSach);
		printf("\nNhap vao Tac Gia:");
		gets(x.TacGia);
		printf("\nNhap vao Nam Xuat Ban:");
		scanf("%hd",&x.NamXuatBan);
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
// Xuất dữ liệu danh sách liên kết đơn .
void OutPut(LIST l)
{
	int dem=0;
	printf("\nSTT\tMa So Sach\tTen Sach\tTac Gia\t\t\tNam Xuat Ban");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem++;
		printf("\n%d\t%d\t%s\t%s\t%hd",dem,p->Data.MaSoSach,p->Data.TenSach,p->Data.TacGia,p->Data.NamXuatBan);
	}
}
// Đếm số sách xuất bản năm X .
void DemSoSachXuatBanNamX(LIST l)
{
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	short x;
	int dem=0;
	printf("\nNhap vao mot nam can kiem tra:");
	scanf("%hd",&x);
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.NamXuatBan==x)
		{
			dem++;
		}
	}
	printf("\nSo Luong Sach Xuat Ban Nam %hd La:%d",x,dem);
}
// Sắp danh sách liên kết đơn tăng dần .
void TangDan(LIST &l)
{
    NODE *p,*q;
    SACH temp;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data.MaSoSach>q->Data.MaSoSach)
			{
				temp=p->Data;
				p->Data=q->Data;
				q->Data=temp;
			}
		}
	}
}
// Sắp danh sách liên kết đơn giảm dần .
void GiamDan(LIST &l)
{
	NODE *p,*q;
	SACH temp;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data.MaSoSach<q->Data.MaSoSach)
			{
				temp=p->Data;
				p->Data=q->Data;
				q->Data=temp;
			}
		}
	}
}
// Sắp xếp danh sách theo mã số sách .
void SapXepDanhSach(LIST l)
{
	NODE*pNode;
	NODE*q;
	LIST Prs;
	INit(Prs);
	int w;
	printf("\n>>>>>>>>>>>>> Sap Xep Danh Sach Theo Ma So Sach <<<<<<<<<<<<<<<<<<\n");
	printf("\n------------ Bang Lua Chon ------------");
	printf("\n1.Sap Danh Sach Tang Dan Theo Ma So Sach");
	printf("\n2.Sap Danh Sach Giam Dan Theo Ma So Sach");
	printf("\n---------------------------------------");
	quaylai:printf("\nNhap vao lua chon o day:");
	scanf("%d",&w);
	if(w!=1&&w!=2)
	{
		printf("\nLua chon khong hop le!Xin nhap lai!");
		goto quaylai;
	}
	if(w==1)
	{
		TangDan(l);
		printf("\n>>>>>>>> Sap Tang Dan Theo Ma So Sach <<<<<<<<<<<<<\n");
		OutPut(l);
	}
	else if(w==2)
	{
		GiamDan(l);
		printf("\n>>>>>>>> Sap Giam Dan Theo Ma So Sach <<<<<<<<<<<<<\n");
		OutPut(l);
	}
}
// Hàm tăng kích cỡ của khung CMD
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
// Hàm hiển thị lời chào .
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
// Hàm MeNu .
void MeNu()
{
	resizeConsole(800,500); // Tăng kích cỡ của khung CMD lên thành chiều rộng 800,chiều cao 500 .
	int w;
	LIST lst;
	printf("\n");
	quaylai:InPut(lst);
	printf("\n>>>>>>>>>>>>>>>>>>>>>Xuat Ra Danh Sach Thong Tin Cac Cuon Sach:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	do{
		// Bảng MeNu đưa ra cho người dùng các sự lựa chọn .
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");		
		printf("\n 1.Dem So Sach Xuat Ban Nam X ");
		printf("\n");
		printf("\n 2.Sap Xep Danh Sach Theo Ma So Sach ");
		printf("\n");
		printf("\n 3.Cap Nhat Lai Thong Tin Cac Cuon Sach ");
		printf("\n");
		printf("\n 0.Thoat chuong trinh ");
		printf("\n");
		printf("\n--------------------------------------------------------------------------------\n");
		printf("\n");
		printf("\nChon:");
		scanf("%d",&w);
		printf("\nKet qua:\n");
		printf("\n");		
		// Cấu trúc switch-case .
		switch(w)
		{								
		case 1:
			{
				DemSoSachXuatBanNamX(lst);
				break; 
			}
		case 2: 
			{
				SapXepDanhSach(lst);
				break;
			}
		case 3:
			{
				system("cls");
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
// Hàm chính .
void main()
{
	MeNu();
}