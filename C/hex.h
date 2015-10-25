#ifndef HEX_H_INCLUDED
#define HEX_H_INCLUDED

#include "../lib/libs.hpp"

//Used namespaces
using namespace std;

class crypt
{
public:
    string char2hex( char dec )
    {
        char dig1 = (dec&0xF0)>>4;
        char dig2 = (dec&0x0F);
        if ( 0<= dig1 && dig1<= 9) dig1+=48;    //0,48inascii
        if (10<= dig1 && dig1<=15) dig1+=97-10; //a,97inascii
        if ( 0<= dig2 && dig2<= 9) dig2+=48;
        if (10<= dig2 && dig2<=15) dig2+=97-10;

        string r;
        r.append( &dig1, 1);
        r.append( &dig2, 1);
        return r;
    }
    string bin2hex(const string& s)
    {
        const static char bin2hex_lookup[] = "0123456789abcdef";
        unsigned int t=0,i=0,leng=s.length();
        string r;
        r.reserve(leng*2);
        for(i=0; i<leng; i++)
        {
            r+= bin2hex_lookup[ s[i] >> 4 ];
            r+= bin2hex_lookup[ s[i] & 0x0f ];
        }
        return r;
    }
    string dec2hex(unsigned long long i)
    {
        stringstream ss;
        ss << hex << uppercase << i;
        //ss << hex << lowercase << i;
        //ss << showbase << hex << lowercase << i; //prepends 0x
        //string s; ss >> s; return s; //alternate way to extract string
        return ss.str();
    }

    string dec2hex_c(unsigned int i) //has limit of 32 bit integer
    {
        char s[20];
        sprintf(s, "%X", i);//uppercase
        //sprintf(s, "%x", i);//lowercase
        return string(s);
    }
    unsigned long long hex2dec(const string &input)
    {
        unsigned long long n;
        stringstream ss;
        ss << hex << uppercase << input;
        //ss << hex << lowercase << input;
        ss >> n;
        return n;
    }

    unsigned long long hex2dec_c(const char*s, int length)
    {
        unsigned long long n=0;
        for(int i=0,v=0; i<length && s[i]!='\0'; i++)
        {
            if      ('a' <= s[i] && s[i] <='f')
            {
                v=s[i]-97+10;
            }
            else if ('A' <= s[i] && s[i] <='F')
            {
                v=s[i]-65+10;
            }
            else if ('0' <= s[i] && s[i] <='9')
            {
                v=s[i]-48;
            }
            else break;
            n*=16;
            n+=v;
        }
        return n;
    }
};

#endif // HEX_H_INCLUDED
