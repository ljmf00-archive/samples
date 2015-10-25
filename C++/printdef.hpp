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

#ifndef LSCLIBPRINTDEF_H_INCLUDED
#define LSCLIBPRINTDEF_H_INCLUDED

#define UNIXCOLORB_BLACK "tput setab 0"
#define UNIXCOLORB_RED "tput setab 1"
#define UNIXCOLORB_GREEN "tput setab 2"
#define UNIXCOLORB_YELLOW "tput setab 3"
#define UNIXCOLORB_BLUE "tput setab 4"
#define UNIXCOLORB_MAGENTA "tput setab 5"
#define UNIXCOLORB_CYAN "tput setab 6"
#define UNIXCOLORB_WHITE "tput setab 7"

#define UNIXCOLORF_BLACK "tput setaf 0"
#define UNIXCOLORF_RED "tput setaf 1"
#define UNIXCOLORF_GREEN "tput setaf 2"
#define UNIXCOLORF_YELLOW "tput setaf 3"
#define UNIXCOLORF_BLUE "tput setaf 4"
#define UNIXCOLORF_MAGENTA "tput setaf 5"
#define UNIXCOLORF_CYAN "tput setaf 6"
#define UNIXCOLORF_WHITE "tput setaf 7"

#define UNIXPRINT_BOLD "tput bold"
#define UNIXPRINTS_UNDERLINE "tput smul"
#define UNIXPRINTR_UNDERLINE "tput rmul"
#define UNIXPRINTS_STANDOUT "tput smso"
#define UNIXPRINTR_STANDOUT "tput rmso"
#define UNIXPRINT_BLINK "tput blink"
#define UNIXPRINT_INVISIBLE "tput invis"
#define UNIXPRINT_REVERSE "tput rev"
#define UNIXPRINT_RESET "tput sgr0"

#define UNIXCURSOR_SAVE "tput sc"
#define UNIXCURSOR_RESTORE "tput rc"
#define UNIXCURSOR_HOME "tput home"
#define UNIXCURSOR_CUP "tput cup " //tput cup x y (x=row; y=col)
#define UNIXCURSOR_DOWN "tput cud1"
#define UNIXCURSOR_UP "tput cuU1"
#define UNIXCURSOR_INVISIBLE "tput civis"
#define UNIXCURSOR_NORMAL "tput cnorm"

#define UNIXSCREEN_SAVE "tput smcup"
#define UNIXSCREEN_RESTORE "tput rmcup"
#define UNIXSCREEN_CLEAR "tput clear"
#define UNIXSCREEN_CLEAR_ENDLINE "tput el"
#define UNIXSCREEN_CLEAR_BEGINNINGLINE "tput el1"
#define UNIXSCREEN_CLEAR_ENDSCREEN "tput ed"

class wincolor
{
public:
    const char WINSYSCOLOR_BLACKBLACK[3] = "00";
    const char WINSYSCOLOR_BLACKBLUE[3] = "01";
    const char WINSYSCOLOR_BLACKGREEN[3] = "02";
    const char WINSYSCOLOR_BLACKAQUA[3] = "03";
    const char WINSYSCOLOR_BLACKRED[3] = "04";
    const char WINSYSCOLOR_BLACKPURPLE[3] = "05";
    const char WINSYSCOLOR_BLACKYELLOW[3] = "06";
    const char WINSYSCOLOR_BLACKWHITE[3] = "07";
    const char WINSYSCOLOR_BLACKGRAY[3] = "08";
    const char WINSYSCOLOR_BLACKLIGHTBLUE[3] = "09";
    const char WINSYSCOLOR_BLACKLIGHTGREEN[3] = "0A";
    const char WINSYSCOLOR_BLACKLIGHTAQUA[3] = "0B";
    const char WINSYSCOLOR_BLACKLIGHTRED[3] = "0C";
    const char WINSYSCOLOR_BLACKLIGHTPURPLE[3] = "0D";
    const char WINSYSCOLOR_BLACKLIGHTYELLOW[3] = "0E";
    const char WINSYSCOLOR_BLACKLIGHTWHITE[3] = "0F";

    const char WINSYSCOLOR_BLUEBLACK[3] = "10";
    const char WINSYSCOLOR_BLUEBLUE[3] = "11";
    const char WINSYSCOLOR_BLUEGREEN[3] = "12";
    const char WINSYSCOLOR_BLUEAQUA[3] = "13";
    const char WINSYSCOLOR_BLUERED[3] = "14";
    const char WINSYSCOLOR_BLUEPURPLE[3] = "15";
    const char WINSYSCOLOR_BLUEYELLOW[3] = "16";
    const char WINSYSCOLOR_BLUEWHITE[3] = "17";
    const char WINSYSCOLOR_BLUEGRAY[3] = "18";
    const char WINSYSCOLOR_BLUELIGHTBLUE[3] = "19";
    const char WINSYSCOLOR_BLUELIGHTGREEN[3] = "1A";
    const char WINSYSCOLOR_BLUELIGHTAQUA[3] = "1B";
    const char WINSYSCOLOR_BLUELIGHTRED[3] = "1C";
    const char WINSYSCOLOR_BLUELIGHTPURPLE[3] = "1D";
    const char WINSYSCOLOR_BLUELIGHTYELLOW[3] = "1E";
    const char WINSYSCOLOR_BLUELIGHTWHITE[3] = "1F";

    const char WINSYSCOLOR_GREENBLACK[3] = "20";
    const char WINSYSCOLOR_GREENBLUE[3] = "21";
    const char WINSYSCOLOR_GREENGREEN[3] = "22";
    const char WINSYSCOLOR_GREENAQUA[3] = "23";
    const char WINSYSCOLOR_GREENRED[3] = "24";
    const char WINSYSCOLOR_GREENPURPLE[3] = "25";
    const char WINSYSCOLOR_GREENYELLOW[3] = "26";
    const char WINSYSCOLOR_GREENWHITE[3] = "27";
    const char WINSYSCOLOR_GREENGRAY[3] = "28";
    const char WINSYSCOLOR_GREENLIGHTBLUE[3] = "29";
    const char WINSYSCOLOR_GREENLIGHTGREEN[3] = "2A";
    const char WINSYSCOLOR_GREENLIGHTAQUA[3] = "2B";
    const char WINSYSCOLOR_GREENLIGHTRED[3] = "2C";
    const char WINSYSCOLOR_GREENLIGHTPURPLE[3] = "2D";
    const char WINSYSCOLOR_GREENLIGHTYELLOW[3] = "2E";
    const char WINSYSCOLOR_GREENLIGHTWHITE[3] = "2F";

    const char WINSYSCOLOR_AQUABLACK[3] = "30";
    const char WINSYSCOLOR_AQUABLUE[3] = "31";
    const char WINSYSCOLOR_AQUAGREEN[3] = "32";
    const char WINSYSCOLOR_AQUAAQUA[3] = "33";
    const char WINSYSCOLOR_AQUARED[3] = "34";
    const char WINSYSCOLOR_AQUAPURPLE[3] = "35";
    const char WINSYSCOLOR_AQUAYELLOW[3] = "36";
    const char WINSYSCOLOR_AQUAWHITE[3] = "37";
    const char WINSYSCOLOR_AQUAGRAY[3] = "38";
    const char WINSYSCOLOR_AQUALIGHTBLUE[3] = "39";
    const char WINSYSCOLOR_AQUALIGHTGREEN[3] = "3A";
    const char WINSYSCOLOR_AQUALIGHTAQUA[3] = "3B";
    const char WINSYSCOLOR_AQUALIGHTRED[3] = "3C";
    const char WINSYSCOLOR_AQUALIGHTPURPLE[3] = "3D";
    const char WINSYSCOLOR_AQUALIGHTYELLOW[3] = "3E";
    const char WINSYSCOLOR_AQUALIGHTWHITE[3] = "3F";

    const char WINSYSCOLOR_REDBLACK[3] = "40";
    const char WINSYSCOLOR_REDBLUE[3] = "41";
    const char WINSYSCOLOR_REDGREEN[3] = "42";
    const char WINSYSCOLOR_REDAQUA[3] = "43";
    const char WINSYSCOLOR_REDRED[3] = "44";
    const char WINSYSCOLOR_REDPURPLE[3] = "45";
    const char WINSYSCOLOR_REDYELLOW[3] = "46";
    const char WINSYSCOLOR_REDWHITE[3] = "47";
    const char WINSYSCOLOR_REDGRAY[3] = "48";
    const char WINSYSCOLOR_REDLIGHTBLUE[3] = "49";
    const char WINSYSCOLOR_REDLIGHTGREEN[3] = "4A";
    const char WINSYSCOLOR_REDLIGHTAQUA[3] = "4B";
    const char WINSYSCOLOR_REDLIGHTRED[3] = "4C";
    const char WINSYSCOLOR_REDLIGHTPURPLE[3] = "4D";
    const char WINSYSCOLOR_REDLIGHTYELLOW[3] = "4E";
    const char WINSYSCOLOR_REDLIGHTWHITE[3] = "4F";
};


#endif // LSCLIBPRINTDEF_H_INCLUDED
