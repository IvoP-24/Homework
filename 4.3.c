#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <word> <text1> <text2> ...\n", argv[0]);
        return 1;
    }

    char *word = argv[1];
    int wordLen = strlen(word);
    int found = 0;

    for(int i = 2; i < argc; i++) {
        char *text = argv[i];
        int textLen = strlen(text);

        for(int j = 0; j <= textLen - wordLen; j++) {
            int k;
            for(k = 0; k < wordLen; k++) {
                if(tolower(text[j + k]) != tolower(word[k]))
                    break;
            }
            if(k == wordLen) {
                printf("String %d contains '%s'\n", i - 1, word);
                found = 1;
                break;  
            }
        }
    }

    if(found = 0) {
        printf("No strings contain '%s'\n", word);
    }

    return 0;
}
