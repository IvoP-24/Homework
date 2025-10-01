#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modifystring.h"
#include <ctype.h>
void upper(int argc, char *argv[]){

    for(int i = 2; i < argc; i++) {
        for(int j = 0; argv[i][j]; j++) {
            argv[i][j] = toupper(argv[i][j]);
        }
        printf("%s\n", argv[i]);
    }
}
void lower(int argc, char *argv[]){
for(int i = 2; i < argc; i++) {
    for(int j = 0; argv[i][j]; j++) {
        argv[i][j] = tolower(argv[i][j]);
    }
    printf("%s\n", argv[i]);
    }
}
void reverse(int argc, char *argv[]){
for(int i = 2; i < argc; i++) {
    int len = strlen(argv[i]);
    for(int j = len - 1; j >= 0; j--) {
        printf("%c", argv[i][j]);
    }
    printf("\n");
    }
}
void concat(int argc, char *argv[]){
for(int i = 2; i < argc; i++) {
    printf("%s", argv[i]);
}
printf("\n");
}