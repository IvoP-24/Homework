#include "math_operations.h"
void checkSymbol(char* argv[],int a,int b){
    int result;
    if(argv[2][0] == '-'){
        subtract(a,b,&result);
    }
    if(argv[2][0] == '+'){ // checking character symbol 
        add(a,b,&result);
    }
    if(argv[2][0] == '*'){
        multiply(a,b,&result);
    }
    if(argv[2][0] == '/'){
        divide(a,b,&result);
    }
    printf("The sum is : %d\n",result);
    
}