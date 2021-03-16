#include "Matrix.h"

void mx_print_bits(unsigned int num)
{
    for(int i = 256; i > 0; i = i / 2) {
        if(num & i) 
            printf("1 ");
        else
            printf("0 ");
    }
}


// void mx_print_bits(unsigned int n) {
//    int  result;
//     do
//     {
//         result = ('0' + (n % 2)) + result;
//         n = n / 2;
//     } while (n > 0);
//     return result;
// }