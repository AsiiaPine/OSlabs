#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
    int integer = INT_MAX;
    float flt = FLT_MAX;
    double dbl = DBL_MAX;
    printf("Size of integer: %lu, MAX int value: %d\n Size of float: %lu, MAX float value: %f\n Size of double: %lu, MAX double value: %f\n", sizeof(integer), integer,sizeof(flt), flt, sizeof(dbl), dbl);
    return 0;
}