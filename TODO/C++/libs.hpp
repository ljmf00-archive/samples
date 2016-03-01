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

#ifndef LSCLIBLIBS_H_INCLUDED
#define LSCLIBLIBS_H_INCLUDED
//OPERATION SYSTEM DETECTION
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include <tchar.h>
#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
#elif TARGET_OS_IPHONE
#elif TARGET_OS_MAC
#else
#endif
#elif __linux
#elif __unix__
#elif __posix
#endif
//GENERAL LIBRARY
#include <cstdlib>
#include <string>
#include <iostream>
#include <ciso646>
#include <cassert>
#include <cmath>
#include <clocale>
#include <unistd.h>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#endif // LSCLIBLIBS_H_INCLUDED
