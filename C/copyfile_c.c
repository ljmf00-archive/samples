#include <stdio.h>
#include <stdlib.h>
int main() { char ch, source_file[], target_file[];
   FILE *source, *target;
   printf("FILE?: \n"); gets(source_file);
   source = fopen(source_file, "r");
   if( source == NULL )
   { printf("Press any key to exit...\n");
      exit(EXIT_FAILURE); }
   printf("PATH?: \n"); gets(target_file);
   target = fopen(target_file, "w");
   if( target == NULL ) { fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE); }
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
   printf("FILE COPIED.\n");
   fclose(source);
   fclose(target);
return 0; }
