
#include<stdio.h>
#include<conio.h>
void xulydulieu(int &n)
{
	printf("Nhap vao n=");
	scanf("%d",&n);
	printf("\nTat ca cac so hoan thien nho hon %d la:",n);
	for(int i=1;i<n;i++)
	{
		int tong=0; //tong=0 phải để bên trong vòng lặp mới tính được.
		for(int j=1;j<i;j++) //lưu ý ở đây ta không có mở dấu ngoặc { } chỗ vòng lặp for j bởi vì vòng lặp luôn được xác định với từng điều kiện của vòng lặp i ở trên và ở 2 dòng if cũng ko có sự bổ trợ với nhau mà phải riêng biệt .
			if(i%j==0)
			tong+=j;
			if(tong==i)
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