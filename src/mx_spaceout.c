#include "Matrix.h"

char mx_cutspace(char *s) {
    int i = 0;
    char symb;

    while (mx_isspace(s[i]))
        i++;
    symb = s[i++];
    while (mx_isspace(s[i]))
        i++;
    if ((symb != '+' && symb != '-' && symb != '/' &&
                symb != '*' && symb != '?') || s[i])
        return 0;
    return symb;
}

char *mx_spaceout(char *s) {
    int i;
    int c = 0;

    while (mx_isspace(s[c]))
        c++;
    for (i = c; i < mx_strlen(s); i++) {
        if (s[i] == '-' || s[i] == '+')
            i++;
        while (mx_isdigit(s[i]) || s[i] == '?') 
            i++;
        int tmp = i;
        while (mx_isspace(s[tmp]))
            tmp++;
        if (s[tmp])
             return 0;
    }
    return mx_strndup(s + c, i - c);
}
