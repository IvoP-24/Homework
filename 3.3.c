#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number> <from_base> <to_base>\n", argv[0]);
        return 1;
    }

    char *number = argv[1];
    int from_base = atoi(argv[2]);
    int to_base = atoi(argv[3]);

    if ((from_base != 2 && from_base != 8 && from_base != 10 && from_base != 16) ||
        (to_base != 2 && to_base != 8 && to_base != 10 && to_base != 16)) {
        printf("Error: Supported bases are 2, 8, 10, 16\n");
        return 1;
    }

    char *endptr;
    long value = strtol(number, &endptr, from_base);

    if (*endptr != '\0') {
        printf("Error: Invalid number '%s' for base %d\n", number, from_base);
        return 1;
    }

    if (to_base == 2) {

        long mask = 1;
        int bits = 0;
        for (long temp = value; temp > 0; temp >>= 1) bits++;
        if (bits == 0) bits = 1;
        for (int i = bits - 1; i >= 0; i--) {
            printf("%ld", (value >> i) & 1);
        }
        printf("\n");
    } else if (to_base == 8) {
        printf("%lo\n", value);
    } else if (to_base == 10) {
        printf("%ld\n", value);
    } else if (to_base == 16) {
        printf("%lX\n", value);  
    }
}

