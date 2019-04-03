
#include<stdio.h>
#include<conio.h>
void lietke(int &i)
{
	printf("\nCac so le nho hon 100 khong tinh cac so 5,7,93 la:\n");
	for(i=1;i<5;i+=2)
		printf("%4d",i);
	for(i=9;i<93;i+=2)
		printf("%4d",i);
	for(i=95;i<100;i+=2)
		printf("%4d",i);
}
void main()
{
	int tieptuc,i;
	quaylai:lietke(i);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}