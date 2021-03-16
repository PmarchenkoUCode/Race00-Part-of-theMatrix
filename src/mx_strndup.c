#include "Matrix.h"

char *mx_strndup(const char *str, int len) {
    char *duplicate;

    duplicate = (mx_strnew(len + 1));
    mx_strcpy(duplicate, str);
    return duplicate;
}
