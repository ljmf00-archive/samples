#include <stdio.h>
int main() { int array[100], position, c, n, value;
   printf("NUM_ELEMENTSOFARRAY?: "); scanf("%d", &n);
   printf("%d_ELEMENTS?: ", n);
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);
   printf("LOCATION_INSERTELEMENT?: "); scanf("%d", &position);
   printf("VALUE_INSERT?: "); scanf("%d", &value);
   for (c = n - 1; c >= position - 1; c--)
      array[c+1] = array[c];
   array[position-1] = value;
   printf("RESULT:\n");
   for (c = 0; c <= n; c++)
      printf("%d\n", array[c]);
   return 0; }
