#include <stdio.h>
int main() { int c, n, fact = 1;
  printf("NUM?: "); scanf("%d", &n);
  for (c = 1; c <= n; c++)
    fact = fact * c;
  printf("Factorial: %d = %d\n", n, fact);
return 0; }
