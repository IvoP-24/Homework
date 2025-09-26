#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./fileops <operation> ...\n");
        return 1;
    }

    if (strcmp(argv[1], "copy") == 0) {
        if (argc != 4) {
            printf("Usage: ./fileops copy <src> <dst>\n");
            return 1;
        }

        FILE *in = fopen(argv[2], "r");
        if (!in) { printf("Error: Cannot open %s\n", argv[2]); return 1; }

        FILE *out = fopen(argv[3], "w");
        if (!out) { printf("Error: Cannot open %s\n", argv[3]); fclose(in); return 1; }

        int ch;
        while ((ch = fgetc(in)) != EOF) {
            fputc(ch, out);
        }

        printf("Copied %s -> %s\n", argv[2], argv[3]);

        fclose(in);
        fclose(out);
    }
    else if (strcmp(argv[1], "merge") == 0) {
        if (argc < 4) {
            printf("Usage: ./fileops merge <output> <input1> <input2> ...\n");
            return 1;
        }

        FILE *out = fopen(argv[2], "w");
        if (!out) { printf("Error: Cannot open %s\n", argv[2]); return 1; }

        for (int i = 3; i < argc; i++) {
            FILE *in = fopen(argv[i], "r");
            if (!in) { printf("Error: Cannot open %s\n", argv[i]); continue; }

            int ch;
            while ((ch = fgetc(in)) != EOF) {
                fputc(ch, out);
            }

            fclose(in);
        }

        printf("Merged files into %s\n", argv[2]);
        fclose(out);
    }
    else if (strcmp(argv[1], "split") == 0) {
        if (argc != 4) {
            printf("Usage: ./fileops split <input> <size>\n");
            return 1;
        }

        char *input = argv[2];
        int size = atoi(argv[3]);
        if (size <= 0) { printf("Invalid size\n"); return 1; }

        FILE *in = fopen(input, "r");
        if (!in) { printf("Error: Cannot open %s\n", input); return 1; }

        int ch, count = 0, file_num = 1;
        char outname[256];
        FILE *out = NULL;

        while ((ch = fgetc(in)) != EOF) {
            if (count % size == 0) {
                if (out) fclose(out);
                sprintf(outname, "%s_part%d", input, file_num++);
                out = fopen(outname, "w");
                if (!out) { printf("Error: Cannot create %s\n", outname); fclose(in); return 1; }
            }
            fputc(ch, out);
            count++;
        }

        if (out) fclose(out);
        printf("Split %s into %d files of %d bytes\n", input, file_num - 1, size);

        fclose(in);
    }
    else {
        printf("Unknown operation: %s\n", argv[1]);
    }
    return 0;
}
