#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int port = 8080;
    char host[100] = "localhost";
    int debug = 0;

    for (int i = 1; i < argc; i++) {
        if ((strcmp(argv[i], "--port") == 0 || strcmp(argv[i], "-p") == 0)) {  
            if (i + 1 < argc) {
                port = atoi(argv[++i]); 
            } else {
                printf("Error: --port requires a number\n");
                return 1;
            }
        }
        else if ((strcmp(argv[i], "--host") == 0 || strcmp(argv[i], "-h") == 0)) {
            if (i + 1 < argc) {
                strncpy(host, argv[++i], sizeof(host)-1);
                host[sizeof(host)-1] = '\0'; 
            } else {
                printf("Error: --host requires an address\n");
                return 1;
            }
        }
        else if ((strcmp(argv[i], "--debug") == 0 || strcmp(argv[i], "-d") == 0)) {
            debug = 1;
        }
        else {
            printf("Error: Unknown flag %s\n", argv[i]);
            return 1;
        }
    }

    printf("Configuration:\n");
    printf("Default host : %s\n", host);
    printf("Default port : %d\n", port);
    printf("Default debug: %s\n", debug ? "True" : "False");

    return 0;
}
