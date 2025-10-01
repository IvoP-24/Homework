#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "modifystring.h"

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <op> <string>\n", argv[0]);
        return 1;
    }
    char *op = argv[1];
    if(strcmp(op, "upper") == 0) {
        upper(argc,argv);
    }
    else if(strcmp(op, "lower") == 0) {
        lower(argc,argv);
    }
    else if(strcmp(op, "reverse") == 0) {
        reverse(argc,argv);
    }
    else if(strcmp(op, "concat") == 0) {
        concat(argc,argv);
    }
    else {
        printf("Usage: %s <op> <string>\n", argv[0]);
        return 1;
    }
    return 0;
}

