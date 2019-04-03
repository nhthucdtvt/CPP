
#include<stdio.h>
#include<conio.h>
void lietke(int &i)
{
	printf("\nCac so le nho hon 100 khong tinh cac so 5,7,93 la:\n");
	for(i=1;i<100;i+=2)
	{
		if(i==5||i==7||i==93)
			continue;	// Câu lệnh này có tác dụng như khi gặp số 5,7,93 thì nó sẽ bỏ qua không liệt kê và tính tiếp các số khác.
		printf("%4d",i);
	}
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