
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void Nhapvao2songuyenduong(int &a,int &b)
{
	quaylaia:printf("\nNhap vao so nguyen duong a=");
	scanf("%d",&a);
	if(a<0)
	{
		printf("\nGia tri a nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylaia;
	}
	quaylaib:printf("\nNhap vao so nguyen duong b=");
	scanf("%d",&b);
	if(b<0)
	{
		printf("\nGia tri b nhap vao khong hop le!Xin vui long nhap lai!\n");
		goto quaylaib;
	}
}
int TimUCLN(int a,int b)
{
	if(a==0&&b!=0)
		return b;
	if(b==0&&a!=0)
		return a;
	if(a==0&&b==0)
		printf("Khong xac dinh duoc!");
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
int TimBCNN(int a,int b)
{
	int x=(a*b)/TimUCLN(a,b);
	return x;
}
void main()
{
	int a,b,tieptuc;
	quaylai:Nhapvao2songuyenduong(a,b);
	int s=TimUCLN(a,b);
	printf("\nUCLN cua 2 so %d,%d la:%d",a,b,s);
	int x=TimBCNN(a,b);
	printf("\nBCNN cua 2 so %d,%d la:%d",a,b,x);
	printf("\nBan co muon tiep tuc chay lai chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc !\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}