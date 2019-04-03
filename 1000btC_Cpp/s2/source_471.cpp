
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoxy(int x,int y)
{
	HANDLE hstdout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x,y};
	SetConsoleCursorPosition(hstdout,position);
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void MeNu()
{
	resizeConsole(800,500);
	int w;
	printf("\n");
	do{
		// Bảng MeNu đưa ra các sự lựa chọn .
		printf("\n-------------------------------------MeNu---------------------------------------\n");
		printf("\n");
		printf("\n 1.Nhap Vao Danh Sach Cac Phan So Va Xuat Ra Cac Phan So Do ");
		printf("\n");
		printf("\n 2.Nhap Vao Phan So K Va Xuat Ra Cac Phan So Trong Danh Sach Ma Nho Hon K ");
		printf("\n");
		printf("\n 3.Rut Gon Cac Phan So Co Trong Danh Sach Va Xuat Ra Cac Phan So Do");
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
				break;
			}
		case 2:
			{
				break;
			}
		case 3:
			{
				break;
			}
		case 0:
			{
				system("cls"); // Xóa đi mọi dữ liệu đã làm trước đó .
				srand(time(NULL));
				for(int j=1;j<=20;j++)
				{
					int color=rand()%15+1;
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
		}
	}while(w!=0);
}
void main()
{
	MeNu();
}