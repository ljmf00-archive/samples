#include <stdio.h>
#include <dos.h>
main() { struct time t;
  gettime(&t);
   printf("Current system time is %d : %d : %d\n",t.ti_hour,t.ti_min,t.ti_sec);
return 0; }
