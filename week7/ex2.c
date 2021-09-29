#include <stdio.h>
#include <malloc.h>

int main() {
    printf("Hello, print the number of array entities: \n");
    printf("Thank you!\n");
    int n;
    scanf("%d", &n);
    int * a= malloc(n* sizeof(int));
    for(int i=0; i<n;i++){
        a[i]=i;
    }
    for(int i=n-1; i>=0; i--){
        int* b=&a[i];
        printf("#%d\t element :\t %d\n", i, a[i]);
        realloc(a, i* sizeof(int));
    }
    return 0;
}
