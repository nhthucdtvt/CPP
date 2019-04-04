#include <stdio.h>
#include <string.h>

int main()
{
   char src[40];
   char dest[12];
  
   memset(dest, 'c', sizeof(dest)-1);
   strcpy(src, "Hoc C co ban va nang cao tai VietJack !!!");
   strncpy(dest, src, 10);

   printf("Sau khi thuc hien ham strncpy, chuoi dest co dang: \n%s\n", dest);
   
   return(0);
}