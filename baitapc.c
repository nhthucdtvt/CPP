#include <stdio.h>
#include<math.h>
int main( )
{   
   int n,a,b;
   a = 3;
   b = 4;
   float sum;
   float pc;
   pc = (float)3/2;
   printf("pc = %0.3f\n", pc);
   //printf("sum = %0.1f\n",sum );
   printf("nhap n");
   scanf("%d",&n);

   //sum = 1/n;
   //sum = 3/2;
   printf("n = %d\n",n);
   sum = (float)1/n;
   printf("1/n = %0.3f\n",sum );
   while(n > 0){
   		sum = (float)(sum + (float)(1/n));
   		printf("sum = %0.3f\n",sum );   		
   		//printf("n = %d\n",n);
   		n--;
   }   
   printf("sum = %0.3f\n",sum );

   return 0;
}
