#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int verbose = 0;
    int number = 0;
    char *files[300];  
    int file_count = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        }
        else if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 < argc) {
                number = atoi(argv[++i]); // consume next argument
            } else {
                printf("Error: requires a number\n");
                return 1;
            }
        }
        else if (argv[i][0] == '-') {
            printf("Error: Unknown flag %s\n", argv[i]);
            return 1;
        }
        else {
            files[file_count++] = argv[i];
        }
    }
    printf("Verbose: %s\n", verbose ? "True" : "False");
    printf("Number: %d\n", number);
    printf("Files:\n");
    for (int j = 0; j < file_count; j++) {
        printf("%s\n", files[j]);
    }
    return 0;
}
