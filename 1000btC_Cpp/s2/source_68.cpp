
#include<stdio.h>
#include<conio.h>
#include<math.h>
void xulydulieu(int &n)
{
	double sqrt(double x);
	printf("Nhap vao n=");
	scanf("%d",&n);
	printf("\nTat ca cac so chinh phuong nho hon %d la:",n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(sqrt (i)==j)
				printf("%4d",i);
		}
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