
#include<stdio.h>
#include<conio.h>
void xulydulieu(int &n)
{
	int dem=0;
	do{
		printf("Nhap vao n(n>=0):n=");
		scanf("%d",&n);
		if(n<0)
			printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<0);
	if(n==0)
		printf("\nSo %d khong co uoc so nao ca",n);
	if(n>0)
	{
		printf("\nCac uoc so cua so %d la:",n);
		for(int k=1;k<=n;k++)
		{
			if(n%k==0)
			{
				printf("%4d",k);
				dem++;
			}
		}
	}
	printf("\nSo %d co %d uoc so",n,dem);
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