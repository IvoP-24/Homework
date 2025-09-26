#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <op> <string>\n", argv[0]);
        return 1;
    }
    char *op = argv[1];

    if(strcmp(op, "upper") == 0) {
        for(int i = 2; i < argc; i++) {
            for(int j = 0; argv[i][j]; j++) {
                argv[i][j] = toupper(argv[i][j]);
            }
            printf("%s\n", argv[i]);
        }
    }
    else if(strcmp(op, "lower") == 0) {
        for(int i = 2; i < argc; i++) {
            for(int j = 0; argv[i][j]; j++) {
                argv[i][j] = tolower(argv[i][j]);
            }
            printf("%s\n", argv[i]);
        }
    }
    else if(strcmp(op, "reverse") == 0) {
        for(int i = 2; i < argc; i++) {
            int len = strlen(argv[i]);
            for(int j = len - 1; j >= 0; j--) {
                printf("%c", argv[i][j]);
            }
            printf("\n");
        }
    }
    else if(strcmp(op, "concat") == 0) {
        for(int i = 2; i < argc; i++) {
            printf("%s", argv[i]);
        }
        printf("\n");
    }
    else {
        printf("Usage: %s <op> <string>\n", argv[0]);
        return 1;
    }

    return 0;
}
