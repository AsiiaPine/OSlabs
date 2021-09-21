#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define SIZE 5

FILE * f=NULL;
int counter = 0;

void *producer_func(void *arg) {
    while (true) {

        while (counter < 0 || counter > SIZE - 1)
            sleep(1);
        fprintf(f, "Producer rules #%d\n", counter);
        counter++;
    }
}

void *consumer_func(void *arg) {
    int temp = 0;
    while (true) {
        while (counter <= 0 || counter > SIZE)
            sleep(1);
        fprintf(f, "Consumer rules #%d\n", counter);     
	    counter--;
    }
}

int main() {
    f= fopen("file.txt", "w");
    pthread_t producer_t, consumer_t;
    pthread_create(&producer_t, NULL, producer_func, NULL);
    pthread_create(&consumer_t, NULL, consumer_func, NULL);
    sleep(10);
}
