/*lsferreira programming */

//Include Header
#include "portugal.h"

    void imprimir(char* strputs)
    {
		/* Summary: This function is a translation of puts() 
         * function in stdio.h header
         * It is used to print in screen any string (only command 
         * line) */

        puts(strprint); 
    }
    void caracter(char charputchar)
    {
        /* Summary: This function is a translation of putchar()
         * function in stdio.h header
         * It is used to print in screen any character (only command
         * line) */

        putchar(charputchar);
    }
    void caracterentrada(char chargetchar)
    {
        /* Summary: This function is a translation of getchar()
         * function in stdio.h header
         * It is used to get character */

        getchar(chargetchar);
    }
    void entrada(char* strgets)
    {
        /* Summmary: This function is a translation of gets() 
         * function in stdio.h header
         * It is used to get any string */

        gets(strgets);
    }
    int quociente(int divindendo, int divisor)
    {
        /* Summary: This function is a translation of div() 
         * function in stdio.h header
         * It is used to divid 2 values and return a quotient */

        div_t divresult;
        divresult = div(dividendo, divisor);
        return divresult.quot;
    }
    int resto(int divindendo, int divisor)
    {
        /* Summary: This function is a translation of div() 
         * function in stdio.h header
         * It is used to divid 2 values and return a rest value */

        div_t divresult;
        divresult = div(dividendo, divisor);
        return divresult.rem;
    }
    int quocientelongo(int divindendo, int divisor)
    {
        /* Summary: This function is a translation of ldiv() 
         * function in stdio.h header
         * It is used to divid 2 long type values and return 
         * a quotient */

        ldiv_t ldivresult;
        ldivresult = ldiv(dividendo,divisor);
        return ldivresult.quot;
    }
    int restolongo(int divindendo, int divisor)
    {
        /* Summary: This function is a translation of ldiv() 
         * function in stdio.h header
         * It is used to divid 2 long type values and return 
         * a rest value */

        ldiv_t ldivresult;
        ldivresult = ldiv(dividendo,divisor);
        return ldivresult.rem;
    }
	int fraseparainteiro(char* stratoi) {
        /* Summary: This function is a translation of atoi()
         * function in stdio.h header 
         * It is used to convert any string to a int definition type */

		return atoi(stratoi);
	}
	long int fraseparainteirolongo(char* stratol) {
        /* Summary: This function is a translation of atol()
         * function in stdio.h header 
         * It is used to convert any string to a long int definition type */

		return atol(stratol);
	}
	double fraseparadecimaldouble(char* stratof) {
        /* Summary: This function is a translation of atof()
         * function in stdio.h header 
         * It is used to convert any string to a double definition type */

		return atof(stratof);
	}
	float fraseparadecimalfloat(char* stratof) {
        /* Summary: This function is a translation of atof()
         * function in stdio.h header 
         * It is used to convert any string to a float definition type */

		return atof(stratof);
	}
	void remover(char* strremove) {
        /* Summary: This function is a translation of remove()
         * function in stdio.h header */

		remove(strremove);
	}
	void renomear(char* strold, char* strnew) {
        /* Summary: This function is a translation of renane()
         * function in stdio.h header */

		rename(strold, strnew);
	}
	void entradacaracter(char charscanf) {
        /* Summary: This function is a translation of scanf()
         * function in stdio.h header */

		scanf("%c",&charscanf);
	}
	void entradainteiro(int intscanf) {
        /* Summary: This function is a translation of scanf()
         * function in stdio.h header */

		scanf("%d", &intscanf);
	}
	void entradadecimal(float floatscanf) {
        /* Summary: This function is a translation of scanf()
         * function in stdio.h header */

		scanf("%f", &floatscanf);
	}
	void entradafrase(char* strscanf) {
        /* Summary: This function is a translation of scanf()
         * function in stdio.h header */
        
		scanf("%s", strscanf);
	}