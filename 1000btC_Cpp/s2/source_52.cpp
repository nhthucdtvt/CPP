
#include<stdio.h>
#include<conio.h>
#include<math.h> //ở đây ta có thể dùng thư viện là #include<cmath> cũng như nhau (chỉ có đối với C++).
void xulydulieu(float &x,int &n)
{
	float s=0,s1=0;
	double pow(double y,double z); // dòng này phải khai báo hàm mũ (pow) để sử dụng ở dưới,điều này là bắt buộc đối với C++ còn C chuẩn thì không cần.
	printf("Nhap vao x=");
	scanf("%f",&x);
	do{
	printf("\nNhap vao n(n>=1):n=");
	scanf("%d",&n);
	if(n<1)
		printf("So ban nhap vao khong hop le!Xin vui long nhap lai!\n");
	else
		break;
	}while(n<1);
	for(int i=1;i<=n;i++)
	{
		s+=i;
		s1+=pow(-1,i)*(pow(x,i)/s); // ở đây s1 đang ở kiểu số thực và pow cũng đang ở kiểu số thực nên kết quả luôn đúng,nếu s1 ở số thực mà vế sau nó ở dạng số nguyên thì ta phải nhân thêm 1.0 vào mới đúng được.
	}
	printf("\nKet qua la:%f",s1);
}
void main()
{
	int n,tieptuc;
	float x;
	quaylai:xulydulieu(x,n);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
		goto quaylai;
}