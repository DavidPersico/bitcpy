#include "bitcpy.h"
#include <stdio.h>

void print_result(char* result, int length)
{
    printf("\nCopied array is ");
    for (int i = 0; i < length; i++)
        printf("%d ", result[i]);
}

/* Testing, using char (Single byte) array with numbers to avoid headaches. */
int main() 
{
    char source[] = { 11, 27, 35, 42, 53 };
    char dest[] = { 0, 0, 0, 0, 0 };

    print_result(bitcpy(dest, source, 0), 5);
    print_result(bitcpy(dest, source, 1), 5);
    print_result(bitcpy(dest, source, 2), 5);
    print_result(bitcpy(dest, source, 4), 5);
    print_result(bitcpy(dest, source, 8), 5);

    print_result(bitcpy(dest, source, 9), 5);
    print_result(bitcpy(dest, source, 10), 5);
    print_result(bitcpy(dest, source, 11), 5);
    print_result(bitcpy(dest, source, 12), 5);
    print_result(bitcpy(dest, source, 16), 5);

    print_result(bitcpy(dest, source, 17), 5);
    print_result(bitcpy(dest, source, 18), 5);
    print_result(bitcpy(dest, source, 19), 5);
    print_result(bitcpy(dest, source, 24), 5);

    print_result(bitcpy(dest, source, 25), 5);
    print_result(bitcpy(dest, source, 26), 5);
    print_result(bitcpy(dest, source, 28), 5);
    print_result(bitcpy(dest, source, 30), 5);

    print_result(bitcpy(dest, source, 33), 5);
    print_result(bitcpy(dest, source, 36), 5);
    print_result(bitcpy(dest, source, 37), 5);
    print_result(bitcpy(dest, source, 40), 5);
    
    return 0;
}
