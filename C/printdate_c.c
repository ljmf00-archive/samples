#include <stdio.h>
#include <conio.h>
#include <dos.h>
int main() { struct date d;
   getdate(&d);
   printf("DATE: %d/%d/%d",d.da_day,d.da_mon,d.da_year);
   getch();
return 0; }
