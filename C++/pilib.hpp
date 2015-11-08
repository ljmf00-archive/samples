/*lsferreira programming */

/*
                                              _       _
                                             (_)     | |
  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_
 / __|/ _ \| | | | '__/ __/ _ \/ __|/ __| '__| | '_ \| __|
 \__ \ (_) | |_| | | | (_|  __/\__ \ (__| |  | | |_) | |_
 |___/\___/ \__,_|_|  \___\___||___/\___|_|  |_| .__/ \\__|
                                               | |
                                               |_|
*/

#ifndef LSCLIBPILIB_H_INCLUDED
#define LSCLIBPILIB_H_INCLUDED

#if !(_WIN32) //If dont support Windows :: Do Def. Inst.

#endif

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define FPINUMBASE    10000

// ...

class picalc
{
public:
    int nblock;
    int *tot;
    int *t1;
    int *t2;
    int *t3;

    void arctan(int* result, int* w1, int* w2, int denom, int onestep)
    {
        int denom2 = denom*denom;
        int k = 1;
        set(result, 1);
        div(result, denom);
        copy(w1, result);
        do
        {
            if(onestep)
                div(w1, denom2);
            else
            {
                div(w1, denom);
                div(w1, denom);
            }
            copy(w2, w1);
            div(w2, 2*k+1);
            if(k%2)
                sub(result, w2);
            else
                add(result, w2);
            k++;
        }
        while(!zero(w2));
    }
    void pi(int ndigit)
    {
        if(ndigit < 20) ndigit = 20;
        nblock = ndigit/4;
        tot = (int *)malloc(nblock*sizeof(int));
        t1 = (int *)malloc(nblock*sizeof(int));
        t2 = (int *)malloc(nblock*sizeof(int));
        t3 = (int *)malloc(nblock*sizeof(int));
        if(!tot || !t1 || !t2 || !t3)
        {
            fprintf(stderr, "Not enough memory\n");
            exit(1);
        }
        arctan(tot, t1, t2, 5, 1);
        mult(tot, 4);
        arctan(t3, t1, t2, 239, 2);
        sub(tot, t3);
        mult(tot, 4);
        print(tot);
    }


    void copy(int* result, int* from)
    {
        int i;
        for(i=0; i<nblock; i++)
            result[i] = from[i];
    }
    bool zero(int* result)
    {
        int i;
        for(i=0; i<nblock; i++)
            if(result[i])
                return 0;
        return 1;
    }
    void add(int* result, int *increm)
    {
        int i;
        for(i=nblock-1; i>=0; i--)
        {
            result[i] += increm[i];
            if(result[i] >= FPINUMBASE)
            {
                result[i] -= FPINUMBASE;
                result[i-1]++;
            }
        }
    }
    void sub(int* result, int* decrem)
    {
        int i;
        for(i=nblock-1; i>=0; i--)
        {
            result[i] -= decrem[i];

            if(result[i] < 0)
            {
                result[i] += FPINUMBASE;
                result[i-1]--;
            }
        }
    }
    void mult(int* result, int factor)
    {
        int i, carry = 0;
        for(i=nblock-1; i>=0; i--)
        {
            result[i] *= factor;
            result[i] += carry;
            carry = result[i]/FPINUMBASE;
            result[i] %= FPINUMBASE;
        }
    }
    void print(int* result)
    {
        int i, k;
        char s[10];
        printf("%1d.\n", result[0]);
        for(i=1; i<nblock; i++)
        {
            sprintf(s, "%4d ", result[i]);
            for(k=0; k<5; k++)
                if(s[k] == ' ') s[k] = '0';
            printf("%c%c%c%c", s[0], s[1], s[2], s[3]);
            if(i%15 == 0) printf("\n");
        }
        printf("\n");
    }
    void set(int* result, int rhs)
    {
        int i;
        for(i=0; i<nblock; i++)
            result[i] = 0;
        result[0] = rhs;
    }
    void div(int* result, int denom)
    {
        int i, carry = 0;
        for(i=0; i<nblock; i++)
        {
            result[i] += carry*FPINUMBASE;
            carry = result[i] % denom;
            result[i] /= denom;
        }
    }
};

#endif // LSCLIBPILIB_H_INCLUDED
