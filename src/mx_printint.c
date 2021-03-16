#include "Matrix.h"

void mx_printint(int n) {
    if (n == -2147483648) {
        mx_printchar('-');
        mx_printchar('2');
        mx_printint(147483648);
    }
    else if (n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    if (n > 9) {
        mx_printint(n / 10);
        mx_printint(n % 10);
    }
    else
        mx_printchar(n + 48);
}
