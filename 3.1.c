#include <stdio.h>
#include <stdlib.h>
#include "math_operations.h"
#include "mathsymbol.h"
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./calc <num1> <operator> <num2>\n");
        return 1;
    }
    int a = atoi(argv[1]); // CONVERTING ARGV POINTERS TO INTEGERS
    int b = atoi(argv[3]);
    checkSymbol(argv,a,b);
    return 0;
}