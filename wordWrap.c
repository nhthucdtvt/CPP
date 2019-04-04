#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *substr(char *str1, char *str2, int beg, int n);

int main(int argc, char const *argv[])
{
	/* code */
	//char *str = (char*)malloc(20*sizeof(char));
	//char *temp = (char*)malloc(20*sizeof(char));
	//char str[20], str1[20], str2[20], str3[20], temp[20], kq[20];
	char * str, *str1, *str2, *str3, *kq, *temp;

	str = (char*)malloc(20*sizeof(char));
	str1 = (char*)malloc(20*sizeof(char));
	str2 = (char*)malloc(20*sizeof(char));
	str3 = (char*)malloc(20*sizeof(char));
	temp = (char*)malloc(20*sizeof(char));
	kq = (char*)malloc(20*sizeof(char));

	int length = 0, lengthArr = 0;
	int arr[20];

	printf("nhap 1 chuoi\n");
	scanf("%[^\n]",str);
	printf("chuoi vua nhap:%s\n", str);

	length = strlen(str);

	int j = 0;
	for (int i = 0; i < length; i++)
	{
		/* code */
		if (str[i] == 32)
		{
			/* code */
			arr[j] = i;
			printf("arr:%d\n",i);
			j++;
		}
	}
	lengthArr = j;
	printf("lengthArr:%d\n", lengthArr);
	
	str1 = substr(str1,str,0,(arr[0]));
	printf("str1:%s\n", str1);

	str3 = substr(str3,str,arr[lengthArr],length - arr[lengthArr]);
	str2 = substr(str2,str,arr[0],arr[lengthArr] - arr[0]);
	
	// int d= 0;
	// for (int i = arr[0]; i < lengthArr; ++i)
	// {
	// 	/* code */
	// 	str2[d] = str[i];
	// 	d++;
	// }
	// str2[d] = 0;

	// d = 0;
	// for (int i = lengthArr; i < length; ++i)
	// {
	// 	/* code */
	// 	str3[d] = str[i];
	// 	d++;
	// }
	// str3[d] = 0;

	int k = 0;
	for (int i = lengthArr; i > 0; i--)
	{
		/* code */
		temp[k] = str[i];
	}
	//temp = strrev((char*)str2);

	kq = strcat(str1,temp);
	kq = strcat(kq,str3);

	printf("kq:%s\n", kq);

	return 0;
}

char *substr(char *str1, char *str2, int beg, int n){
	while(n > 0){
		*str1 = *(str2 + beg);
		str1++;
		str2++;
		n--;
	}
	*str1 = '\0';
	return str1;
}