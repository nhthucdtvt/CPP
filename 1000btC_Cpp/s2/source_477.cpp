
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
// Hàm tăng kích cỡ của khung CMD .
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm lấy tọa độ vị trí con trỏ .
void gotoxy(int x,int y)
{
	HANDLE hstdout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x,y};
	SetConsoleCursorPosition(hstdout,position);
}
// Hàm tô màu chữ .
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
// Hàm đồ họa cho tên tác giả .
void TacGia()
{
	textcolor(14); // Tô chữ màu vàng .
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tDesigned By : \n");
	printf("\n\t\t\tNguyen Viet Nam Son - 1261031\n");
	printf("\n\t\t\tChu Anh Anh         - 1261001\n");
	printf("\n\t\t\tTran Van Nghia      - 1261026\n");
	printf("\n--------------------------------------------------------------------------------\n");
}
void ThanksYouForUsingTheProgram()
{
	system("cls"); // Xóa đi mọi dữ liệu đã làm trước đó .
	srand(time(NULL)); // Khởi tạo chạy ngẫu nhiên .
	for(int j=1;j<=20;j++)
	{
		int color=rand()%15+1; // Khởi tạo màu chạy ngẫu nhiên trong đoạn thang màu [1,15].
		Sleep(300);
		gotoxy(j-1,40);
		printf("			");
		gotoxy(j,40);
		textcolor(color);
		printf("\nThanks You For Using The Program ! Goodbye And See You Later !\n"); // Khi người dùng thoát chương trình sẽ hiển thị ra lời chào !
	}
	textcolor(15);
	gotoxy(3,42);
}
void ThanksTeacherHoThiThanhTuyen()
{
	int i,j;
	for(i=1;i<=100;i++)
	{
		system("cls"); // Xóa đi mọi dữ liệu đã làm trước đó .
		textcolor(10); // Tô chữ màu xanh đậm .
		printf("\n\t\t\t Connecting From Thank Teacher... ");
		printf("\n\n\t\t\tSend ......... To Teacher:Ho Thi Thanh Tuyen  ");
		printf("\n\n\t\t\t\tLoading...%d %c", i, '%');
		printf("\n\n\t\t\t------------------------------------------");
		textcolor(7); // Trả về màu chữ bình thường .
		if(i==11)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\n\t\t Thoi gian troi qua that nhanh chong ! ");
			Sleep(4000);
		}
		if(i==22)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\n\tMoi hom nao chung em con bo*~ ngo*~ voi mon hoc Cau Truc Du Lieu !");
			Sleep(5000);
		}
		if(i==33)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\n\t\tMoi hom nao con hoc tiet thuc hanh Cau Truc Du Lieu dau tien !");
			Sleep(5000);
		}
		if(i==44)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\n\t\tMoi hom nao con ngoi nghe Co dung tren buc giang bai !");
			Sleep(5000);
		}
		if(i==55)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\n\tMa hom nay da la bai tap thuc hanh cuoi cung chung em nop cho Co ! ");
			printf("\n\n\tThoi gian troi qua that nhanh chong,moi do ma da 10 thang troi qua ! ");
			Sleep(4000);
		}
		if(i==66)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\nChung em rat cam on Co da tan tinh chi day chung em trong suot 10 thang qua ! ");
			Sleep(4000);
		}
		if(i==77)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\nChung em cung khong biet noi gi hon ngoai viec gui den Co loi chuc suc khoe tot dep nhat ! ");
			Sleep(4000);
		}
		if(i==88)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\nChuc cho Co luon gap nhieu dieu may man,gat hai duoc nhieu thanh cong trong cong viec & trong cuoc song ! ");
			Sleep(4000);
		}
		if(i==99)
		{
			for(j=1;j<=23;j++)
			{
				system("cls");
				if(j==1)
				{
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j== 2)
				{
					printf("\t\t * . \n");
					Sleep(500);
				}
				if(j== 3)
				{
					printf("\t\t * . \n");
					printf("\t\t . \n");
					Sleep(500);
				}
				if(j== 4)
				{
					printf("\t\t * . . \n");
					printf("\t\t . \n");
					Sleep(500);
				}
				if(j== 5)
				{
					printf("\t\t * . . * \n");
					printf("\t\t . \n");
					Sleep(500);
				}
				if(j== 6)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . \n");
					Sleep(500);
				}
				if(j== 7)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . * \n");
					Sleep(500);
				}
				if(j== 8)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j== 9)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . * \n");
					printf("\t\t * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j== 10)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . * \n");
					printf("\t\t * \n");
					printf("\t\t * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j== 11)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . * \n");
					printf("\t\t * \n");
					printf("\t\t * \n");
					printf("\t\t * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j==12)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . * \n");
					printf("\t\t * \n");
					printf("\t\t * \n");
					printf("\t\t * * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j==13)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . * \n");
					printf("\t\t * \n");
					printf("\t\t * * \n");
					printf("\t\t * * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j==14)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t . * \n");
					printf("\t\t * * \n");
					printf("\t\t * * \n");
					printf("\t\t * * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j==15)
				{
					printf("\t\t * . . *. \n");
					printf("\t\t * . * \n");
					printf("\t\t * * \n");
					printf("\t\t * * \n");
					printf("\t\t * * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j==16)
				{
					printf("\t\t .* . . *. \n");
					printf("\t\t * . * \n");
					printf("\t\t * * \n");
					printf("\t\t * * \n");
					printf("\t\t * * \n");
					printf("\t\t * \n");
					Sleep(500);
				}
				if(j==17)
				{
					printf("\t\t .* . . *. .* . . *. \n");
					printf("\t\t * . * * . * \n");
					textcolor(13); // Tô chữ màu hồng !
					printf("\t\t * I Wish You ​Success In Work And In Life * * \n");
					printf("\t\t * * * * \n");
					printf("\t\t * * * * \n");
					printf("\t\t * * \n");
					Sleep(500);
				}
				if(j==18)
				{
					printf("\t\t \n");
					printf("\t\t \n");
					textcolor(13); // Tô chữ màu hồng !
					printf("\t\t I Wish You ​Success In Work And In Life \n");
					printf("\t\t \n");
					printf("\t\t \n");
					printf("\t\t \n");
					Sleep(500);
				}
				if(j==19)
				{
					printf("\t\t .* . . *. .* . . *. \n");
					printf("\t\t * . * * . * \n");
					textcolor(13); // Tô chữ màu hồng !
					printf("\t\t * I Wish You ​Success In Work And In Life * * \n");
					printf("\t\t * * * * \n");
					printf("\t\t * * * * \n");
					printf("\t\t * * \n");
					Sleep(500);
				}
				if(j==20)
				{
					printf("\t\t \n");
					printf("\t\t \n");
					textcolor(13); // Tô chữ màu hồng !
					printf("\t\t I Wish You ​Success In Work And In Life \n");
					printf("\t\t \n");
					printf("\t\t \n");
					printf("\t\t \n");
					Sleep(500);
				}
				if(j==21)
				{
					printf("\t\t .* . . *. .* . . *. \n");
					printf("\t\t * . * * . * \n");
					textcolor(13); // Tô chữ màu hồng !
					printf("\t\t * I Wish You ​Success In Work And In Life * * \n");
					printf("\t\t * * * * \n");
					printf("\t\t * * * * \n");
					printf("\t\t * * \n");
					Sleep(500);
				}
				if(j==22)
				{
					printf("\t\t \n");
					printf("\t\t \n");
					textcolor(13); // Tô chữ màu hồng !
					printf("\t\t I Wish You ​Success In Work And In Life \n");
					printf("\t\t \n");
					printf("\t\t \n");
					printf("\t\t \n");
					Sleep(500);
				}
				if(j==23)
				{
					printf("\t\t .* . . *. .* . . *. \n");
					printf("\t\t * . * * . * \n");
					textcolor(13); // Tô chữ màu hồng !
					printf("\t\t * I Wish You ​Success In Work And In Life * * \n");
					printf("\t\t * * * * \n");
					printf("\t\t * * * * \n");
					printf("\t\t * * \n");
					Sleep(500);
				}
			}
			Sleep(5000);
		}
		if(i==100)
		{
			textcolor(13); // Tô chữ màu hồng !
			printf("\n\n\t\t\t\t100 %c THE END ! ", '%');
			printf("\n\n\t\t\tGood Luck To You ");
			Sleep(5000);
		}
		Sleep(100);
	}
}
struct phanso
{
	int tuso; // Khai báo theo đúng như yêu cầu đề bài .
	int mauso; // Khai báo theo đúng như yêu cầu đề bài .
};
typedef struct phanso PHANSO;
void DocFileInPut(PHANSO a[],int &n)
{
	FILE * pFile;
	pFile = fopen("C:\\InPut.txt", "r+t"); // Tìm kiếm và mở File InPut.txt ở trong ổ đĩa C để đọc dữ liệu trong File vào chương trình .
	if(pFile==NULL) // Nếu File rỗng (không tìm thấy File) .
	{
		textcolor(13); // Tô màu hồng . 
		printf("\nKhong Doc Duoc File InPut.txt Trong O C \n"); // Báo lỗi không đọc được file InPut.txt trong ổ đĩa C .
		printf("\nMoi Ban Tao Ra C:\\InPut.txt De Nhap Du Lieu Cho Chuong Trinh "); // Nhắc nhở người dùng tạo ra File InPut.txt để nhập dữ liệu cho chương trình .
	}
	else // Nếu đã tìm được File thì đọc dữ liệu trong File vào chương trình .
	{
		textcolor(13); // Tô màu hồng . 
		printf("\nDu Lieu Tu C:\\InPut.txt Da Duoc Doc Vao Chuong Trinh !\n"); // Thông báo đã đọc thành công dữ liệu từ File InPut.txt vào chương trình .
		textcolor(7); // Trả về màu chữ bình thường .
		fscanf(pFile,"%d\n",&n); // Đọc dữ liệu số lượng các phân số trong File vào chương trình .
		if(n<0)
		{
			printf("\nSo luong phan so khong hop le!Xin hay kiem tra lai trong File !"); // Báo lỗi số lượng các phân số trong File không hợp lệ .
		}
		else if(n>=0)
		{
			for(int i=0;i<n;i++)
			{
				fscanf(pFile,"%d %d\n",&a[i].tuso,&a[i].mauso); // Đọc dữ liệu tử số và mẫu số trong File vào chương trình .
				if(a[i].mauso==0) // Trường hợp phân số không hợp lệ (mẫu số bằng 0) .
				{
					printf("\nMau so cua phan so thu %d khong hop le!Xin vui kiem tra lai trong File !\n",i+1); // Báo lỗi phân số không hợp lệ (mẫu số bằng 0) .
				}
				else if(a[i].mauso!=0) // Trường hợp phân số hợp lệ (mẫu số khác 0) .
				{
					// Nếu người dùng nhập vào mẫu số âm thì ta sẽ chuyển dấu trừ (-) lên tử số và mẫu số lúc đó sẽ không còn âm nữa . Để làm được điều đó thì ta phải đặt điều kiện nếu người dùng nhập vào giá trị mẫu số âm thì đồng thời nhân tử số & mẫu số cho -1 .
					if(a[i].mauso < 0)
					{
						a[i].tuso=a[i].tuso *-1; // Nhân tử số cho -1 .
						a[i].mauso=a[i].mauso *-1; // Nhân mẫu số cho -1 .
					}
				}
			}
		}
	}
	fclose(pFile); // Đóng File lại .
}
void XuatDuLieu(PHANSO a[],int n)
{
	int dem=0; // Khởi tạo biến đếm = 0 .
	for(int i=0;i<n;i++)
	{
		if(a[i].mauso!=0)
		{
			dem++; // Đếm số lượng các phân số hợp lệ (mẫu số khác 0) .
		}
	}
	printf("\nTong cong co tat ca %d phan so !\n",n); // In ra tổng số lượng các phân số .
	printf("\nCo %d phan so hop le !\n",dem); // In ra số lượng các phân số hợp lệ .
	for(int i=0;i<n;i++)
	{
		if(a[i].mauso!=0)
		{
			printf("\nPhan so thu %d la:%d/%d",i+1,a[i].tuso,a[i].mauso); // In ra các phân số hợp lệ (mẫu số khác 0) .
		}
	}
	printf("\n");
}
void RutGonPhanSo(PHANSO a[],int n)
{
	// Áp dụng ý tưởng trên vào trong bài này thì để cho đơn giản nhất thì ta sẽ đi so sánh giữa tử số & mẫu số của phân số cần rút gọn tìm ra min trong 2 cái đó. Ta khởi tạo min là tử số và thực hiện phép so sánh,nếu mẫu số mà < min => cập nhật lại min = mẫu số.Tiếp đó Khởi tạo vòng lặp giảm dần từ min -> 1 . Nếu giá trị đầu tiên nào thỏa tử số & mẫu số của phân số cần rút gọn đồng thời chia hết cho nó => đó là giá trị cần tìm và ta lần lượt đem tử số & mẫu số chia cho giá trị vừa tìm được .
	// Tuy nhiên khi áp dụng vào thì sẽ phát sinh ra 4 trường hợp đó là : 1/ tử số & mẫu số của phân số cần rút gọn đều là số dương . 2/ tử số là số âm,mẫu số là số dương . 3/ tử số & mẫu số đều là số âm . 4/ tử số là số dương,mẫu số là số âm . Ta phải thêm vào 1 số điều kiện ràng buộc .
	printf("\n");
	for(int i=0;i<n;i++)
	{
		// Trường hợp rút gọn cả tử số & mẫu số đều là số dương .
		if(a[i].tuso>=0&&a[i].mauso>0)
		{
			int min; // Khởi tạo 1 biến min .
			min=a[i].tuso; // Gán min = giá trị của tử số .
			if(min>a[i].mauso) // Nếu giá trị mẫu số mà nhỏ hơn min thì cập nhật lại min .
			{
				min=a[i].mauso; // cập nhật lại min .
			}
			for(int j=min;j>=1;j--) // Khởi tạo vòng lặp giảm dần từ min -> 1 .
			{
				if(a[i].tuso%j==0&&a[i].mauso%j==0) // Nếu giá trị đầu tiên thỏa đồng thời tử số & mẫu số cùng chia hết => giá trị cần tìm .
				{
					a[i].tuso=a[i].tuso/j; // lấy tử số chia cho giá trị đó .
					a[i].mauso=a[i].mauso/j; // lấy mẫu số chia cho giá trị đó .
				}
			}
		}
		// Trường hợp rút gọn tử số là số âm & mẫu số là số dương .
		if(a[i].tuso<0&&a[i].mauso>0)
		{
			a[i].tuso=a[i].tuso*-1; // Đầu tiên ta phải nhân tử số cho -1 để biến tử số về dạng số dương để tiện cho việc rút gọn,sau khi xong rồi ta sẽ nhân thêm -1 vào để trả lại giá trị ban đầu của tử số .
			int min; // Khởi tạo 1 biến min .
			min=a[i].tuso; // Gán min = giá trị của tử số .
			if(min>a[i].mauso) // Nếu giá trị mẫu số mà nhỏ hơn min thì cập nhật lại min .
			{
				min=a[i].mauso; // cập nhật lại min .
			}
			a[i].tuso=a[i].tuso*-1; // Trả lại giá trị lúc đầu của tử số bằng cách tiếp tục nhân thêm cho -1 .
			for(int j=min;j>=1;j--) // Khởi tạo vòng lặp giảm dần từ min -> 1 .
			{
				if(a[i].tuso%j==0&&a[i].mauso%j==0) // Nếu giá trị đầu tiên thỏa đồng thời tử số & mẫu số cùng chia hết => giá trị cần tìm .
				{
					a[i].tuso=a[i].tuso/j; // lấy tử số chia cho giá trị đó .
					a[i].mauso=a[i].mauso/j; // lấy mẫu số chia cho giá trị đó .
				}
			}
		}
		// Còn lại 2 trường hợp là cả tử số và mẫu số đều là số âm & trường hợp tử số là số dương,mẫu số là số âm thì không cần làm do khi nhập phân số ta đã đặt điều kiện để xuất ra là nếu mẫu số < 0 thì đồng thời nhân -1 cho cả tử số & mẫu số . Và khi đã nhân xong rồi thì lập tức lại trở về 1 trong 2 trường hợp rút gọn mà ta đã làm ở trên .		
	}
}
void Swap(PHANSO &x,PHANSO &y)
{
	PHANSO temp;
	temp=x;
	x=y;
	y=temp;
}
void Shift(PHANSO a[],int n, int i)
{
	int left = 2*i+1; 
	int right = 2*i+2;
	int max;
	if(left<n&&(((a[left].tuso*1.0)/a[left].mauso)>((a[i].tuso*1.0)/a[i].mauso)))
	{
		max = left;
	}
	else
	{
		max = i;
	}
	if(right<n&&(((a[right].tuso*1.0)/a[right].mauso)>((a[max].tuso*1.0)/a[max].mauso)))
	{
		max = right;
	}
	if(i!=max) 
	{
		Swap(a[i],a[max]);
		Shift(a,n,max);
	}
}
// Sử dụng hàm Shift bên trên với left hiện hành là phần tử ở giữa dãy ((N-1)/2). Lặp lại quá trình trên với left giảm dần về đầu dãy. */
void CreateHeap(PHANSO a[],int n)
{
	for(int left=(n-1)/2;left>=0;left--) 
	{
		Shift(a,n,left);
	}
}
void HeapSort(PHANSO a[], int n) 
{
	CreateHeap(a,n); 
	for(int right=n-1;right>0;right--) 
	{
		Swap(a[0],a[right]); 
		Shift(a,right,0);
	}
}
void GhiFileOutPut(PHANSO a[],int n)
{
	FILE * pFile;
	pFile = fopen ("C:\\OutPut.txt","wt"); // Mở tập tin OutPut.txt trong ổ đĩa C để ghi dữ liệu.Tập tin sẽ được tạo mới nếu chưa có,ngược lại nếu tập tin có sẵn thì dữ liệu trước đó sẽ bị xóa hết .
	fprintf(pFile,"%d\n",n); // Ghi số lượng các phân số vào đầu File OutPut.txt trong ổ đĩa C .
	for(int i=0;i<n;i++)
	{
		fprintf(pFile,"%d %d\n",a[i].tuso,a[i].mauso); // Ghi giá trị của các phân số sau khi rút gọn và được sắp xếp tăng dần vào File OutPut.txt trong ổ C .
	}
	textcolor(14); // Tô chữ màu vàng .
	printf("\nCac Phan So Sau Khi Sap Xep Tang Dan Duoc Ghi Vao Trong C:\\OutPut.txt ! ");
	printf("\n");
	printf("\nMoi Ban Vao C:\\OutPut.txt De Xem Ket Qua ! ");
	printf("\n");
	fclose (pFile); // Đóng file lại .
}
void MeNu()
{
	resizeConsole(1000,800); // Tăng kích cỡ của khung CMD lên thành chiều rộng 1000,chiều cao 800 .
	PHANSO a[200]; // Khai báo cấu trúc phân số .
	int n;
	int luachon; // Lựa chọn .
	quaylai1:textcolor(10); // Tô màu xanh đậm cho MeNu
	printf("\n---------------------------------- MeNu ----------------------------------------");
	printf("\n1. Doc Du Lieu Cac Phan So Tu C:\\InPut.txt Vao Chuong Trinh ");
	printf("\n2. Xuat Du Lieu Cac Phan So Vua Doc Tu File InPut.txt ");
	printf("\n3. Rut Gon Cac Phan So ");
	printf("\n4. Sap Xep Tang Dan Cac Phan So Sau Khi Da Duoc Rut Gon ");
	printf("\n5. Ghi Noi Dung Cac Phan So Sau Khi Da Sap Xep Vao C:\\OutPut.txt \n");
	textcolor(13);
	printf("\n\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3");
	textcolor(10);
	printf("\n6. \3\3\3 Loi Chuc Tot Dep Nhat Chung Em Gui Den Teacher : Ho Thi Thanh Tuyen \3\3\3  \n");
	textcolor(13);
	printf("\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3");
	textcolor(10);
	printf("\n0. Thoat Chuong Trinh \n");
	printf("\n--------------------------------------------------------------------------------\n");
	textcolor(7); // Trả về lại màu bình thường .
	printf("\n");
	quaylai:printf("\nNhap Vao Lua Chon Cua Ban:");
	scanf("%d",&luachon);
	printf("\n");
	printf("\nKet Qua:");
	if(luachon==1) // Lựa chọn đọc dữ liệu các phân số từ File InPut.txt trong ổ đĩa C vào chương trình .
	{
		system("cls"); // Xóa đi hết mọi dữ liệu đã thực thi trước đó . 
		TacGia(); // In ra đồ họa tác giả .
		DocFileInPut(a,n); // Đọc File vào chương trình .
		printf("\n");
		goto quaylai1; // Dùng hợp ngữ - chức năng để quay trở lại bảng MeNu cho lần lựa chọn tiếp theo .
	}
	else if(luachon==2) // Lựa chọn xuất ra các dữ liệu vừa đọc từ File .
	{
		system("cls"); // Xóa đi hết mọi dữ liệu đã thực thi trước đó .
		textcolor(14); // Tô chữ màu vàng .
		printf("\n>>>>>>>>>>>>>>>> Du Lieu Cac Phan So Duoc Doc Tu File InPut.txt <<<<<<<<<<<<<<<<\n");
		textcolor(7); // Trả về màu chữ bình thường .
		XuatDuLieu(a,n); // Xuất ra dữ liệu vừa đọc từ File .
		goto quaylai1; // Dùng hợp ngữ - chức năng để quay trở lại bảng MeNu cho lần lựa chọn tiếp theo .
	}
	else if(luachon==3) // Lựa chọn rút gọn các phân số và xuất ra chúng .
	{
		system("cls"); // Xóa đi hết mọi dữ liệu đã thực thi trước đó .
		textcolor(14); // Tô chữ màu vàng .
		printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Cac Phan So Da Rut Gon <<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		textcolor(7); // Trả về màu chữ bình thường .
		RutGonPhanSo(a,n); // Rút gọn các phân số .
		XuatDuLieu(a,n); // In ra các phân số sau khi đã được rút gọn ở trên .
		goto quaylai1; // Dùng hợp ngữ - chức năng để quay trở lại bảng MeNu cho lần lựa chọn tiếp theo .
	}
	else if(luachon==4) // Lựa chọn sắp xếp tăng dần các phân số đã được rút gọn bằng thuật toán HeapSort .
	{
		system("cls"); // Xóa đi hết mọi dữ liệu đã thực thi trước đó .
		textcolor(14); // Tô chữ màu vàng .
		printf("\n>>>>>>>>>>>>>>>> Sap Xep Tang Dan Cac Phan So Sau Khi Rut Gon <<<<<<<<<<<<<<<<<<\n");
		textcolor(7); // Trả về màu chữ bình thường .
		RutGonPhanSo(a,n); // Rút gọn các phân số .
		HeapSort(a,n); // Sắp xếp các phân số vừa được rút gọn tăng dần bằng thuật toán HeapSort .
		XuatDuLieu(a,n); // Xuất ra các phân số sau khi đã sắp xếp tăng dần .
		goto quaylai1; // Dùng hợp ngữ - chức năng để quay trở lại bảng MeNu cho lần lựa chọn tiếp theo .
	}
	else if(luachon==5) // Lựa chọn ghi kết quả các phân số sau khi sắp xếp tăng dần vào File: OutPut.txt trong ổ C .
	{
		system("cls"); // Xóa đi hết mọi dữ liệu đã thực thi trước đó .
		RutGonPhanSo(a,n); // Rút gọn các phân số .
		HeapSort(a,n); // Sắp xếp các phân số vừa được rút gọn tăng dần bằng thuật toán HeapSort .
		GhiFileOutPut(a,n); // Ghi các kết quả vừa sắp xếp xong vào C:\\OutPut.txt .
		goto quaylai1; // Dùng hợp ngữ - chức năng để quay trở lại bảng MeNu cho lần lựa chọn tiếp theo .
	}
	else if(luachon==6) // Lựa chọn in ra lời chúc tốt đẹp nhất của tụi em dành cho Cô .
	{
		ThanksTeacherHoThiThanhTuyen(); // In ra lời chúc tốt đẹp nhất mà chúng em gửi tặng đến Cô .
		system("cls"); // Xóa đi hết mọi dữ liệu đã thực thi trước đó .
		goto quaylai1; // Dùng hợp ngữ - chức năng để quay trở lại bảng MeNu cho lần lựa chọn tiếp theo .
	}
	else if(luachon==0) // Lựa chọn thoát chương trình .
	{
		ThanksYouForUsingTheProgram(); // In ra lời chào khi kết thúc chương trình .
	}
	else if(luachon!=1&&luachon!=2&&luachon!=3&&luachon!=4&&luachon!=5&&luachon!=6&&luachon!=0) 
	{
		printf("\nLua chon ban nhap vao khong hop le!Xin vui long nhap lai!"); // Báo lỗi yêu cầu lựa chọn không hợp lệ .
		goto quaylai; // Dùng hợp ngữ - chức năng để quay trở lại cho phép người dùng nhập lại lựa chọn khác .
	}
}
void main()
{
	MeNu();
}
