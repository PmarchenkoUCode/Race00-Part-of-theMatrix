#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_operation(int num1, int num2, char operation);
int mx_atoi(const char *str);
int mx_strlen(const char *s);
char *mx_spaceout(char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strndup(const char *str, int len);
char *mx_strnew(const int size);
bool mx_isspace(int c);
bool mx_isdigit(int c);
char *mx_outspace(char *s);
char mx_cutspace(char *s);
void mx_print_unicode(wchar_t c);
double mx_pow(double n, unsigned int pow);
void mx_print_bits(unsigned int num);

#endif
