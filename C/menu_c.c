#include <stdio.h>
main() {char opc;
	do {
		printf("          COMPANY MENU              \n\n");
		printf(" 1.FORNECEDORES                     \n");
		printf(" 2.CLIENTES                         \n");
		printf(" 3.ENCOMENDAS                       \n");
		printf(" 4.SAIR                             \n\n");
		printf("OP?: "); scanf("%c",&opc);
		switch(opc)
		{
			case '1' : puts("FORNECEDORES"); break;
			case '2' : puts("CLIENTES"); break;
			case '3' : puts("ENCOMENDAS"); break;
			case '4' : puts("SAIR"); break;
			default  : puts("OP?"); break;
		}
		system("cls");
	} while(opc!='4');
}
