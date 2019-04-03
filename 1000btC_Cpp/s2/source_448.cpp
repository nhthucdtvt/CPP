
// Các thư viện sử dụng trong chương trình .
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
// Khai báo cấu trúc dữ liệu cây nhị phân tìm kiếm (Binary Search Tree) .
struct node
{
	int Key;
	struct node*pLeft;
	struct node*pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
// Khởi tạo cây .
void INit(TREE &t)
{
	t=NULL;
}
// Thêm Node vào cây .
void InSert(TREE &t,int x)
{
	if(t==NULL)
	{
		NODE*q;
		q=new NODE;
		q->Key=x;
		q->pLeft=q->pRight=NULL;
		t=q;
	}
	else
	{
		if(x<t->Key)
		{
			InSert(t->pLeft,x);
		}
		else if(x>t->Key)
		{
			InSert(t->pRight,x);
		}
	}
}
// Nhập dữ liệu vào cây .
void CreateTree(TREE &t)
{
	int Data;
	printf("\nNhap du lieu vao cay ,nhap 696969 de ket thuc!");
	quaylai:printf("\nNhap vao gia tri:");
	scanf("%d",&Data);
	if(Data!=696969)
	{
		InSert(t,Data);
		goto quaylai;
	}
}
// Phép duyệt trước .
void NLR(TREE t)
{
	if(t!=NULL)
	{
		printf("%4d",t->Key);
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}
// Phép duyệt giữa (dùng phép duyệt này thì sau khi duyệt xong các phần tử sẽ tự động được sắp xếp tăng dần . Do phép duyệt giữa đi từ nhánh trái -> gốc -> nhánh phải => dựa vào đặc tính của cây nhị phân tìm kiếm => in ra các giá trị sắp tăng dần ) .
void LNR(TREE t)
{
	if(t!=NULL)
	{
		LNR(t->pLeft);
		printf("%4d",t->Key);
		LNR(t->pRight);
	}
}
// Phép duyệt sau .
void LRN(TREE t)
{
	if(t!=NULL)
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		printf("%4d",t->Key);
	}
}
// Tính tổng tất cả các Node
int SumAllNode(TREE t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int left=SumAllNode(t->pLeft);
		int right=SumAllNode(t->pRight);
		return (t->Key+left+right);
	}
	return 0;
}
// Tính tổng các Node dương .
int SumPositiveNode(TREE t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int left=SumPositiveNode(t->pLeft);
		int right=SumPositiveNode(t->pRight);
		if(t->Key>=0)
		{
			return (t->Key+left+right);
		}
		else if(t->Key<0)
		{
			return (left+right);
		}
	}
	return 0;
}
// Tính tổng các Node âm
int SumNegativeNode(TREE t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int left=SumNegativeNode(t->pLeft);
		int right=SumNegativeNode(t->pRight);
		if(t->Key<0)
		{
			return (t->Key+left+right);
		}
		else if(t->Key>=0)
		{
			return (left+right);
		}
	}
	return 0;
}
// Tính tích tất cả các Node
int MultAllNode(TREE t)
{
	if(t==NULL)
	{
		return 1;
	}
	else
	{
		int left=MultAllNode(t->pLeft);
		int right=MultAllNode(t->pRight);
		return (t->Key*left*right);
	}
	return 0;
}
// Tính tích các Node dương .
int MultPositiveNode(TREE t)
{
	if(t==NULL)
	{
		return 1;
	}
	else
	{
		int left=MultPositiveNode(t->pLeft);
		int right=MultPositiveNode(t->pRight);
		if(t->Key>=0)
		{
			return (t->Key*left*right);
		}
		else if(t->Key<0)
		{
			return (left*right);
		}
	}
	return 0;
}
// Tính tích các Node âm .
int MultNegativeNode(TREE t)
{
	if(t==NULL)
	{
		return 1;
	}
	else
	{
		int left=MultNegativeNode(t->pLeft);
		int right=MultNegativeNode(t->pRight);
		if(t->Key<0)
		{
			return (t->Key*left*right);
		}
		else if(t->Key>=0)
		{
			return (left*right);
		}
	}
	return 0;
}
// Tìm Node lớn nhất
int Max(TREE t)
{
	if(t->pRight==NULL)
	{
		return (t->Key);
	}
	else
	{
		return Max(t->pRight);
	}
}
// Tìm Node nhỏ nhất .
int Min(TREE t)
{
	if(t->pLeft==NULL)
	{
		return (t->Key);
	}
	else
	{
		return Min(t->pLeft);
	}
}
// Đếm số lượng các Node
int CountNode(TREE t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int left=CountNode(t->pLeft);
		int right=CountNode(t->pRight);
		return (1+left+right);
	}
	return 0;
}
// Đếm số lượng các Node dương
int CountPositiveNode(TREE t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int left=CountPositiveNode(t->pLeft);
		int right=CountPositiveNode(t->pRight);
		if(t->Key>=0)
		{
			return (1+left+right);
		}
		else if(t->Key<0)
		{
			return (left+right);
		}
	}
	return 0;
}
// Đếm số lượng các Node âm
int CountNegativeNode(TREE t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int left=CountNegativeNode(t->pLeft);
		int right=CountNegativeNode(t->pRight);
		if(t->Key<0)
		{
			return (1+left+right);
		}
		else if(t->Key>=0)
		{
			return (left+right);
		}
	}
	return 0;
}
// Đếm số lượng các Node lá (Node không có con)
int CountNodeLeaf(TREE t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int left=CountNodeLeaf(t->pLeft);
		int right=CountNodeLeaf(t->pRight);
		if(t->pLeft==NULL&&t->pRight==NULL)
		{
			return (1+left+right);
		}
		else
		{
			return (left+right);
		}
	}
	return 0;
}
// Tìm kiếm 1 Node .
NODE* Search(TREE t,int x)
{
	if(t==NULL)
		return NULL;
	if(x<t->Key)
		Search(t->pLeft,x);
	else
		if(x>t->Key)
			Search(t->pRight,x);
		else
		{
			return t;
		}
}
// Đo chiều cao của Node .
int Height(TREE t)
{
	if(t==NULL)
		return 0;
	int HL,HR;
	HL=Height(t->pLeft);
	HR=Height(t->pRight);
	if(HL>HR)
		return (1+HL);
	return (1+HR);
}
// Tìm phần tử thế mạng cho nút p
void SearchStandFor(TREE &p,TREE &q)
{
	if(q->pLeft)
		SearchStandFor(p,q->pLeft);
	else
	{
		p->Key=q->Key;
		p=q;
		q=q->pRight;
	}
}
// Xóa Node .
void RemoveNode(TREE &t,int x)
{
	NODE*p;
	if(t==NULL)
		printf("\n%d khong co trong cay",x);
	else
	{
		if(x<t->Key)
			RemoveNode(t->pLeft,x);
		else
			if(x>t->Key)
				RemoveNode(t->pRight,x);
			else
			{
				p=t;
				if(p->pRight==NULL)
					t=p->pLeft;
				else
					if(p->pLeft==NULL)
						t=p->pRight;
					else
					{
						SearchStandFor(t->pLeft,p);
					}
				delete p;
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
// Hàm in ra màn hình lời giới thiệu chương trình .
int gioithieu()
{
	FILE* f = fopen("C:\\BinarySearchTree.txt","rt");
	if (f != NULL)
	{
		while (1)
		{			
			if (feof(f)) 
				break;
			if (kbhit())
			{
				char key;
				key = getch();
				if (key == 13 || key == 27)
					return 0;
			}
			char x;
			x = fgetc(f);
			printf("%c",x);	
			Sleep(35);	// Điều chỉnh tốc độ chạy dữ liệu trong file : Sleep càng nhỏ thì tốc độ chạy chữ càng nhanh và ngược lại .			
		}
		fclose(f);
	}
	else 
		printf("Khong co File BinarySearchTree.txt");	
	getch();
}
// Hàm hiển thị lời chào khi kết thúc chương trình .
void Thanks()
{
	system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
	srand(time(NULL)); // Khởi tạo chạy ngẫu nhiên .
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
	resizeConsole(1000,550); // Tăng kích cỡ của khung CMD lên thành chiều rộng 1000,chiều cao 550 .
	textcolor(14); // Tô màu vàng cho chữ .
	gioithieu(); // In ra lời giới thiệu từ File .
	textcolor(7); // Trả về màu chữ bình thường .
	TREE t,p;
	int x;
	system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
	INit(t);
	CreateTree(t);
	printf("\n>>>>>>>>>>>>>> Binary Search Tree <<<<<<<<<<<<<<<<<\n");
	LNR(t);
	int luachon;
	quaylai1:textcolor(2); // Tô màu xanh nhạt cho MeNu
	printf("\n------------------ MeNu ------------------------\n");
	printf("\n1.  Tinh Tong Cac Node ");
	printf("\n2.  Tinh Tong Cac Node Duong ");
	printf("\n3.  Tinh Tong Cac Node Am ");
	printf("\n4.  Tinh Tich Cac Node ");
	printf("\n5.  Tinh Tich Cac Node Duong ");
	printf("\n6.  Tinh Tich Cac Node Am ");
	printf("\n7.  Tim Node Lon Nhat ");
	printf("\n8.  Tim Node Nho Nhat ");
	printf("\n9.  Dem So Luong Cac Node ");
	printf("\n10. Dem So Luong Cac Node Duong ");
	printf("\n11. Dem So Luong Cac Node Am ");
	printf("\n12. Dem So Luong Cac Node La' ");
	printf("\n13. Tim Kiem Mot Node ");
	printf("\n14. Tinh Do Cao Cua Mot Node ");
	printf("\n15. Xoa Mot Node ");
	printf("\n0.  Thoat Chuong Trinh ");
	printf("\n------------------------------------------------\n");
	printf("\n");
	textcolor(7); // Trả về lại màu bình thường .
	quaylai:printf("\nNhap Vao Lua Chon Cua Ban:");
	scanf("%d",&luachon);
	printf("\n");
	printf("\nKet Qua:");
	if(luachon==1)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n1.  Tong cac Node la:%d",SumAllNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==2)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n2.  Tong cac Node duong la:%d",SumPositiveNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==3)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n3.  Tong cac Node am la:%d",SumNegativeNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==4)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n4.  Tich cac Node la:%d",MultAllNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==5)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n5.  Tich cac Node duong la:%d",MultPositiveNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==6)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n6.  Tich cac Node am la:%d",MultNegativeNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==7)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n7.  Node lon nhat la:%d",Max(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==8)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n8.  Node nho nhat la:%d",Min(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==9)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n9.  So luong cac Node la:%d",CountNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==10)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n10. So luong cac Node duong la:%d",CountPositiveNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==11)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n11. So luong cac Node am la:%d",CountNegativeNode(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==12)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\n12. So luong cac Node la' la:%d",CountNodeLeaf(t));
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==13)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\nNhap vao 1 gia tri de tim kiem: ");
		scanf("%d", &x);
		p = Search(t, x);
		if(p != NULL)
			printf ("Node %d co xuat hien trong cay.\n", x);
		else
			printf("Node %d khong co trong cay.\n", x);
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==14)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\nNhap vao 1 Node can tinh do cao : ");
		scanf("%d", &x);
		p = Search(t, x);
		if(p != NULL)
			printf("Chieu cao cua Node %d la %d\n", x, Height(p));
		else
			printf("Node %d khong co trong cay nen khong the tinh do cao duoc \n", x);
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==15)
	{
		system("cls"); // Được hỗ trợ bởi thư viện "Windows.h" chức năng : Xóa đi mọi dữ liệu đã làm trước đó .
		printf("\nNhap vao 1 Node can xoa : ");
		scanf("%d", &x);
		p = Search(t, x);
		if(p != NULL)
		{
			RemoveNode(t,x); // Xóa Node .
			printf("\n>>>>>>>>>>>> Cay Sau Khi Xoa Node %d <<<<<<<<<<<<<<<<\n",x);
			LNR(t); // Duyệt lại cây .
		}
		else
		printf("Node %d khong co trong cay nen khong the xoa duoc \n", x);
		goto quaylai1; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và hiển thị ra lại MeNu cho phép người dùng tiếp tục nhập vào các lựa chọn khác .
	}
	else if(luachon==0)
	{
		Thanks();
	}
	if(luachon!=1&&luachon!=2&&luachon!=3&&luachon!=4&&luachon!=5&&luachon!=6&&luachon!=7&&luachon!=8&&luachon!=9&&luachon!=10&&luachon!=11&&luachon!=12&&luachon!=13&&luachon!=14&&luachon!=15&&luachon!=0)
	{
		printf("\nLua chon ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp chức năng tương tự,dùng để quay lại và cho phép người dùng nhập vào lựa chọn khác do lựa chọn trước đó không hợp lệ !
	}
}
// Hàm chính .
void main()
{
	MeNu();
}
