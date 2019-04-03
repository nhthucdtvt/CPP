
#include<stdio.h>
#include<conio.h>
void xulydulieu(int &n)
{
	int f;
	printf("Nhap vao n=");
	scanf("%d",&n);
	printf("\nTat ca cac so nguyen to nho hon %d la:",n);
	for(int i=0;i<n;i++)
	{
		f=1;
		if(i<2)
			f=0;
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0)
				f=0;
		}
		if(f==1)
		printf("%4d",i);
	}
}
void main()
{
	int n,tieptuc;
	quaylai:xulydulieu(n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}