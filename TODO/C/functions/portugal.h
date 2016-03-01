/*lsferreira programming */
#ifndef PORTUGAL_H_INCLUDED
#define PORTUGAL_H_INCLUDED

//Include Libraries
#include <stdio.h>

    void imprimir(char* strputs); //puts()
    void caracter(char charputchar); //putchar()
    void caracterentrada(char chargetchar); //getchar()
    void entrada(char* strgets); //gets()
    int quociente(int divindendo, int divisor); //div()
    int resto(int divindendo, int divisor); // "
    int quocientelongo(int divindendo, int divisor); //ldiv()
    int restolongo(int divindendo, int divisor); // "
	int fraseparainteiro(char* stratoi); //atoi()
	long int fraseparainteirolongo(char* stratol); //atol()
	double fraseparadecimaldouble(char* stratof); //atof()
	float fraseparadecimalfloat(char* stratof); // "
	void remover(char* strremove); // remove()
	void renomear(char* strold, char* strnew); // rename()
	void entradacaracter(char charscanf); // scanf()
	void entradainteiro(int intscanf); // "
	void entradadecimal(float floatscanf); // "
	void entradafrase(char* strscanf); // "

#endif // PORTUGAL_H_INCLUDED
