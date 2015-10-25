#include <stdio.h>
#include <conio.h>
#include <dos.h>
main() { struct date d;
   printf("ENTER DD MM YYYY ?: "); scanf("%d%d%d",&d.da_day,&d.da_mon,&d.da_year);
   setdate(&d);
   printf("CURRENT SYSTEM DATE: %d/%d/%d\n",d.da_day,d.da_mon,d.da_year);
   getch();
return 0; }
