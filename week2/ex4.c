#include <stdio.h>
#include <limits.h>
#include <float.h>
void swap( int *a, int *b){
    int p=*a;
    *a=*b;
    *b=p;
}
int main(){
    int a;
    int b;
    printf("Enter the first value A:\n");
    scanf("%d", &a);
    printf("Enter the second value B: \n");
    scanf("%d", &b);
    swap(&a,&b);
    printf("A: %d\n", a);
    printf("B: %d", b);
    return 0;
}
