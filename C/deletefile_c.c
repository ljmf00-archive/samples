#include <stdio.h>
main() { int status; char file_name[];
   printf("FILE?: \n"); gets(file_name);
   status = remove(file_name);
   if( status == 0 )
      printf("%s FILE DELETED.\n",file_name);
   else
   {
      printf("ERROR: UNABLE TO DELETE A FILE\n");
      perror("ERORR; EXIT");
   }
return 0; }
