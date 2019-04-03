#include <stdio.h>
int main(int argc, char *argv[])
{
    struct str
    {
       char c;
       int i;
       float f;
       double d;
    }str1;

    //struct str str1;
    str1.c = 'c';
    str1.i = 10;
    str1.f = 10.12;
    //str1.d = 12;

   // str2.c = 'a';

    printf("c = %c\n",str1.c);
    printf("i = %d\n",str1.i);
    printf("f = %f\n",str1.f);
    //printf("d= %d\n",str1.d);

   // printf("str2.c = %c\n",str2.c);
    printf("size of str1 = %d\n",sizeof(str1));
    return 0;
}
