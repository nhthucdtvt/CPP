#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	unsigned int d = 0, n = 0, sumOdd = 0, so = 0;
	do{
		printf("nhap n:\n");
		scanf("%d",&n);
		if ((n < 0) || (n > 4000000000)) printf("vui long nhap lai\n");		
	}while((n < 0) || (n > 4000000000));
	
	printf("n = %d\n",n );

	d = n;
	while(d){
		//temp = d;
		so = d%10;
		d = d/10;
		//printf("so = %d\n", so);
		if ((so % 2) != 0)
		{
			/* code */
			printf("so = %d\n", so);
			sumOdd += so;
		}
	}

	printf("sumOdd = %d\n", sumOdd);

	return 0;
}
