
#include "stdio.h"
#include "conio.h"
#include "limits.h"
#include "float.h"
#include "time.h"
#include "Windows.h"
#define NamHienTai 2013
struct sinhvien
{
	int MaSinhVien;
	char Ten[30];
	int NamSinh;
	float Toan;
	float Ly;
	float Hoa;
	float TrungBinh;
};
typedef struct sinhvien SINHVIEN;
struct node
{
	SINHVIEN Data;
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
	quaylai:printf("\nNhap vao so luong sinh vien:");
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
		printf("\n>>>>>>>>>>>>>>> Nhap Vao Thong Tin Cua Sinh Vien Thu %d <<<<<<<<<<<<<<<<<<<\n",i);
		printf("\nNhap vao Ma Sinh Vien:");
		scanf("%d",&x.MaSinhVien);
		fflush(stdin);
		printf("\nNhap vao Ten Sinh Vien:");
		gets(x.Ten);
		printf("\nNhap vao Nam Sinh:");
		scanf("%d",&x.NamSinh);
		do{
			printf("\nNhap vao diem mon Toan:");
			scanf("%f",&x.Toan);
			if(x.Toan<0||x.Toan>10)
			{
				printf("\nDiem mon Toan khong hop le!Xin vui long nhap lai!");
			}
		}while(x.Toan<0||x.Toan>10);
		do{
			printf("\nNhap vao diem mon Ly:");
			scanf("%f",&x.Ly);
			if(x.Ly<0||x.Ly>10)
			{
				printf("\nDiem mon Ly khong hop le!Xin vui long nhap lai!");
			}
		}while(x.Ly<0||x.Ly>10);
		do{
			printf("\nNhap vao diem mon Hoa:");
			scanf("%f",&x.Hoa);
			if(x.Hoa<0||x.Hoa>10)
			{
				printf("\nDiem mon Hoa khong hop le!Xin vui long nhap lai!");
			}
		}while(x.Hoa<0||x.Hoa>10);
		x.TrungBinh=(x.Toan+x.Ly+x.Hoa)/3;
		NODE*p=getnode(x);
		AddTail(l,p);
	}
}
void OutPut(LIST l)
{
	int dem=0;
	printf("\nSTT\tMa Sinh Vien\tTen\tNam Sinh\tToan\tLy\tHoa\tTrung Binh");
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem++;
		printf("\n%d\t%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f",dem,p->Data.MaSinhVien,p->Data.Ten,p->Data.NamSinh,p->Data.Toan,p->Data.Ly,p->Data.Hoa,p->Data.TrungBinh);
	}
}
void TimSinHVienCoDiemTrungBinhMax(LIST l)
{
	int dem=0;
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	float max=FLT_MIN;
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.TrungBinh>max)
		{
			max=pNode->Data.TrungBinh;
		}
	}
	printf("\nDiem Trung Binh Max La:%f",max);
	printf("\n");
	printf("\n>>>>>>>>>>>>> Danh Sach Cac Sinh Vien Dat Diem Trung Binh Cao Nhat <<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nSTT\tMa Sinh Vien\tTen\tNam Sinh\tToan\tLy\tHoa\tTrung Binh");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(max==pNode->Data.TrungBinh)
		{
			dem++;
			printf("\n%d\t%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f",dem,pNode->Data.MaSinhVien,pNode->Data.Ten,pNode->Data.NamSinh,pNode->Data.Toan,pNode->Data.Ly,pNode->Data.Hoa,pNode->Data.TrungBinh);
		}
	}
}
void SapTangDanTheoDiemTrungBinh(LIST &l)
{
	NODE *p,*q;
	SINHVIEN temp;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data.TrungBinh>q->Data.TrungBinh)
			{
				temp=p->Data;
				p->Data=q->Data;
				q->Data=temp;
			}
		}
	}
}
void SapDanhSachSinhVienTangDanTheoDiemTrungBinh(LIST l)
{
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	SapTangDanTheoDiemTrungBinh(l);
	printf("\n>>>>>>>>>>> Danh Sach Sau Khi Da Sap Tang Dan Theo Diem Trung Binh:<<<<<<<<<<<<<<\n");
	OutPut(l);
}
void SapGiamDanTheoDiemToan(LIST &l)
{
	NODE *p,*q;
	SINHVIEN temp;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if(p->Data.Toan<q->Data.Toan)
			{
				temp=p->Data;
				p->Data=q->Data;
				q->Data=temp;
			}
		}
	}
}
void SapDanhSachSinhVienGiamDanTheoDiemToan(LIST l)
{
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	SapGiamDanTheoDiemToan(l);
	printf("\n>>>>>>>>>>> Danh Sach Sau Khi Da Sap Giam Dan Theo Diem Toan:<<<<<<<<<<<<<<\n");
	OutPut(l);
}
void TimKiemVaInRaCacSinhVienCoDiemTrungBinhLonHon5VaKhongCoMonNaoDuoi3(LIST l)
{
	int dem=0;
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	printf("\n>>>>>>> Danh Sach Cac Sinh Vien Co Diem Trung Binh > 5 Va Khong Co Mon Nao  <<<<<<<<<\n");
	printf("\n");
	printf("\nSTT\tMa Sinh Vien\tTen\tNam Sinh\tToan\tLy\tHoa\tTrung Binh");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(pNode->Data.TrungBinh>5&&(pNode->Data.Toan>=3&&pNode->Data.Ly>=3&&pNode->Data.Hoa>=3))
		{
			dem++;
			printf("\n%d\t%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f",dem,pNode->Data.MaSinhVien,pNode->Data.Ten,pNode->Data.NamSinh,pNode->Data.Toan,pNode->Data.Ly,pNode->Data.Hoa,pNode->Data.TrungBinh);
		}
	}
}
void TimSinhVienCoTuoiLonNhat(LIST l)
{
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	int tuoi,dem=0;
	int max=INT_MIN;
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		tuoi = NamHienTai - pNode->Data.NamSinh;
		if(tuoi>max)
		{
			max=tuoi;
		}
	}
	printf("\nTuoi lon nhat la:%d",max);
	printf("\n");
	printf("\n>>>>>>>>>> Danh Sach Cac Sinh Vien Co Tuoi Lon Nhat La:<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nSTT\tMa Sinh Vien\tTen\tNam Sinh\tToan\tLy\tHoa\tTrung Binh");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		if(max==(2013-(pNode->Data.NamSinh)))
		{
			dem++;
			printf("\n%d\t%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f",dem,pNode->Data.MaSinhVien,pNode->Data.Ten,pNode->Data.NamSinh,pNode->Data.Toan,pNode->Data.Ly,pNode->Data.Hoa,pNode->Data.TrungBinh);
		}
	}
}
void TraCuuThongTinSinhVienDuaVaoTen(LIST l)
{
	SINHVIEN x;
	int dem=0;
	NODE*pNode;
	LIST Prs;
	INit(Prs);
	fflush(stdin);
	printf("\nNhap vao ten sinh vien can tim kiem:");
	gets(x.Ten);
	printf("\n>>>>>>>>> Thong Tin Ve Sinh Vien Can Tim Kiem:<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nSTT\tMa Sinh Vien\tTen\tNam Sinh\tToan\tLy\tHoa\tTrung Binh");
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		// Hàm so sánh 2 chuỗi strcmp được hỗ trợ bởi thư viện "string.h" hay "Windows.h" . Ở đây ta đã khai báo thư viện "Windows.h" nên không cần dùng thư viện "string.h" nữa .
		// Hàm strcmp(const char*s1,const char*s2) so sánh 2 chuỗi s1 & s2 , nếu s1 < s2 => trả về giá trị âm , s1==s2 => trả về giá trị 0 , s1 > s2 => trả về giá trị dương .
		if(strcmp(x.Ten,pNode->Data.Ten)==0)
		{
			dem++;
			printf("\n%d\t%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f",dem,pNode->Data.MaSinhVien,pNode->Data.Ten,pNode->Data.NamSinh,pNode->Data.Toan,pNode->Data.Ly,pNode->Data.Hoa,pNode->Data.TrungBinh);
		}
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
void NguyenVietNamSon()
{
	textcolor(14); // Tô màu vàng .
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\t\t\tDesigned By : Nguyen Viet Nam Son              \n");
	printf("\n--------------------------------------------------------------------------------\n");
	textcolor(7); // Trả lại màu chữ bình thường .
}
void MeNu()
{
	resizeConsole(800,500); // Tăng kích cỡ của khung CMD lên thành chiều rộng 800,chiều cao 500 .
	int w;
	LIST lst; // Khai báo cấu trúc dữ liệu danh sách liên kết đơn .
	printf("\n");
	quaylai:NguyenVietNamSon();
	InPut(lst);
	printf("\n>>>>>>>>>>>>>>>>>>>>>Xuat Ra Danh Sach Cac Sinh Vien:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	do{
		// Bảng MeNu đưa ra cho người dùng các sự lựa chọn .
		textcolor(2); // Tô màu xanh nhạt cho MeNu
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");		
		printf("\n 1.Tim Sinh Vien Co Diem Trung Binh Cao Nhat ");
		printf("\n");
		printf("\n 2.Sap Xep Danh Sach Lop Theo Thu Tu Tang Dan Cua Diem Trung Binh ");
		printf("\n");
		printf("\n 3.Sap Xep Danh Sach Lop Theo Thu Tu Giam Dan Cua Diem Toan ");
		printf("\n");
		printf("\n 4.Tim Kiem Va In Ra Cac Sinh Vien Co Diem Trung Binh >5 Va Khong Co Mon Nao <3 ");
		printf("\n 5.Tim Sinh Vien Co Tuoi Lon Nhat ");
		printf("\n");
		printf("\n 6.Tra Cuu Thong Tin Cua 1 Sinh Vien Dua Vao Ho Ten Sinh Vien ");
		printf("\n");
		printf("\n 7.Cap Nhat Lai Danh Sach Sinh Vien ");
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
				TimSinHVienCoDiemTrungBinhMax(lst);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 2:
			{
				SapDanhSachSinhVienTangDanTheoDiemTrungBinh(lst);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 3: 
			{
				SapDanhSachSinhVienGiamDanTheoDiemToan(lst);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 4: 
			{
				TimKiemVaInRaCacSinhVienCoDiemTrungBinhLonHon5VaKhongCoMonNaoDuoi3(lst);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 5:
			{
				TimSinhVienCoTuoiLonNhat(lst);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 6:
			{
				TraCuuThongTinSinhVienDuaVaoTen(lst);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 7:
			{
				system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng xóa hết đi mọi dữ liệu cũ để bắt đầu cho lần thực thi mới .
				goto quaylai; // Dùng hợp ngữ chức năng quay lại từ đầu .
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 0: // Thoát chương trình .
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