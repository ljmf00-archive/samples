#include <stdio.h>
main(int argc, int *argv[]) {int num=atoi(argv[1]); int tf=argv[1];
	if (tf==0)
		printf("Usage: int <integer>");
	else{
		printf("INT: %d\n",num);
		printf("CHAR: %c",(char)num);}
}