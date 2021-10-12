#include <malloc.h>
#include <unistd.h>

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
    }

// si and so fields represent amount of bytes which were transeferred from
// physical memory to/from disk.
// Values of si and so during running ex2.c on my computer were 0/0
// accordingly, so my computer has enough RAM)

// Ex3
// Dirung programm execution we can see than VIRTual and RESidenial memory value grow, but SHaRed is constant. Shared is constant because it is allocated by libraries, Virtual and Residential memories grow because of malloc.
}
