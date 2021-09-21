
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *printMessage(void *i) {
    printf("It is message from %d thread\n", *((int *) i));
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter number of threads: ");
    scanf("%d", &n);
    pthread_t thread[n];

    for (int i = 0; i < n; i++) {
        pthread_create(thread + i, NULL, printMessage, (void *) &i);
        printf("Thread # %d is created in iteration %d\n", (int) thread[i], i);
    }

    return 0;
}
