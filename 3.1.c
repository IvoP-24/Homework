#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./calc <num1> <operator> <num2>\n");
        return 1;
    }
    int a = atoi(argv[1]); // CONVERTING ARGV POINTERS TO INTEGERS
    int b = atoi(argv[3]);
    int sum;
    char symbol = argv[2][0];
    if(argv[2][0] == '-'){
        sum = a - b; 
    }
    if(argv[2][0] == '+'){ // checking character symbol 
        sum = a + b;
    }
    if(argv[2][0] =='*'){
        sum = a * b;
    }
    if(argv[2][0] == '/'){
        sum = a / b;
    }
    printf("The sum is : %d\n",sum);
    
    return 0;
}