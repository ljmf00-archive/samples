#include <stdio.h>
int main() { int first, second, add, subtract, multiply; float divide;
   printf("TWO_INT?: "); scanf("%d%d", &first, &second);
   add = first + second; printf("\nSum = %d\n",add);
   subtract = first - second; printf("Difference = %d\n",subtract);
   multiply = first * second; printf("Multiplication = %d\n",multiply);
   divide = first / (float)second; printf("Division = %.2f\n",divide);
return 0; }
