
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
int Getbit(int &a, int i)
{
	return (a>>i)&1;
}
void Mangchuabit(int a[], int &n)
{
	printf("\nNhap vao so thap phan can chuyen sang he nhi phan:n=");
	scanf ("%d", &n);
	for (int i=0;i<32;i++)
	{
		a[i]=Getbit(n,32-1-i);
	}
}
void Xuatmangchuabit(int a[])
{
	for (int i=0;i<32;i++)
		printf ("%2d", a[i]);
}
void main ()
{
	int n,i,a[32],tieptuc;
	quaylai:Mangchuabit(a,n);
	Xuatmangchuabit(a);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}