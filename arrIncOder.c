#include <stdlib.h>
#include <stdio.h>

void IncOder(int *arr, int n);

int main(int argc, char const *argv[])
{
	/* code */
	int n = 0, arr[20];

	printf("nhap so phan tu n\n");
	scanf("%d",&n);

	printf("nhap vao cac phan tu\n");
	for (int i = 0; i < n; i++)
	{
		/* code */
		scanf("%d",&arr[i]);
	}

	IncOder(arr,n);

	return 0;
}

void IncOder(int *arr, int n){
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		for (int j = i+1; j < n; j++)
		{
			/* code */
			if (arr[i] > arr[j])
			{
				/* code */
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		/* code */
		printf("sau khi oder:%d\n", arr[i]);
	}
}