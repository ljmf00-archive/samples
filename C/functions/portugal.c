/*lsferreira programming */

//Include Header
#include "portugal.h"


    void imprimir(char* strputs)
    {
        puts(strprint);
    }

    void caracter(char charputchar)
    {
        putchar(charputchar);
    }
    void caracterentrada(char chargetchar)
    {
        getchar(chargetchar);
    }
    void entrada(char* strgets)
    {
        gets(strgets);
    }
    int quociente(int divindendo, int divisor)
    {
        div_t divresult;
        divresult = div(dividendo,divisor);
        return divresult.quot;
    }
    int resto(int divindendo, int divisor)
    {
        div_t divresult;
        divresult = div(dividendo,divisor);
        return divresult.rem;
    }
    int quocientelongo(int divindendo, int divisor)
    {
        ldiv_t ldivresult;
        ldivresult = ldiv(dividendo,divisor);
        return ldivresult.quot;
    }
    int restolongo(int divindendo, int divisor)
    {
        ldiv_t ldivresult;
        ldivresult = ldiv(dividendo,divisor);
        return ldivresult.rem;
    }
	int fraseparainteiro(char* stratoi) {
		return atoi(stratoi);
	}
	long int fraseparainteirolongo(char* stratol) {
		return atol(stratol);
	}
	double fraseparadecimaldouble(char* stratof) {
		return atof(stratof);
	}
	float fraseparadecimalfloat(char* stratof) {
		return atof(stratof);
	}
	void remover(char* strremove) {
		remove(strremove);
	}
	void renomear(char* strold, char* strnew) {
		rename(strold, strnew);
	}
	void entradacaracter(char charscanf) {
		scanf("%c",&charscanf);
	}
	void entradainteiro(int intscanf) {
		scanf("%d", &intscanf);
	}
	void entradadecimal(float floatscanf) {
		scanf("%f", &floatscanf);
	}
	void entradafrase(char* strscanf) {
		scanf("%s", strscanf);
	}