#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int i;
    int num;
    int sum = 0;
    int count = 0;
    int max;
    int min;
    for(i = 1; i < argc; i++){
        if(isdigit(argv[i][0]) ){ // Checking if it's a number
            num = atoi(argv[i]);
            sum = sum + atoi(argv[i]);  // Summing each real number
                 if (count == 0) {
                    min = max = num;
            }   else {
                    if (num < min) min = num;
                    if (num > max) max = num;
            }
            count++;
        }
        else{
            printf("Not a number %s\n",argv[i]);
            }
        
    }
     if (count > 0) {
        printf("Min: %d\nMax: %d\nAverage: %.2f\n", min, max, (double)sum / count);
        printf("The sum is : %d\n",sum);
     }

    return 0;
}