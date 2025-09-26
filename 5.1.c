#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int verbose = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printf("Usage: %s <-v> for verbose or <-h> for help <args>\n", argv[0]);
            return 0;
        }
        else {
            if (verbose) {
                printf("Processing argument: %s\n", argv[i]);
            }
            else {
                printf("%s\n", argv[i]);
            }
        }
    }
    if (verbose) {
        printf("Verbose mode is enabled.\n");
    }

    return 0;
}
