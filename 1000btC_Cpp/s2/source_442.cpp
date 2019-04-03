
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
struct hocsinh
{
	char HoTen[30];
	float Toan;
	float Van;
	float TrungBinh;
};
typedef struct hocsinh HOCSINH;
struct node
{
	HOCSINH Data;
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
NODE*getnode(HOCSINH x)
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
	quaylai:printf("\nNhap vao so luong hoc sinh:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo luong hoc sinh khong hop le!Xin vui long nhap lai!");
		goto quaylai;
	}
	INit(l);
	for(int i=1;i<=n;i++)
	{
		HOCSINH x;
		printf("\n>>>>>>>>> Nhap Vao Du Lieu Hoc Sinh Thu %d <<<<<<<<<<<<\n",i);
		fflush(stdin);
		printf("\nNhap vao Ho Ten:");
		gets(x.HoTen);
		do{
			printf("\nNhap vao diem Toan:");
			scanf("%f",&x.Toan);
			if(x.Toan<0||x.Toan>10)
			{
				printf("\nDiem mon Toan khong hop le!Xin vui long nhap lai!");
			}
		}while(x.Toan<0||x.Toan>10);
		do{
			printf("\nNhap vao diem Van:");
			scanf("%f",&x.Van);
			if(x.Van<0||x.Van>10)
			{
				printf("\nDiem mon Van khong hop le!Xin vui long nhap lai!");
			}
		}while(x.Van<0||x.Van>10);
		x.TrungBinh=(x.Toan+x.Van)/2;
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
void OutPut(LIST l)
{
	printf("\tHo Va Ten  \t");
	printf("Diem Toan\t\t");
	printf("Diem Van\t\t");
	printf("Diem TB  \n\n");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%20s  ",p->Data.HoTen);
		printf("%10.2f  ",p->Data.Toan);
		printf("%20.2f  ",p->Data.Van);
		printf("%22.2f  \n\n",p->Data.TrungBinh);
	}
}
void LietKeCacHocSinhCoDiemToanNhoHon5(LIST l)
{
	NODE*pNode;
	printf("\n>>>>>>>>> Danh Sach Cac Hoc Sinh Co Diem Toan < 5 <<<<<<<<<\n");
	printf("\n");
	printf("\tHo Va Ten  \t");
	printf("Diem Toan\t\t");
	printf("Diem Van\t\t");
	printf("Diem TB  \n\n");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.Toan<5)
		{
			printf("%20s  ",pNode->Data.HoTen);
			printf("%10.2f  ",pNode->Data.Toan);
			printf("%20.2f  ",pNode->Data.Van);
			printf("%22.2f  \n\n",pNode->Data.TrungBinh);
		}	
	}
}
void DemSoLuongHocSinhCoDiemToanVaDiemVanLonHon8(LIST l)
{
	NODE*pNode;
	int dem=0;
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.Toan>8&&pNode->Data.Van>8)
		{
			dem++;
		}	
	}
	printf("\nSo Luong Cac Hoc Sinh Co Diem Toan & Van > 8 La:%d",dem);
}
void HamSapXepGiamDanTheoDiemTrungBinh(LIST &l)
{
	NODE *p,*q;
	HOCSINH temp;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data.TrungBinh<q->Data.TrungBinh)
			{
				temp=p->Data;
				p->Data=q->Data;
				q->Data=temp;
			}
		}
	}
}
void SapXepDanhSachCacHocSinhGiamDanTheoDiemTrungBinh(LIST l)
{
	HamSapXepGiamDanTheoDiemTrungBinh(l);
	printf("\n>>>>>>>>>>> Danh Sach Cac Hoc Sinh Sap Giam Dan Theo Diem Trung Binh <<<<<<<<<<\n");
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
	printf("\n>>>>>>>>>>>>>>>>>>>>> Xuat Ra Danh Sach Cac Hoc Sinh <<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	do{
		// Bảng MeNu đưa ra cho người dùng các sự lựa chọn .
		textcolor(2); // Tô màu xanh nhạt cho MeNu
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");		
		printf("\n 1.Liet Ke Cac Hoc Sinh Co Diem Toan < 5 ");
		printf("\n");
		printf("\n 2.Dem So Luong Hoc Sinh Co Diem Toan & Diem Van > 8 ");
		printf("\n");
		printf("\n 3.Sap Xep Lai Danh Sach Hoc Sinh Giam Dan Theo Diem Trung Binh ");
		printf("\n");
		printf("\n 4.Cap Nhat Lai Danh Sach Cac Hoc Sinh ");
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
				LietKeCacHocSinhCoDiemToanNhoHon5(lst);
				break; 
			}
		case 2: 
			{
				DemSoLuongHocSinhCoDiemToanVaDiemVanLonHon8(lst);
				break;
			}
		case 3:
			{
				SapXepDanhSachCacHocSinhGiamDanTheoDiemTrungBinh(lst);
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
