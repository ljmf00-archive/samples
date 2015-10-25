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

#ifndef STDPRINT_HPP_INCLUDED
#define STDPRINT_HPP_INCLUDED

#if !(WIN32) //If dont support Windows :: Do Def. Inst.

#endif
#if !(WIN64) //! win64

#endif

#include "libs.hpp"

using namespace std;
// ...

class printing
{
public:
    void slprint(char olavo[])
    {
        int i,cont=60;
        for (i = 0; olavo[i] != '\0'; i++)
        {
            printf("%c",olavo[i]);
            Sleep(25);
            fflush(stdin);
        }
    }
};




#endif // STDPRINT_HPP_INCLUDED
