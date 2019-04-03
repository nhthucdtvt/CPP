
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<math.h>
#define MAX 10
void Nhapdaybit(int a[MAX])
{
	printf("\n>>>>>>>>>Moi ban nhap vao day 10 bit <<<<<<<<<<<<<<<<<\n");
	printf("\n");
	for(int i=0;i<MAX;i++)
	{
		quaylai:printf("\nNhap vao a[%d]=",i);
		scanf("%d",&a[i]);
		if(a[i]!=1&&a[i]!=0)
		{
			printf("\nSo ban nhap vao khong hop le!Xin vui long nhap lai!");
			goto quaylai;
		}
	}
}
void Chuyenrathapphan(int a[MAX])
{
	int s=0,s1=0,s2;
	for(int i=1;i<MAX;i++)
	{
		s1+=a[i]*pow(2.0,9-i);
	}
	if(a[0]==0)
		s2=s1;
	else if(a[0]==1)
		s2=-pow(2.0,9-0)+s1;
	printf("\nSo thap phan tuong ung la:%d",s2);
}
void main()
{
	int a[MAX],tieptuc;
	quaylai:Nhapdaybit(a);
	Chuyenrathapphan(a);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai;
	}
}