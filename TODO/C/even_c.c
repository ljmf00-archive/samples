#include <stdio.h>
main() {int n; int m;
	printf("NUM?: "); scanf("%d",&m);
	m/=2;
	for(n=1;n<=m;n=n+1)
		printf("%2d\n",n*2);
return 0; }
