#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() { int n, max, num, c;
   printf("RAND_NUM?: \n"); scanf("%d", &n);
   printf("MAX?: \n"); scanf("%d", &max);
   printf("%d RAND FROM 0 TO %d ARE: \n\n", n, max);
   randomize();
   for (c = 1; c <= n; c++)
   { num = random(max);
      printf("%d\n",num);         }
   getch();
return 0; }
