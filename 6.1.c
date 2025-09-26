#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("Error: Could not open file %s\n", argv[i]);
            continue;  
        }

        printf("=== %s ===\n", argv[i]);

        int ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
        printf("\n");
        fclose(fp);
    }
    return 0;
}
