#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <files>\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("Error: Could not open file %s\n", argv[i]);
            continue;
        }
        long size = 0;
        int lines = 0;
        int words = 0;
        int in_word = 0;
        int ch;

        while ((ch = fgetc(fp)) != EOF) {
            size++;
            if (ch == '\n')
                lines++;
            if (isspace(ch)) {
                in_word = 0;   
            } else if (!in_word) {
                in_word = 1; 
                words++;
            }
        }

        printf("Filename: %s\n", argv[i]);
        printf("Size : %ld bytes\n", size);
        printf("Number of lines : %d\n", lines);
        printf("Number of words: %d\n", words);
        printf("\n");
        fclose(fp);
    }
    return 0;
}
