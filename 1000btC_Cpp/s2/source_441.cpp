
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
#define NamHienTai 2013
struct nhanvien
{
	char HoTen[30];
	int NamSinh;
	float Luong;
	int GioiTinh;
};
typedef struct nhanvien NHANVIEN;
struct node
{
	NHANVIEN Data;
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
NODE*getnode(NHANVIEN x)
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
	quaylai:printf("\nNhap so luong nhan vien:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong nhan vien khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		NHANVIEN x;
		printf("\n>>>>>> Nhap Vao Du Lieu Nhan Vien Thu %d <<<<<<<\n",i);
		fflush(stdin);
		printf("\nNhap vao Ho Ten:");
		gets(x.HoTen);
		do{	
			printf("\nNhap vao Nam Sinh:");
			scanf("%d",&x.NamSinh);
			if(x.NamSinh<0)
			{
				printf("\nNam Sinh khong hop le!Xin vui long nhap lai!");
			}
		}while(x.NamSinh<0);
		do{
			printf("\nNhap vao Luong:");
			scanf("%f",&x.Luong);
			if(x.Luong<0)
			{
				printf("\nLuong khong hop le!Xin vui long nhap lai!");
			}
		}while(x.Luong<0);
		do{
			printf("\nNhap vao Gioi Tinh (0.Nu , 1.Nam):");
			scanf("%d",&x.GioiTinh);
			if(x.GioiTinh!=0&&x.GioiTinh!=1)
			{
				printf("\nGioi Tinh Khong hop le!Xin nhap lai!");
			}
		}while(x.GioiTinh!=0&&x.GioiTinh!=1);
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
void OutPut(LIST l)
{
	printf("Ho Va Ten  \t\t");
	printf("Nam Sinh\t\t");
	printf("Luong\t\t");
	printf("Gioi Tinh  \n\n");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%20s  ",p->Data.HoTen);
		printf("%8d  ",p->Data.NamSinh);
		printf("%30f  ",p->Data.Luong);
		printf("%8d  \n\n",p->Data.GioiTinh);
	}
}
void LietKeCacNhanVienTren40Tuoi(LIST l)
{
	NODE*pNode;
	printf("\n>>>>>>>>>>>>>>> Cac Nhan Vien Tren 40 Tuoi <<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("Ho Va Ten  \t\t");
	printf("Nam Sinh\t\t");
	printf("Luong\t\t");
	printf("Gioi Tinh  \n\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(NamHienTai-pNode->Data.NamSinh>40)
		{
			printf("%20s  ",pNode->Data.HoTen);
			printf("%8d  ",pNode->Data.NamSinh);
			printf("%30f  ",pNode->Data.Luong);
			printf("%8d  \n\n",pNode->Data.GioiTinh);
		}
	}
}
void DemSoLuongNhanVienCoLuongLonHon1Trieu(LIST l)
{
	NODE*pNode;
	int dem=0;
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.Luong>1000000)
		{
			dem++;
		}
	}
	printf("\nSo Luong Nhan Vien Co Luong Lon Hon 1 000 000 La:%d",dem);
}
void HamSapGiamDanTheoNamSinh(LIST &l)
{
	NODE *p,*q;
	NHANVIEN temp;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data.NamSinh<q->Data.NamSinh)
			{
				temp=p->Data;
				p->Data=q->Data;
				q->Data=temp;
			}
		}	
	}
}
void SapXePDanhSachCacNhanVienGiamDanTheoNamSinh(LIST l)
{
	HamSapGiamDanTheoNamSinh(l);
	printf("\n>>>>>>>>>>>> Danh Sach Cac Nhan Vien Giam Dan Theo Nam Sinh <<<<<<<<<<<<<\n");
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
	printf("\n>>>>>>>>>>>>>>>>>>>>> Xuat Ra Danh Sach Cac Nhan Vien <<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	do{
		// Bảng MeNu đưa ra cho người dùng các sự lựa chọn .
		textcolor(2); // Tô màu xanh nhạt cho MeNu
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");		
		printf("\n 1.Liet Ke Cac Nhan Vien Tren 40 Tuoi ");
		printf("\n");
		printf("\n 2.Dem So Luong Nhan Vien Co Luong > 1 Trieu ");
		printf("\n");
		printf("\n 3.Sap Xep Cac Nhan Vien Giam Dan Theo Nam Sinh ");
		printf("\n");
		printf("\n 4.Cap Nhat Lai Danh Sach Cac Nhan Vien ");
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
				LietKeCacNhanVienTren40Tuoi(lst);
				break; 
			}
		case 2: 
			{
				DemSoLuongNhanVienCoLuongLonHon1Trieu(lst);
				break;
			}
		case 3:
			{
				SapXePDanhSachCacNhanVienGiamDanTheoNamSinh(lst);
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
