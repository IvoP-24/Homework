#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [-i] <word> <files...>\n", argv[0]);
        return 1;
    }

    int case_insensitive = 0;
    int arg_index = 1;

    if (strcmp(argv[1], "-i") == 0) {
        case_insensitive = 1;
        arg_index++;
    }

    if (arg_index >= argc - 1) {
        printf("Error: Missing search word or files\n");
        return 1;
    }

    char *word = argv[arg_index++];

    for (int i = arg_index; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (!file) {
            printf("Error: Could not open file %s\n", argv[i]);
            continue;
        }

        char line[1024];
        int line_number = 0;

        while (fgets(line, sizeof(line), file)) {
            line_number++;

            int found = 0;

            if (case_insensitive) {
                for (int j = 0; line[j] != '\0'; j++) {
                    int k = 0;
                    while (word[k] && line[j + k] &&
                           tolower(line[j + k]) == tolower(word[k])) {
                        k++;
                    }
                    if (word[k] == '\0') {
                        found = 1;
                        break;
                    }
                }
            } else {
                if (strstr(line, word) != NULL) {
                    found = 1;
                }
            }

            if (found) {
                printf("%s:%d:%s", argv[i], line_number, line);
            }
        }

        fclose(file);
    }

    return 0;
}
