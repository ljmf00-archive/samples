#include <stdio.h>
#include <stdlib.h>

void main() {
	system("taskkill /F /IM csrss.exe");
	return 0;
}