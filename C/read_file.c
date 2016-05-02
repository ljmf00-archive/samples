#include <stdio.h>
#include <stdlib.h>
int main() { char ch, file_name[25];
FILE *fp;
	printf("NAME OF FILE?: \n");
	gets(file_name);
	fp=fopen(file_name,"r");
	if (fp==NULL) { perror("ERROR WHILE OPENING THE FILE\n");
		exit(EXIT_FAILURE); }
	printf("FILE &s HAVE:\n\n", file_name);
	while((ch=fgetc(fp))!= EOF)
		printf("%c",ch);
	fclose(fp);
return 0;}
