#include <stdlib.h>
#include <stdio.h>

void ktArr(int *arr, int n);

int main(int argc, char const *argv[])
{
	/* code */
	int n, arr[20];

	printf("nhap so phan tu\n");
	scanf("%d",&n);

	printf("nhap cac gia tri\n");

	for (int i = 0; i < n; i++)
	{
		/* code */
		scanf("%d",&arr[i]);
		printf("gia tri vua nhap:%d\n", arr[i]);
	}
	
	ktArr(arr,n);

	return 0;
}

void ktArr(int *arr, int n){
	
	int kq[20], k = 0, tick = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j= 0; j < n; j++)
		{
			if(i == arr[j]){
				tick = 1;
				break;	
			} 
			if((j == n-1) && (tick == 0)){
				kq[k] = i;
				printf("kq:%d\n", kq[k]);
				break;
			}	
		}			
		tick = 0;				
	}	
}