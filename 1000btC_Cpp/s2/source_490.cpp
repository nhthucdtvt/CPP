
#include<stdio.h>
#include<conio.h>
void xulydulieu(int &x,int &y)
{
	int max;
	do{
		printf("Nhap vao x=");
		scanf("%d",&x);
		printf("Nhap vao y=");
		scanf("%d",&y);
		if(x==y)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		if(x!=y)
		{
			if(x>y)
			max=x;
			if(y>x)
			max=y;
			if(max<0||max%13!=0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
			if(max>=0&&max%13==0)
			break;
		}
	}while(x==y||max<0||max%13!=0);
	printf("So ban nhap vao da hop le!\n");
}
void main()
{
	int x,y,NAMSON;
	quaylai:xulydulieu(x,y);
	printf("Ban co muon tiep tuc chay chuong trinh moi khong ? Neu co bam phim C,con lai bam bat ky 1 phim nao khac de thoat!\n");
	NAMSON=getch();
	if(NAMSON=='c'||NAMSON=='C')
		goto quaylai;
}
