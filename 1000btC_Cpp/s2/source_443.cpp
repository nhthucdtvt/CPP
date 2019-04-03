
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
struct phong
{
	char MaPhong[5];
	char TenPhong[30];
	float DonGiaThue;
	int SoLuongGiuong;
	int TinhTrangPhong;
};
typedef struct phong PHONG;
struct node
{
	PHONG Data;
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
NODE*getnode(PHONG x)
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
	quaylai:printf("\nNhap vao so luong phong:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong phong khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		PHONG x;
		printf("\n>>>>>>>> Nhap Vao Thong Tin Phong Thu %d <<<<<<<<<<<\n",i);
		fflush(stdin);
		printf("\nNhap vao Ma Phong:");
		gets(x.MaPhong);
		printf("\nNhap vao Ten Phong:");
		gets(x.TenPhong);
		do{
			printf("\nNhap vao Don Gia Thue:");
			scanf("%f",&x.DonGiaThue);
			if(x.DonGiaThue<=0)
			{
				printf("\nDon gia thue khong hop le!Xin vui long nhap lai!");
			}
		}while(x.DonGiaThue<=0);
		do{	
			printf("\nNhap vao So Luong Giuong:");
			scanf("%d",&x.SoLuongGiuong);
			if(x.SoLuongGiuong<1)
			{
				printf("\nSo Luong Giuong khong hop le!Xin vui long nhap lai!");
			}
		}while(x.SoLuongGiuong<1);
		do{
			printf("\nNhap vao Tinh Trang Phong (0:Ranh,1:Ban):");
			scanf("%d",&x.TinhTrangPhong);
			if(x.TinhTrangPhong!=0&&x.TinhTrangPhong!=1)
			{
				printf("\nTinh Trang Phong khong hop le!Xin vui long nhap lai!");
			}
		}while(x.TinhTrangPhong!=0&&x.TinhTrangPhong!=1);
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
void OutPut(LIST l)
{
	printf("Ma Phong  \t");
	printf("Ten Phong\t");
	printf("Don Gia\t\t");
	printf("So Luong Giuong \t");
	printf("T Trang \n\n");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%5s  ",p->Data.MaPhong);
		printf("%20s  ",p->Data.TenPhong);
		printf("%10f  ",p->Data.DonGiaThue);
		printf("%20d  ",p->Data.SoLuongGiuong);
		printf("%10d \n\n",p->Data.TinhTrangPhong);
	}
}
void LietKeCacPhongTrong(LIST l)
{
	NODE*pNode;
	printf("\n>>>>>>>>>> Cac Phong Trong Trong Danh Sach <<<<<<<<<<<<\n");
	printf("\n");
	printf("Ma Phong  \t");
	printf("Ten Phong\t");
	printf("Don Gia\t\t");
	printf("So Luong Giuong \t");
	printf("T Trang \n\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.TinhTrangPhong==0)
		{
			printf("%5s  ",pNode->Data.MaPhong);
			printf("%20s  ",pNode->Data.TenPhong);
			printf("%10f  ",pNode->Data.DonGiaThue);
			printf("%20d  ",pNode->Data.SoLuongGiuong);
			printf("%10d \n\n",pNode->Data.TinhTrangPhong);
		}
	}
}	
void TongSoLuongGiuong(LIST l)
{
	NODE*pNode;
	int tong=0;
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		tong+=pNode->Data.SoLuongGiuong;
	}
	printf("\nTong So Luong Giuong Co Trong Danh Sach La:%d",tong);
}
void SapTangDanTheoDonGiaThue(LIST &l)
{
	NODE *p,*q;
	PHONG temp;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data.DonGiaThue>q->Data.DonGiaThue)
			{
				temp=p->Data;
				p->Data=q->Data;
				q->Data=temp;
			}
		}
	}
}
void SapXepDanhSachPhongTangDanTheoDonGiaThue(LIST l)
{
	SapTangDanTheoDonGiaThue(l);
	printf("\n>>>>>>>>>>>> sap Xep Danh Sach Tang Dan Theo Don Gia Thue <<<<<<<<<<<<<<\n");
	OutPut(l);
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
	resizeConsole(800,600); // Tăng kích cỡ của khung CMD lên thành chiều rộng 800,chiều cao 600 .
	LIST lst;
	int w;
	printf("\n");
	quaylai:NguyenVietNamSon();
	InPut(lst);
	printf("\n>>>>>>>>>>>>>>>>>>>>> Xuat Ra Danh Sach Cac Phong <<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	do{
		// Bảng MeNu đưa ra cho người dùng các sự lựa chọn .
		textcolor(2); // Tô màu xanh nhạt cho MeNu
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");		
		printf("\n 1.Liet Ke Cac Phong Trong ");
		printf("\n");
		printf("\n 2.Tinh Tong So Luong Giuong ");
		printf("\n");
		printf("\n 3.Sap Danh Sach Cac Phong Tang Dan Theo Don Gia Thue ");
		printf("\n");
		printf("\n 4.Cap Nhat Lai Danh Sach Cac Phong ");
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
				LietKeCacPhongTrong(lst);
				break; 
			}
		case 2: 
			{
				TongSoLuongGiuong(lst);
				break;
			}
		case 3:
			{
				SapXepDanhSachPhongTangDanTheoDonGiaThue(lst);
				break;
			}
		case 4:
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
