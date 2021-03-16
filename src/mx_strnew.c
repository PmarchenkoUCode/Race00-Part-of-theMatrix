#include "Matrix.h"

char *mx_strnew(const int size) {
    char *str;

    if (!(str = (char *)malloc(sizeof(char) * size + 1)))
        return (NULL);
    int i = 0;

    while (i < size + 1)
        str[i++] = '\0';
    return (str);
}
