
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
struct sinhvien
{
	int MSSV;
	char HoTen[80];
	char Email[80];
	float TrungBinh;
};
typedef struct sinhvien SINHVIEN;
struct node
{
	SINHVIEN Data;
	node*pNext;
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
NODE*getnode(SINHVIEN x)
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
	quaylai:printf("\nNhap Vao So Luong Sinh Vien Can Khoi Tao:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong sinh vien khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		SINHVIEN x;
		printf("\n>>>>>>>>>>>Nhap Vao Thong Tin Cua Sinh Vien %d<<<<<<<<<<<<<<<\n",i);
		printf("\nNhap vao Ma So Sinh Vien cua Sinh Vien Thu %d:",i);
		scanf("%d",&x.MSSV);
		fflush(stdin);
		printf("\nNhap vao Ho Ten Sinh Vien cua Sinh Vien Thu %d:",i);
		gets(x.HoTen);
		fflush(stdin);
		printf("\nNhap vao Email cua Sinh Vien Thu %d:",i);
		gets(x.Email);
		fflush(stdin);
		do{
			printf("\nNhap Vao Diem Trung Binh Cua Sinh Vien Thu %d:",i);
			scanf("%f",&x.TrungBinh);
			fflush(stdin);
			if(x.TrungBinh<0||x.TrungBinh>10)
			{
				printf("\nDiem Trung Binh khong hop le!Xin vui long nhap lai!");
			}
		}while(x.TrungBinh<0||x.TrungBinh>10);
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
void OutPut(LIST l)
{
	printf("\n");
	printf("Ma So Sinh Vien  \t");
	printf("Ho Va Ten\t\t");
	printf("Dia Chi EMail\t\t");
	printf("Diem TB  \n\n");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%8d  ",p->Data.MSSV);
		printf("%25s  ",p->Data.HoTen);
		printf("%30s  ",p->Data.Email);
		printf("%8.2f  \n\n",p->Data.TrungBinh);
	}
}
void TimKiemSinhVien(LIST l)
{
	SINHVIEN x;
	bool Co=false;
	NODE*pNode;
	printf("\nNhap vao MSSV can tim kiem:");
	scanf("%d",&x.MSSV);
	printf("Ma So Sinh Vien  \t");
	printf("Ho Va Ten\t\t");
	printf("Dia Chi EMail\t\t");
	printf("Diem TB  \n\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.MSSV==x.MSSV)
		{
			Co=true;
			printf("%8d  ",pNode->Data.MSSV);
			printf("%25s  ",pNode->Data.HoTen);
			printf("%30s  ",pNode->Data.Email);
			printf("%8.2f  \n\n",pNode->Data.TrungBinh);
		}
	}
	if(Co==false)
	{
		printf("\nKhong Tim Thay Sinh Vien Co MSSV Da Nhap!");
	}
}
void HamXuLyXoaSinhVienTheoMSSV(LIST &l)
{
	SINHVIEN x;
	bool Co=false;
	NODE*p=l.pHead;
	NODE*q=NULL;
    printf("\nNhap Ma So Sinh Vien Can Xoa: ");
	scanf("%d",&x.MSSV);
	for(p;p!=NULL;p=p->pNext)
    {
		if(p->Data.MSSV==x.MSSV)    
		{
				Co=true;
				break;
		}
       q=p;
    }
	if(Co==true)
	{
		printf("\nDa tim thay Ma So Sinh Vien Can Xoa !");
		printf("\n");
		printf("\nXoa Thanh Cong!");
		printf("\n");
		if(q!=NULL)
		{
			if(p==l.pTail)
			{
				l.pTail=q;
			}
			q->pNext=p->pNext;
			delete(p);
		}
		else
		{
			l.pHead=p->pNext;
			if(l.pHead==NULL)  
			{
				l.pTail=NULL;
			}
		}
	}
	else
	{
		printf("\nKhong tim thay Ma So Sinh Vien Can Xoa!");
		printf("\n");
	}
}
void XoaSinhVienTheoMSSV(LIST l)
{
	HamXuLyXoaSinhVienTheoMSSV(l);
	printf("\n>>>>>>>>>>>>>> Danh Sach Cac Sinh Vien Sau Khi Xoa <<<<<<<<<<<<<<<<\n");
	OutPut(l);
}
void HamXuLyXoaSinhVienTheoHoTen(LIST &l)
{
	SINHVIEN x;
	bool Co=false;
	NODE*p=l.pHead;
	NODE*q=NULL;
    fflush(stdin);
	printf("\nNhap Ho Ten Sinh Vien Can Xoa: ");
	gets(x.HoTen);
	for(p;p!=NULL;p=p->pNext)
    {
		if(strcmp(p->Data.HoTen,x.HoTen)==0)    
		{
				Co=true;
				break;
		}
       q=p;
    }
	if(Co==true)
	{
		printf("\nDa Tim Thay Ho Ten Sinh Vien Can Xoa !");
		printf("\n");
		printf("\nXoa Thanh Cong!");
		printf("\n");
		if(q!=NULL)
		{
			if(p==l.pTail)
			{
				l.pTail=q;
			}
			q->pNext=p->pNext;
			delete(p);
		}
		else
		{
			l.pHead=p->pNext;
			if(l.pHead==NULL)  
			{
				l.pTail=NULL;
			}
		}
	}
	else
	{
		printf("\nKhong Tim Thay Ho Ten Sinh Vien Can Xoa!");
		printf("\n");
	}
}
void XoaSinhVienTheoHoTen(LIST l)
{
	HamXuLyXoaSinhVienTheoHoTen(l);
	printf("\n>>>>>>>>>>>>>>>>>> Danh Sach Cac Sinh Vien Sau Khi Xoa <<<<<<<<<<<<<<<<<\n");
	OutPut(l);
}
void HamXuLyXoaSinhVienTheoEMail(LIST &l)
{
	SINHVIEN x;
	bool Co=false;
	NODE*p=l.pHead;
	NODE*q=NULL;
    fflush(stdin);
	printf("\nNhap Vao EMail Cua Sinh Vien Can Xoa: ");
	gets(x.Email);
	for(p;p!=NULL;p=p->pNext)
    {
		if(strcmp(p->Data.Email,x.Email)==0)    
		{
				Co=true;
				break;
		}
       q=p;
    }
	if(Co==true)
	{
		printf("\nDa Tim Thay EMail Cua Sinh Vien Can Xoa !");
		printf("\n");
		printf("\nXoa Thanh Cong!");
		printf("\n");
		if(q!=NULL)
		{
			if(p==l.pTail)
			{
				l.pTail=q;
			}
			q->pNext=p->pNext;
			delete(p);
		}
		else
		{
			l.pHead=p->pNext;
			if(l.pHead==NULL)  
			{
				l.pTail=NULL;
			}
		}
	}
	else
	{
		printf("\nKhong tim thay EMail Cua Sinh Vien Can Xoa!");
		printf("\n");
	}
}
void XoaSinhVienTheoEMail(LIST l)
{
	HamXuLyXoaSinhVienTheoEMail(l);
	printf("\n>>>>>>>>>>>>>>>> Danh Sach Cac Sinh Vien Sau Khi Xoa <<<<<<<<<<<<<<<<<<\n");
	OutPut(l);
}
void HamXuLyXoaSinhVienTheoDiemTrungBinh(LIST &l)
{
	SINHVIEN x;
	bool Co=false;
	NODE*p=l.pHead;
	NODE*q=NULL;
    fflush(stdin);
	printf("\nNhap Diem Trung Binh Cua Sinh Vien Can Xoa: ");
	scanf("%f",&x.TrungBinh);
	for(p;p!=NULL;p=p->pNext)
    {
		if(p->Data.TrungBinh==x.TrungBinh)    
		{
				Co=true;
				break;
		}
       q=p;
    }
	if(Co==true)
	{
		printf("\nDa Tim Thay Sinh Vien Co Diem Trung Binh Can Xoa !");
		printf("\n");
		printf("\nXoa Thanh Cong!");
		printf("\n");
		if(q!=NULL)
		{
			if(p==l.pTail)
			{
				l.pTail=q;
			}
			q->pNext=p->pNext;
			delete(p);
		}
		else
		{
			l.pHead=p->pNext;
			if(l.pHead==NULL)  
			{
				l.pTail=NULL;
			}
		}
	}
	else
	{
		printf("\nKhong Tim Thay Sinh Vien Co Diem Trung Binh Can Xoa !");
		printf("\n");
	}
}
void XoaSinhVienTheoDiemTrungBinh(LIST l)
{
	HamXuLyXoaSinhVienTheoDiemTrungBinh(l);
	printf("\n>>>>>>>>>>>>>>> Danh Sach Cac Sinh Vien Sau Khi Xoa <<<<<<<<<<<<<<<<<<<<<<\n");
	OutPut(l);
}
void HamXuLyXoaSinhVienTheoTatCaCacThongTinVeSinhVienDo(LIST &l)
{
	SINHVIEN x;
	bool Co=false;
	NODE*p=l.pHead;
	NODE*q=NULL;
	printf("\nNhap vao MSSV Sinh Vien Can Xoa:");
	scanf("%d",&x.MSSV);
	fflush(stdin);
	printf("\nNhap vao Ho Ten Sinh Vien Can Xoa:");
	gets(x.HoTen);
	printf("\nNhap vao EMail Sinh Vien Can Xoa:");
	gets(x.Email);
	printf("\nNhap Diem Trung Binh Cua Sinh Vien Can Xoa: ");
	scanf("%f",&x.TrungBinh);
	for(p;p!=NULL;p=p->pNext)
    {
		if(p->Data.MSSV==x.MSSV&&(strcmp(p->Data.HoTen,x.HoTen)==0)&&(strcmp(p->Data.Email,x.Email)==0)&&p->Data.TrungBinh==x.TrungBinh)    
		{
				Co=true;
				break;
		}
       q=p;
    }
	if(Co==true)
	{
		printf("\nDa Tim Thay Sinh Vien Co Cac Thong Tin Can Xoa !");
		printf("\n");
		printf("\nXoa Thanh Cong!");
		printf("\n");
		if(q!=NULL)
		{
			if(p==l.pTail)
			{
				l.pTail=q;
			}
			q->pNext=p->pNext;
			delete(p);
		}
		else
		{
			l.pHead=p->pNext;
			if(l.pHead==NULL)  
			{
				l.pTail=NULL;
			}
		}
	}
	else
	{
		printf("\nKhong Tim Thay Sinh Vien Co Cac Thong Tin Can Xoa !");
		printf("\n");
	}
}
void XoaSinhVienTheoTatCaCacThongTinVeSinhVienDo(LIST l)
{
	HamXuLyXoaSinhVienTheoTatCaCacThongTinVeSinhVienDo(l);
	printf("\n>>>>>>>>>>>>>>>>> Danh Sach Cac Sinh Vien Sau Khi Xoa <<<<<<<<<<<<<<<<<<\n");
	OutPut(l);
}
void XoaSinhVien(LIST l)
{
	int luachon;
	printf("\nMoi Ban Lua Chon Tieu Chi Xoa Sinh Vien :");
	printf("\n");
	printf("\n------------------- Bang Lua Chon ---------------------\n");
	printf("\n 1.Xoa Sinh Vien Theo MSSV ");
	printf("\n 2.Xoa Sinh Vien Theo Ho Ten ");
	printf("\n 3.Xoa Sinh Vien Theo EMail ");
	printf("\n 4.Xoa Sinh Vien Theo Diem Trung Binh ");
	printf("\n 5.Xoa Sinh Vien Theo Tat Ca Thong Tin Ve Sinh Vien Do ");
	printf("\n-------------------------------------------------------\n");
	quaylai:printf("\nNhap vao lua chon cua ban:");
	scanf("%d",&luachon);
	if(luachon==1)
	{
		XoaSinhVienTheoMSSV(l);
	}
	else if(luachon==2)
	{
		XoaSinhVienTheoHoTen(l);
	}
	else if(luachon==3)
	{
		XoaSinhVienTheoEMail(l);
	}
	else if(luachon==4)
	{
		XoaSinhVienTheoDiemTrungBinh(l);
	}
	else if(luachon==5)
	{
		XoaSinhVienTheoTatCaCacThongTinVeSinhVienDo(l);
	}
	if(luachon!=1&&luachon!=2&&luachon!=3&&luachon!=4&&luachon!=5)
	{
		printf("\nLua chon ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai;
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
	resizeConsole(800,600); // Tăng kích cỡ của khung CMD lên thành chiều rộng 800,chiều cao 600 .
	int w;
	LIST lst;
	printf("\n");
	quaylai:NguyenVietNamSon();
	InPut(lst);
	printf("\n>>>>>>>>>>>>>>>>>>>>> Xuat Ra Danh Sach Cac Sinh Vien <<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	do{
		// Bảng MeNu đưa ra cho người dùng các sự lựa chọn .
		textcolor(2); // Tô màu xanh nhạt cho MeNu
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");		
		printf("\n 3.Tim Kiem Sinh Vien ");
		printf("\n");
		printf("\n 4.Xoa Sinh Vien ");
		printf("\n");
		printf("\n 5.Cap Nhat Lai Danh Sach Sinh Vien ");
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
		case 3:
			{
				TimKiemSinhVien(lst);
				break; 
			}
		case 4: 
			{
				XoaSinhVien(lst);
				break;
			}
		case 5:
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
