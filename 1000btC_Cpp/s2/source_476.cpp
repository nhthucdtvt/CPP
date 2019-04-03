
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
void textcolor(int x);
struct phanso
{
	int tuso; // Khai báo tử số dạng số nguyên theo như yêu cầu đề bài .
	int mauso; // Khai báo mẫu số dạng số nguyên theo như yêu cầu đề bài .
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
void DocFileInPut(LIST &l,int &n)
{
	FILE * pFile;
	pFile = fopen("C:\\InPut.txt", "r+t"); // Tìm kiếm và mở file InPut.txt ở trong ổ C để đọc dữ liệu trong file vào chương trình .
	if(pFile==NULL)
	{
		printf("\nKhong Doc Duoc File InPut.txt"); // Báo lỗi không đọc được file InPut.txt
	}
	else
	{
		textcolor(14); // Tô chữ màu vàng .
		printf("\nDu Lieu Tu C:\\InPut.txt Da Duoc Doc Vao Chuong Trinh !");
		textcolor(7); // Trả về màu chữ bình thường .
		fscanf(pFile,"%d\n",&n);
		if(n<0)
		{
			printf("\nSo luong phan so khong hop le!Xin hay kiem tra lai trong File !");
		}
		else if(n>=0)
		{
			INit(l); // Khởi tạo danh sách liên kết đơn .
			for(int i=1;i<=n;i++)
			{
				PHANSO x;
				fscanf(pFile,"%d %d\n",&x.tuso,&x.mauso);
				if(x.mauso==0)
				{
					printf("\nMau so cua phan so thu %d khong hop le!Xin vui kiem tra lai trong File !",i);
				}
				else if(x.mauso!=0)
				{
					// Nếu người dùng nhập vào mẫu số âm thì ta sẽ chuyển dấu trừ (-) lên tử số và mẫu số lúc đó sẽ không còn âm nữa . Để làm được điều đó thì ta phải đặt điều kiện nếu người dùng nhập vào giá trị mẫu số âm thì đồng thời nhân tử số & mẫu số cho -1 .
					if(x.mauso < 0)
					{
						x.tuso=x.tuso*-1; // Nhân tử số cho -1 .
						x.mauso=x.mauso*-1; // Nhân mẫu số cho -1 .
					}
					NODE*p=getnode(x);
					AddTail(l,p);
				}
			}
		}
	}
	fclose(pFile); // Đóng File lại .
}
void XuatDuLieu(LIST l)
{
	int dem=0;
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem++;
	}
	printf("\nCo %d Phan So Trong Danh Sach",dem);
	printf("\n");
	int dem1=0;
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem1++;
		printf("\nPhan So thu %d la:%d/%d\n",dem1,p->Data.tuso,p->Data.mauso);
	}
}
void RutGonPhanSo(LIST l)
{
	NODE* pNode; // Tạo Node trong danh sách liên kết đơn .
	LIST Prs; // Khai báo cấu trúc dữ liệu cho danh sách liên kết đơn .
	INit(Prs); // Khởi tạo danh sách liên kết đơn .
	// Áp dụng ý tưởng trên vào trong bài này thì để cho đơn giản nhất thì ta sẽ đi so sánh giữa tử số & mẫu số của phân số cần rút gọn tìm ra min trong 2 cái đó. Ta khởi tạo min là tử số và thực hiện phép so sánh,nếu mẫu số mà < min => cập nhật lại min = mẫu số.Tiếp đó Khởi tạo vòng lặp giảm dần từ min -> 1 . Nếu giá trị đầu tiên nào thỏa tử số & mẫu số của phân số cần rút gọn đồng thời chia hết cho nó => đó là giá trị cần tìm và ta lần lượt đem tử số & mẫu số chia cho giá trị vừa tìm được .
	// Tuy nhiên khi áp dụng vào thì sẽ phát sinh ra 4 trường hợp đó là : 1/ tử số & mẫu số của phân số cần rút gọn đều là số dương . 2/ tử số là số âm,mẫu số là số dương . 3/ tử số & mẫu số đều là số âm . 4/ tử số là số dương,mẫu số là số âm . Ta phải thêm vào 1 số điều kiện ràng buộc .
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		// Trường hợp rút gọn cả tử số & mẫu số đều là số dương .
		if(pNode->Data.tuso>=0 && pNode->Data.mauso>0)
		{
			int min; // Khởi tạo 1 biến min .
			min=pNode->Data.tuso; // Gán min = giá trị của tử số .
			if(min>pNode->Data.mauso) // Nếu giá trị mẫu số mà nhỏ hơn min thì cập nhật lại min .
			{
				min=pNode->Data.mauso; // cập nhật lại min .
			}
			for(int i=min;i>=1;i--) // Khởi tạo vòng lặp giảm dần từ min -> 1 .
			{
				if(pNode->Data.tuso%i==0 && pNode->Data.mauso%i==0) // Nếu giá trị đầu tiên thỏa đồng thời tử số & mẫu số cùng chia hết => giá trị cần tìm .
				{
					pNode->Data.tuso=pNode->Data.tuso/i; // lấy tử số chia cho giá trị đó .
					pNode->Data.mauso=pNode->Data.mauso/i; // lấy mẫu số chia cho giá trị đó .
				}
			}
		}
		// Trường hợp rút gọn tử số là số âm & mẫu số là số dương .
		if(pNode->Data.tuso<0 && pNode->Data.mauso>0)
		{
			pNode->Data.tuso=pNode->Data.tuso*-1; // Đầu tiên ta phải nhân tử số cho -1 để biến tử số về dạng số dương để tiện cho việc rút gọn,sau khi xong rồi ta sẽ nhân thêm -1 vào để trả lại giá trị ban đầu của tử số .
			int min; // Khởi tạo 1 biến min .
			min=pNode->Data.tuso; // Gán min = giá trị của tử số .
			if(min>pNode->Data.mauso) // Nếu giá trị mẫu số mà nhỏ hơn min thì cập nhật lại min .
			{
				min=pNode->Data.mauso; // cập nhật lại min .
			}
			pNode->Data.tuso=pNode->Data.tuso*-1; // Trả lại giá trị lúc đầu của tử số bằng cách tiếp tục nhân thêm cho -1 .
			for(int i=min;i>=1;i--) // Khởi tạo vòng lặp giảm dần từ min -> 1 .
			{
				if(pNode->Data.tuso%i==0 && pNode->Data.mauso%i==0) // Nếu giá trị đầu tiên thỏa đồng thời tử số & mẫu số cùng chia hết => giá trị cần tìm .
				{
					pNode->Data.tuso=pNode->Data.tuso/i; // lấy tử số chia cho giá trị đó .
					pNode->Data.mauso=pNode->Data.mauso/i; // lấy mẫu số chia cho giá trị đó .
				}
			}
		}
		// Còn lại 2 trường hợp là cả tử số và mẫu số đều là số âm & trường hợp tử số là số dương,mẫu số là số âm thì không cần làm do khi nhập phân số ta đã đặt điều kiện để xuất ra là nếu mẫu số < 0 thì đồng thời nhân -1 cho cả tử số & mẫu số . Và khi đã nhân xong rồi thì lập tức lại trở về 1 trong 2 trường hợp rút gọn mà ta đã làm ở trên .
		AddTail(Prs,pNode);
	}
	textcolor(14); // Tô màu vàng .
	printf("\n>>>>>>>>>>>>>>>> Xuat Ra Danh Sach Cac Phan So Sau Khi Rut Gon <<<<<<<<<<<<<<<<<\n");
	textcolor(7); // Trả về màu chữ bình thường .
	XuatDuLieu(Prs);
}
void HoanVi(PHANSO &x,PHANSO &y)
{
	PHANSO temp=x;
	x=y;
	y=temp;
}
void HamSapTangDan(LIST &l)
{
	NODE*p,*q;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		for(q=p->pNext;q!=NULL;q=q->pNext)
		{
			if((p->Data.tuso*1.0)/p->Data.mauso>(q->Data.tuso*1.0)/q->Data.mauso)
			{
				HoanVi(p->Data,q->Data);
			}
		}
	}
}
void SapTangDanCacPhanSo(LIST l)
{
	HamSapTangDan(l);
	textcolor(14); // Tô màu vàng .
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>> Sap Tang Dan Cac Phan So <<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	textcolor(7); // Trả về màu chữ bình thường .
	XuatDuLieu(l);
}
void GhiFileOutPut(LIST l,int n)
{
	FILE * pFile;
	pFile = fopen ("C:\\OutPut.txt","wt"); 
	fprintf(pFile,"%d\n",n);
	for(NODE*pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		fprintf(pFile,"%d %d\n",pNode->Data.tuso,pNode->Data.mauso);
	}
	textcolor(14);
	printf("\nCac Phan So Sau Khi Sap Xep Tang Dan Duoc Ghi Vao File : OutPut.txt Trong o C ! ");
	printf("\n");
	printf("\nMoi Ban Vao C:\\OutPut.txt De Xem Ket Qua ! ");
	printf("\n");
	textcolor(7);
	fclose (pFile); // Đóng file lại .
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
// Hàm đồ họa cho tên tác giả .
void TacGia()
{
	textcolor(14); // Tô màu vàng .
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tDesigned By : \n");
	printf("\n\t\t\tNguyen Viet Nam Son - 1261031\n");
	printf("\n\t\t\tChu Anh Anh         - 1261001\n");
	printf("\n\t\t\tTran Van Nghia      - 1261026\n");
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
	resizeConsole(1000,800); // Tăng kích cỡ của khung CMD lên thành chiều rộng 1000,chiều cao 800 .
	LIST lst; // Khai báo cấu trúc dữ liệu danh sách liên kết đơn .
	int n;
	int luachon;
	quaylai1:textcolor(2); // Tô màu xanh nhạt cho MeNu
	printf("\n----------------------------- MeNu --------------------------------\n");
	printf("\n1. Doc Du Lieu Cac Phan So Tu C:\\InPut.txt Vao Chuong Trinh ");
	printf("\n2. Xuat Du Lieu Cac Phan So Vua Doc Tu File InPut.txt ");
	printf("\n3. Rut Gon Cac Phan So ");
	printf("\n4. Sap Xep Tang Dan Cac Phan So Sau Khi Da Duoc Rut Gon ");
	printf("\n5. Ghi Noi Dung Cac Phan So Sau Khi Da Sap Xep Vao C:\\OutPut.txt ");
	printf("\n0. Thoat Chuong Trinh ");
	printf("\n-------------------------------------------------------------------\n");
	textcolor(7); // Trả về lại màu bình thường .
	printf("\n");
	quaylai:printf("\nNhap Vao Lua Chon Cua Ban:");
	scanf("%d",&luachon);
	printf("\n");
	printf("\nKet Qua:");
	if(luachon==1)
	{
		system("cls"); 
		TacGia();
		DocFileInPut(lst,n);
		printf("\n");
		goto quaylai1; 
	}
	else if(luachon==2)
	{
		system("cls"); 
		XuatDuLieu(lst);
		goto quaylai1; 
	}
	else if(luachon==3)
	{
		system("cls"); 
		RutGonPhanSo(lst);
		goto quaylai1; 
	}
	else if(luachon==4)
	{
		system("cls"); 
		RutGonPhanSo(lst);
		SapTangDanCacPhanSo(lst);
		goto quaylai1; 
	}
	else if(luachon==5)
	{
		system("cls"); 
		RutGonPhanSo(lst);
		SapTangDanCacPhanSo(lst);
		GhiFileOutPut(lst,n);
		goto quaylai1; 
	}
	else if(luachon==0)
	{
		system("cls"); 
		Thanks();
	}
	else if(luachon!=1&&luachon!=2&&luachon!=3&&luachon!=4&&luachon!=5&&luachon!=0)
	{
		printf("\nLua chon ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; 
	}
}
void main()
{
	MeNu();
}
