
#include<stdio.h>
#include<conio.h>
#include<limits.h>	// Hàm có tác dụng tìm giá trị lớn nhất và nhỏ nhất của kiểu số nguyên (int) .
#define MAX 100
#define bool
void nhapmatran(int a[MAX][MAX],int &m,int &n)
{
	do{
		printf("Nhap vao so dong cua ma tran:m=");
		scanf("%d",&m);
		if(m<1||m>MAX)
			printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(m<1||m>MAX);
	do{
		printf("Nhap vao so cot cua ma tran:n=");
		scanf("%d",&n);
		if(n<1||n>MAX)
			printf("So cot ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	}while(n<1||n>MAX);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Nhap vao a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatmatran(int a[MAX][MAX],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}
void lietkesoluongcacsohoanthientrongcacdongvatimdongconhieusohoanthiennhat(int a[MAX][MAX],int m,int n)
{
	int b[MAX],max=INT_MIN,vitri=0,Co;
	bool Co=false;
	for(int i=0;i<m;i++)
	{
		int dem=0;	//dem=0 phải để ở đây để mỗi lần đếm xong 1 dòng nó lại trả về giá trị 0 như cũ rồi tiếp tục đếm sang dòng mới,nếu không nó sẽ đem kết quả vừa đếm ở dòng trên tiếp tục đếm thêm ở dòng tiếp theo.
		for(int j=0;j<n;j++)
		{
			int tong=0;
			for(int k=1;k<a[i][j];k++)
			{
				if(a[i][j]%k==0)
				{
					tong+=k;
					if(tong==a[i][j])
					{
						dem++;
						b[i]=dem;
						Co=true;	// ở đây ta cần đặt thêm biến bool để khi trong ma trận không có dòng nào chứa số hoàn thiện thì nó sẽ báo lỗi ra chứ nếu không thì tuy không có 1 dòng nào chứa số hoàn thiện nó vẫn in ra các dòng chứa nhiều số hoàn thiện nhất là : tất cả các dòng .
					}
				}
			}
		}
	}
	if(Co==true)
	{
		for(int i=0;i<m;i++)
			printf("\nSo luong cac so hoan thien cua dong %d la:%d",i,b[i]);
	}
	else
		printf("\nKhong co dong nao co chua so hoan thien");
	if(Co==true)
	{
		for(int i=0;i<m;i++)
		{
			if(b[i]>max)
			{
				max=b[i];
			}
		}
		printf("\nCac dong chua nhieu so hoan thien nhat la:");
		for(int i=0;i<m;i++)
		{
			if(b[i]==max)
			{
				vitri=i;
				printf("%4d",vitri);
			}
		}
	}
}
void main()
{
	int a[MAX][MAX],m,n,tieptuc;
	quaylai:nhapmatran(a,m,n);
	printf("\n>>>>>>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a,m,n);
	lietkesoluongcacsohoanthientrongcacdongvatimdongconhieusohoanthiennhat(a,m,n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}