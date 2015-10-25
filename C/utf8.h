#ifndef UTF8_H_INCLUDED
#define UTF8_H_INCLUDED

#include "../lib/libs.hpp"

class crypt
{
public:
    int codepoint(const string &u)
    {
        int l = u.length();
        if (l<1) return -1;
        unsigned char u0 = u[0];
        if (u0>=0   && u0<=127) return u0;
        if (l<2) return -1;
        unsigned char u1 = u[1];
        if (u0>=192 && u0<=223) return (u0-192)*64 + (u1-128);
        if (u[0]==0xed && (u[1] & 0xa0) == 0xa0) return -1; //code points, 0xd800 to 0xdfff
        if (l<3) return -1;
        unsigned char u2 = u[2];
        if (u0>=224 && u0<=239) return (u0-224)*4096 + (u1-128)*64 + (u2-128);
        if (l<4) return -1;
        unsigned char u3 = u[3];
        if (u0>=240 && u0<=247) return (u0-240)*262144 + (u1-128)*4096 + (u2-128)*64 + (u3-128);
        return -1;
    }

    string codepointhex(const string &u)
    {
        stringstream ss;
        string s;
        ss << showbase << hex << codepoint(u);
        ss >> s;
        return s;
    }


    string utf8chr(int cp)
    {
        char c[5]= { 0x00,0x00,0x00,0x00,0x00 };
        if     (cp<=0x7F)
        {
            c[0] = cp;
        }
        else if(cp<=0x7FF)
        {
            c[0] = (cp>>6)+192;
            c[1] = (cp&63)+128;
        }
        else if(0xd800<=cp && cp<=0xdfff) {} //invalid block of utf8
        else if(cp<=0xFFFF)
        {
            c[0] = (cp>>12)+224;
            c[1]= ((cp>>6)&63)+128;
            c[2]=(cp&63)+128;
        }
        else if(cp<=0x10FFFF)
        {
            c[0] = (cp>>18)+240;
            c[1] = ((cp>>12)&63)+128;
            c[2] = ((cp>>6)&63)+128;
            c[3]=(cp&63)+128;
        }
        return string(c);
    }
    bool utf8_check_is_valid(const string& string)
    {
        int c,i,ix,n,j;
        for (i=0, ix=string.length(); i < ix; i++)
        {
            c = (unsigned char) string[i];
            //if (c==0x09 || c==0x0a || c==0x0d || (0x20 <= c && c <= 0x7e) ) n = 0; // is_printable_ascii
            if (0x00 <= c && c <= 0x7f) n=0; // 0bbbbbbb
            else if ((c & 0xE0) == 0xC0) n=1; // 110bbbbb
            else if ( c==0xed && i<(ix-1) && ((unsigned char)string[i+1] & 0xa0)==0xa0) return false; //U+d800 to U+dfff
            else if ((c & 0xF0) == 0xE0) n=2; // 1110bbbb
            else if ((c & 0xF8) == 0xF0) n=3; // 11110bbb
            //else if (($c & 0xFC) == 0xF8) n=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
            //else if (($c & 0xFE) == 0xFC) n=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
            else return false;
            for (j=0; j<n && i<ix; j++)   // n bytes matching 10bbbbbb follow ?
            {
                if ((++i == ix) || (( (unsigned char)string[i] & 0xC0) != 0x80))
                    return false;
            }
        }
        return true;
    }
    int utf8_strlen(const string& str)
    {
        int c,i,ix,q;
        for (q=0, i=0, ix=str.length(); i < ix; i++, q++)
        {
            c = (unsigned char) str[i];
            if      (c>=0   && c<=127) i+=0;
            else if ((c & 0xE0) == 0xC0) i+=1;
            else if ((c & 0xF0) == 0xE0) i+=2;
            else if ((c & 0xF8) == 0xF0) i+=3;
            //else if (($c & 0xFC) == 0xF8) i+=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
            //else if (($c & 0xFE) == 0xFC) i+=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
            else return 0;//invalid utf8
        }
        return q;
    }
    string utf8_substr(const string& str, unsigned int start, unsigned int leng)
    {
        if (leng==0)
        {
            return "";
        }
        unsigned int c, i, ix, q, min=string::npos, max=string::npos;
        for (q=0, i=0, ix=str.length(); i < ix; i++, q++)
        {
            if (q==start)
            {
                min=i;
            }
            if (q<=start+leng || leng==string::npos)
            {
                max=i;
            }

            c = (unsigned char) str[i];
            if      (c>=0   && c<=127) i+=0;
            else if ((c & 0xE0) == 0xC0) i+=1;
            else if ((c & 0xF0) == 0xE0) i+=2;
            else if ((c & 0xF8) == 0xF0) i+=3;
            //else if (($c & 0xFC) == 0xF8) i+=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
            //else if (($c & 0xFE) == 0xFC) i+=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
            else return "";//invalid utf8
        }
        if (q<=start+leng || leng==string::npos)
        {
            max=i;
        }
        if (min==string::npos || max==string::npos)
        {
            return "";
        }
        return str.substr(min,max);
    }
};

#endif // UTF8_H_INCLUDED
