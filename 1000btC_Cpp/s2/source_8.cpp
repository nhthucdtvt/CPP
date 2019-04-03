
#include<stdio.h>
#include<conio.h>
void tinh(int &n)
{
	do{
	printf("Nhap vao n(n>=0):n=");
	scanf("%d",&n);
	if(n<0)
		printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
	else
		break;
	}while(n<0);
	float s=0;
	for(int i=0;i<=n;i++)
	{
		s+=1.0*(2*i+1)/(2*i+2); //Hay ta có thể ghi la:s+=(float(2*i+1))/(2*i+2);
	}
	printf("Ket qua la:%f",s);
}
void main()
{
	int n,tieptuc;
	quaylai:tinh(n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}