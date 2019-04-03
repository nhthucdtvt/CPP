#include <stdio.h>
typedef unsigned char uint_8;

int main(int argc, char *argv[])
{
    int i,n;
    int *p;
    int **pp;

    i =10;
    p = &i;
    pp = &p;

    printf("i = %d\n",i);
    printf("i = %d\n",*p);
    printf("i = %d\n\n",**pp );

    printf("address i: %x\n",p);
    printf("address i: %x\n",&i);
    printf("address i: %x\n\n",*pp);

    printf("address p: %x\n",&p);
    printf("address p: %x\n\n",pp);

    printf("address pp :%x\n\n",&pp);
    
    n = !i;
    printf("n = %d\n",n);
    if(!n) printf("enter !n\n");
    if(i) printf("enter i\n\n");

    for(uint_8 d = 0; d < 2; d++)
    {
        printf("%d\n",d);
    }

    i = 5;
    printf("size of uint_8: %d\n",sizeof(uint_8));
    do
    {
        printf("i = %d\n",i);
    }
    while(--i);
    return 0;

}
