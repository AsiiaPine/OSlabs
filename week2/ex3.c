#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int myPowOfTwo(int *n) {
    int i; /* Variable used in loop counter */
    int number = 1;

    for (i = 0; i < *n; ++i)
        number *= 2;

    return (number);
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int n = atoi(argv[1]); //reads the number of rows
        int l = 1; //counts the number of stars in the row
        for (int i = 0; i < n; i++) {
            int k = l;

            for (int j = 0; j < n - i - 1; j++) {
                printf(" ");
            }
            if (i == 0) printf("*");
            else
                for (k; k > 0; k--)
                    printf("*");
            for (int j = 0; j < n - i - 1; j++) {
                printf(" ");
            }
            l = l + 2;
            printf("\n");
        }
    } else printf("Not the right format");
    return 0;
}
