#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i = 10;
    char c ='c';
    
    int *pi = NULL;
    char *pc = NULL;
    printf("sizeof(*pi): %d\n",sizeof(pi)); // with 32bit os, sizeof pointer is 4B and 64bit os is 8B
    printf("sizeof(*char): %d\n\n",sizeof(pc));
 
    printf("pi: %x\n",pi);
    printf("pc: %x\n\n",pc);


    pi = malloc(sizeof(int)*4);
   // pc = malloc(sizeof(char)*4);
   // pi = calloc(4,sizeof(int));
    pc = calloc(4,sizeof(char));
   
    printf("*pi: %d\n",*(pi));
    printf("*pc: %d\n\n",*(pc));
 
    printf("sizeof(*pi): %d\n",sizeof(pi));
    printf("sizeof(*char): %d\n\n",sizeof(pc));

    printf("pi: %x\n",pi);
    printf("pc: %x\n",pc);

    free(pi);
    free(pc);
    return 0;
}
