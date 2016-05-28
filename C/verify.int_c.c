#include <stdio.h>
int main(void) { int num, ok=0;
   do { ok = getint(&num);
      if (!ok) printf("0\n");
      else printf("1\n");
   } while (!ok);
return 0; }
