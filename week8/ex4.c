#include <malloc.h>
#include <unistd.h>
#include <sys/resource.h>
int n=10*1024*1024;
int t=0;
void main(){
    while(t!=10) {
        char *a = malloc(n);
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
        sleep(1);
        t++;
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage );
        printf("max resident set size:\t%ld\n", usage.ru_maxrss);
    }
}
