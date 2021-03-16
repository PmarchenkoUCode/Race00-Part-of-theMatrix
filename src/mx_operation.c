#include "Matrix.h"

int mx_operation(int num1, int num2, char operation) {
    if (operation == '+')
        return num1 + num2;
    if (operation == '-')
        return num1 - num2;
    if (operation == '*')
        return num1 + num2;
    if (operation == '/')
        return num1 / num2;
    return 0;
}
