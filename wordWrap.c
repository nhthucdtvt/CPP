#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *strrev(char *str);
char *copyNphanTu(char *str1, char *str2, int beg, int end);

int main(int argc, char const *argv[])
{
	/* code */
	char *str = (char*)malloc(20*sizeof(char));
	printf("nhap chuoi:\n");
	scanf("%[^\n]",str);
	printf("chuoi vua nhap:%s\n", str);

	int beg = 0, end = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		/* code */
		if(str[i] == 32){
			beg = i;
			printf("beg:%d\n", beg);
			break;
		} 
	}

	for (int i = strlen(str)-1; i > 0; i--)
	{
		/* code */
		if(str[i] == 32){
			end = i;
			printf("end:%d\n", end);
			break;
		} 
	}

	char *str1 = (char*)malloc(20*sizeof(char));
	char *str2 = (char*)malloc(20*sizeof(char));
	char *str3 = (char*)malloc(20*sizeof(char));
	char *str4 = (char*)malloc(20*sizeof(char));
	char *kq = (char*)malloc(200*sizeof(char));


	memcpy(str1,str,beg+1);
	memcpy(str3,str+end,strlen(str)-1);
	memcpy(str2,str+beg+1,end-beg-1);

	// printf("str1:%s\n", str1);
	// printf("str2:%s\n", str2);
	// printf("str3:%s\n", str3);

	str4 = strrev(str2);
	kq = strcat(str1,str4);
	printf("kq:%s\n", kq);
	kq = strcat(kq,str3);
	printf("kq:%s\n", kq);

	free(str1);
	free(str2);
	free(str3);
	free(str4);

	return 0;
}

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}
