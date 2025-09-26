#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int number = 0;
    char *output = NULL;
    int verbose = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 < argc) {
                number = atoi(argv[i + 1]);
                i++; // SKIPS
            } else {
                printf("Error: -n requires a number\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                output = argv[i + 1];
                i++;  
            } else {
                printf("Error: -o requires a filename\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        }
        else {
            printf("Invalid argument: %s\n", argv[i]);
            return 1;
        }
    }
    if (verbose) {
        printf("Verbose mode ON\n");
    }
    printf("Number: %d\n", number);
    if (output) {
        printf("Output file: %s\n", output);
    } else {
        printf("No output file specified\n");
    }

    return 0;
}
