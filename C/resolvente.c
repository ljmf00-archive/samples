#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{  
     float totalp,totall,a,b,c,radical;
     printf("a b c\n");                    
     scanf("%f %f %f",&a,&b,&c);  
     printf("%0.1f %0.1f %0.1f\n",a,b,c);
     printf("\n\n");
                        radical=(b*b)-(4*a*c);      
                        totalp=((-b)+sqrt(radical))/(2*a);
                        totall=((-b)-sqrt(radical))/(2*a);
     if (radical < 0)
     {
              printf("IMPOSIBLE!\n\n");
              }
              else{ 
     printf("plus %.2f\n",totalp);
     printf("less %.2f\n",totall);
     }    
     return 0;
    }