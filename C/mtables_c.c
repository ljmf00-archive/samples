#include <stdio.h>
main() { int n; int num; num=0;
	while(num<=10) { n=1;
		while(n<=10) { printf("%d * %d = %d\n",num, n, num*n);
			n=n+1; }
		num=num+1;
		putchar('\n'); }
return 0; }
