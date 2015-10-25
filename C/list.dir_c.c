#include <stdio.h>
#include <conio.h>
#include <dir.h>
int main()
{int done; struct ffblk a;
   printf("FILES_CURRENTDIR:\n"); getch();
   done = findfirst("*.*",&a,0);
   while(!done) { printf("%s\n",a.ff_name);
      done = findnext(&a); }
   getch();
return 0; }
