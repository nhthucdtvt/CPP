#include <stdio.h>

int main()
{
   char str1[20], str2[30];
   char *str;

   printf("Nhap ten: ");
   scanf("%s", &str1);
   str = str1;

   // printf("Nhap so dien thoai va ngay sinh: ");
   // scanf("%s", &str2);

   printf("Ten vua nhap: %s\n", str);
   // printf("So dien thoai va ngay sinh vua nhap: %s", str2);
   
   return(0);
}