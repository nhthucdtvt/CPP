
#include<stdio.h>
#include<conio.h>
#define bool
void kiemtra(int &n)
{
	int tong=0,Co;
	bool Co=false;
	do{
		printf("Nhap vao n(n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
	if(n==0||n==1)
		printf("\nSo %d khong phai la so hoan thien",n);
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			tong+=i;
			Co=true; //Ở đây nếu ta không gán biến bool thì nếu thoát ra khỏi vòng lặp ta mà if(tong==n)...thì kết quả sẽ ra sai hoàn toàn,bắt buộc phải dùng biến bool để xác định được giá trị của tong.
		}
	}
	if(Co==true)
	{
		if(tong==n)
			printf("\nSo %d la so hoan thien",n);
		else
			printf("\nSo %d khong phai la so hoan thien",n);
	}
}
void main()
{
	int n,tieptuc;
	quaylai:kiemtra(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}