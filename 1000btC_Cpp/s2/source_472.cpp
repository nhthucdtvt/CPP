
#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"
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
void InPut(LIST &l)
{
	int n;
	quaylai:printf("\nNhap so luong cac phan so:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
		goto quaylai; // Dùng hợp ngữ thay cho vòng lặp . Mục đích nếu người dùng nhập vào số lượng không hợp lệ thì chương trình sẽ bắt nhập lại đến khi nào hợp lệ thì thôi .
	}
	INit(l); // Khởi tạo danh sách liên kết đơn .
	for(int i=1;i<=n;i++)
	{
		PHANSO x;
		printf("\n>>>>>>>>>>>>>>>>>> Moi ban nhap vao phan so thu:%d <<<<<<<<<<<<<<<<<",i);
		printf("\n");
		printf("\nNhap vao tu so cua phan so thu %d: ",i);
		scanf("%d",&x.tuso);
		do{
			printf("\nNhap vao mau so cua phan so thu %d: ",i);
			scanf("%d",&x.mauso);
			if(x.mauso == 0)
			{
				printf("\nMau so cua phan so thu %d khong hop le!Xin vui long nhap lai!",i);
			}
		}while(x.mauso == 0); // Điều kiện mẫu số phải khác 0 . Nếu người dùng nhập vào mẫu số bằng 0 thì bắt nhập lại .
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
void OutPut(LIST l)
{
	int dem=0; // Khởi tạo ban đầu biến đếm = 0 .
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		dem++; // Đếm số lượng các phân số xuất ra .
		printf("\nPhan so thu %d La:%d/%d",dem,p->Data.tuso,p->Data.mauso); // Ở đây khi xuất ra phân số ta có thể để gộp lại là p->Data cũng được chứ không nhất thiết phải liệt kê ra từng cái là p->Data.tuso,p->Data.mauso bởi vì cấu trúc của phân số ta khai báo ở dạng số nguyên thì chỉ có tử số và mẫu số tuần tự nhau .
	}
}
void SoSanhPhanSo(LIST l)
{
	int tusok; // Khai báo tử số của phân số k .
	int mausok; // Khai báo mẫu số của phân số k .
	int dem=0; // Khởi tạo biến đếm = 0 .
	printf("\n>>>>>>>>>>>>>>>>>>Nhap Vao Phan So K:<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\nNhap vao tu so cua phan so K:");
	scanf("%d",&tusok);
	do{
		printf("\nNhap vao mau so cua phan so K:");
		scanf("%d",&mausok);
		if(mausok==0)
		{
			printf("\nMau so cua phan so K khong hop le!Xin vui long nhap lai!");
		}
	}while(mausok==0); // Đặt điều kiện mẫu số phải khác 0 .Nếu mẫu số bằng 0 thì bắt nhập lại .
	// Nếu người dùng nhập vào mẫu số âm thì ta sẽ chuyển dấu trừ (-) lên tử số và mẫu số lúc đó sẽ không còn âm nữa . Để làm được điều đó thì ta phải đặt điều kiện nếu người dùng nhập vào giá trị mẫu số âm thì đồng thời nhân tử số & mẫu số cho -1 .
	if(mausok<0)
	{
		tusok=tusok*-1; // Nhân tử số của phân số k cho -1 .
		mausok=mausok*-1; // Nhân mẫu số của phân số k cho -1 .
	}
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>Phan So K:<<<<<<<<<<<<<<<<<<<<\n");
	printf("%d/%d",tusok,mausok); // Xuất ra phân số K .
	printf("\n");
	NODE* pNode; // Tạo Node trong danh sách liên kết đơn .
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{
		// Đếm số lượng các phân số trong danh sách mà có giá trị nhỏ hơn giá trị của phân số K .
		if(((pNode->Data.tuso*1.0)/pNode->Data.mauso)<((tusok*1.0)/mausok)) // Tính ra kết quả của phân số bằng cách lấy tử số * 1.0 (ép kiểu về dạng thực) rồi đem chia cho mẫu số rồi dựa vào kết quả đó so sánh các phân số với nhau và liệt kê ra được tất cả các phân số có trong list < phân số K . Ở đây để cho dễ nhìn thì trước khi khởi tạo điều kiện ta có thể gán 1 biến float ketqua=(tuso*1.0)/mauso rồi bên trong điều kiện này chỉ cần gọi lại biến đó nhưng như vậy sẽ khiến lãng phí đi bộ nhớ nên ta làm gộp chung lại .
		{
			dem++; 
		}
	}
	printf("\nCo %d phan so trong danh sach nho hon phan so K",dem);
	printf("\n");	
	dem=0; // Khởi tạo lại biến đếm = 0 .
	for(pNode=l.pHead;pNode!=NULL;pNode=pNode->pNext)
	{	
		// Xuất ra các phân số trong danh sách mà có giá trị nhỏ hơn giá trị của phân số k .
		if(((pNode->Data.tuso*1.0)/pNode->Data.mauso)<((tusok*1.0)/mausok)) // Tính ra kết quả của phân số bằng cách lấy tử số * 1.0 (ép kiểu về dạng thực) rồi đem chia cho mẫu số rồi dựa vào kết quả đó so sánh các phân số với nhau và liệt kê ra được tất cả các phân số có trong list < phân số K . Ở đây để cho dễ nhìn thì trước khi khởi tạo điều kiện ta có thể gán 1 biến float ketqua=(tuso*1.0)/mauso rồi bên trong điều kiện này chỉ cần gọi lại biến đó nhưng như vậy sẽ khiến lãng phí đi bộ nhớ nên ta làm gộp chung lại .
		{
			dem++;
			printf("\nPhan so thu %d La:%d/%d\n",dem,pNode->Data.tuso,pNode->Data.mauso); // Ở đây khi xuất ra phân số ta có thể để gộp lại là p->Data cũng được chứ không nhất thiết phải liệt kê ra từng cái là p->Data.tuso,p->Data.mauso bởi vì cấu trúc của phân số ta khai báo ở dạng số nguyên thì chỉ có tử số và mẫu số tuần tự nhau .
		}
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
	printf("\n>>>>>>>>>>>>>>>>>>Xuat Ra Cac Phan So Da Rut Gon:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");	
	OutPut(Prs);
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
	resizeConsole(800,500); // Tăng kích cỡ của khung CMD lên thành chiều rộng 800,chiều cao 500 .
	int w;
	LIST lst; // Khai báo cấu trúc dữ liệu danh sách liên kết đơn .
	printf("\n");
	quaylai:NguyenVietNamSon();
	InPut(lst);
	printf("\n>>>>>>>>>>>>>>>>>>>>>Xuat Ra Danh Sach Cac Phan So:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	OutPut(lst);
	printf("\n");
	// Chương trình yêu cầu bước đầu tiên là người dùng sẽ phải nhập vào các thông tin phân số trong danh sách liên kết . Sau đó với các thông tin đó chương trình sẽ tiếp tục đưa ra bảng MeNu cho người dùng nhập vào sự lựa chọn .
	do{
		// Bảng MeNu đưa ra cho người dùng các sự lựa chọn .
		textcolor(2); // Tô màu xanh nhạt cho MeNu
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");		
		printf("\n 2.Nhap Vao Phan So K Va Xuat Ra Cac Phan So Trong Danh Sach Ma Nho Hon K ");
		printf("\n");
		printf("\n 3.Rut Gon Cac Phan So Co Trong Danh Sach Va Xuat Ra Cac Phan So Do ");
		printf("\n");
		printf("\n 4.Cap Nhat Lai Thong Tin Cac Phan So ");
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
		case 2: // Nhập vào phân số k và thực hiện việc so sánh các phân số có trong danh sách với phân số k vừa nhập,xuất ra các phân số trong danh sách mà có giá trị nhỏ hơn giá trị của phân số k .
			{
				SoSanhPhanSo(lst);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 3: // Thực hiện việc rút gọn các phân số có trong danh sách và xuất ra các phân số đó sau khi đã rút gọn .
			{
				RutGonPhanSo(lst);
				break; // có tác dụng khi đã làm xong nhiệm vụ của nó thì sẽ thoát ra và hiện lại bảng MeNu cho người dùng muốn nhập vào lựa chọn tiếp theo . Nếu không có lệnh break này thì khi đã làm xong nhiệm vụ của nó,chương trình không thoát ra và hiện lại bảng MeNu cho ta nhập vào lựa chọn tiếp theo mà sẽ tiếp tục chạy xuống những đoạn lệnh bên dưới và tính toán những đoạn lệnh đó mặc dù chưa có sự cho phép của ta !
			}
		case 4: // Quay lại cập nhật lại đầu vào thông tin về danh sách các phân số .
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
