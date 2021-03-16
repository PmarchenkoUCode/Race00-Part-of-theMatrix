#include "Matrix.h"

static void mx_print_res(char *a, char *b, char *r, char op) {
    int val1 = mx_atoi(a);
    int val2 = mx_atoi(b);
    int res = mx_atoi(r);


    if (op == '/' && !val2)
        return ;
    if (mx_operation(val1, val2, op) == res) {
        mx_printint(val1);
        mx_printchar(' ');
        mx_printchar(op);
        mx_printchar(' ');
        mx_printint(val2);
        mx_printstr(" = ");
        mx_printint(res);
        mx_printchar('\n');
    }
}

static void mx_matrix_sec(char *a, char *b, char *r, char op) {
    for (int i = 0; i < mx_strlen(b); ++i)
        if (b[i] == '?') {
            for (int j = 48; j < 58; ++j) {
                b[i] = j;
                mx_matrix_sec(a, b, r, op);
                b[i] = '?';
            }
            return ;
        }
    for (int i = 0; i < mx_strlen(r); ++i)
        if (r[i] == '?') {
            for (int j = 48; j < 58; ++j) {
                r[i] = j;
                mx_matrix_sec(a, b, r, op);
                r[i] = '?';
            }
            return ;
        }
    mx_print_res(a, b, r, op);
}

static void mx_matrix(char *a, char *b, char *r, char op) {
    if (op == '?') {
        mx_matrix(a, b, r, '+');
        mx_matrix(a, b, r, '-');
        mx_matrix(a, b, r, '*');
        mx_matrix(a, b, r, '/');
        return ;
    }
    for (int i = 0; i < mx_strlen(a); ++i)
        if (a[i] == '?') {
            for (int j = 48; j < 58; ++j) {
                a[i] = j;
                mx_matrix(a, b, r, op);
                a[i] = '?';
            }
            return ;
        }
    mx_matrix_sec(a, b, r, op);
}

static void print_err(int code, char *s) {
    if (code == 1) {
        write(2, "usage: ./part_of_the_matrix [operand1]", 38);
        write(2, " [operation] [operand2] [result]\n", 33);
    }
    else {
        if (code == 2)
            write(2, "Invalid operand: ", 17);
        else if (code == 3)
            write(2, "Invalid operation: ", 19);
        else
            write(2, "Invalid result: ", 16);
        write(2, s, mx_strlen(s));
        write(2, "\n", 1);
    }
    exit(1);
}

int main(int ac, char **av)
{
    if (ac != 5)
        print_err(1, 0);
    char *a = mx_spaceout(av[1]);    
    char *b = mx_spaceout(av[3]);
    char *r = mx_spaceout(av[4]);
    char op = mx_cutspace(av[2]);
    
    if (!op)
        print_err(3, av[2]);
    if (!a)
        print_err(2, av[1]);
    if (!b)
        print_err(2, av[3]);
    if (!r)
        print_err(4, av[4]);
    mx_matrix(a, b, r, op);
    return 0;
}
