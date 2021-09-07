#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void bubble_sort(int **a, int n) {
    int *arr = *a;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int curr = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = curr;
        }
    }
}

int convertStringToInt(char *str) {
    int value = 0;
    while (*str != '\0') {
        value = value * 10 + (*str - '0');
        str++;
    }
    return value;
}

int main() {
    // read string
    int arr_len;
    printf("Enter array length: ");
    scanf("%i", &arr_len);
    printf("Waiting for %i elements\n", arr_len);

    int *elements = malloc(arr_len);

    for (int i = 0; i < arr_len; i++) {
        char word[256];
        scanf("%s", word);
        printf("Parsed word '%s'\n", word);
        int number = convertStringToInt(word);
        elements[i] = number;

        if (i != arr_len - 1)
            scanf(" ");
    }
    bubble_sort(&elements, arr_len);
    printf("Elements: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%i ", elements[i]);
    }
    printf("\n");
}
