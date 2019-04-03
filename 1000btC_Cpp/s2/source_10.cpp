
#include<stdio.h>
#include<conio.h>
#include<math.h>
void tinh(float &x,float &n)
{
	printf("Nhap vao x=");
	scanf("%f",&x);
	printf("Nhap vao n=");
	scanf("%f",&n);
	float s=pow(x,n);
	printf("Ket qua la:%f",s);
}
void main()
{
	float x,n,tieptuc;
	quaylai:tinh(x,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}