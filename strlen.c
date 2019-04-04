#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int Strlen(char *str);
char *Strcat(char *str1, char *str2);
char *Strncat(char *str1, char *str2, int n);
int Strstr(char *str1, char *str2);

int main(int argc, char const *argv[])
{
	/* code */
	char *str1 = malloc(10*sizeof(char));
	char *str2 = malloc(10*sizeof(char));
	//int length,i;

	printf("nhap vao 2 chuoi:");
	scanf("%s %s",str1,str2);
	//char *str = s;
	//getch();

	printf("2 chuoi vua nhap:%s va %s\n", str1,str2);
	printf("2 chuoi vua nhap:%d va %s\n", *(unsigned const char*)str1);

	printf("length = %d\n", Strlen(str1));
	printf("length = %d\n", Strlen(str2));
	printf("noi chuoi = %s\n", Strcat(str1,str2));
	printf("noi %d ky tu = %s\n", 2,Strncat(str1,str2,2));

	
	return 0;
}

int Strlen(char *str){
	int length = 0;	
	
	while(*str){
		//temp = str;
		length++;
		str++;			
	}
	//printf("length = %d\n", length);
	return length;
}

char *Strcat(char *str1, char *str2){
	char *temp = malloc(10*sizeof(char));
	int length = Strlen(str1) + Strlen(str2);
	//printf("%s\n", str1);
	//printf("%s\n", str2);
	//printf("length = %d\n", length);
	for (int i = 0; i < length; i++)
	{
		/* code */
		if (i < Strlen(str1)) temp[i] = str1[i];
		else temp[i] = str2[i - Strlen(str1)]; 
		
		//printf("%c\n", temp[i]);
	}

	temp[length] = 0;

	return temp;
}

char *Strncat(char *str1, char *str2, int n){
	char *temp = calloc(10,sizeof(char));
	int length = Strlen(str1) + n;

	for (int i = 0; i < length; i++)
	{
		/* code */
		if (i < Strlen(str1)) temp[i] = str1[i];
		else temp[i] = str2[i - Strlen(str1)]; 
		
		//printf("%c\n", temp[i]);
	}

	temp[length] = 0;

	return temp;
}
