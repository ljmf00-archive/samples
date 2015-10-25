#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{  
     float a,b,c,x;
     printf("a -------- b\n");                    
     printf("c -------- X\n");
     printf("\n\n");
     printf("a b c\n");
     scanf("%f %f %f",&a,&b,&c);  
     printf("%0.1f %0.1f %0.1f\n",a,b,c);
     printf("\n\n");
     x=(c*b)/a;
     printf("X value: %.2f\n",x);
     return 0;
    }