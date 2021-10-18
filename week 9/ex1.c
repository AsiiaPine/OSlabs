#include <stdio.h>
#include <stdlib.h>

struct page {
    unsigned short id;
    unsigned short age;
} page;
int n;
struct page *pages;

void increaseAge(struct page *page) {
    for (int i = 0; i < n; i++) {
        pages[i].age >>= 1;
    }
    page->age += 0x8000;
}

void increaseAgeMiss() {
    for (int i = 0; i < n; i++) {
        pages[i].age >>= 1;
    }
}

int main() {
    FILE *input = fopen("input.txt", "r");
    float numOfMisses = 0;
    float numOfHits = 0;
    char *s;
    printf("Write the number of pages:");
    scanf("%d", &n);
    pages = malloc(n * sizeof(page));
    for (int i = 0; i < n; i++) {
        pages[i].id = 35768;
        pages[i].age = 0;
    }
    unsigned short id;
    while (fscanf(input, "%hu", &id) != -1) {
        int miss = 1;
        for (int i = 0; i < n; i++) {
            if (pages[i].id == id) {
                increaseAge(&pages[i]);
                miss = -1;
            }
        }
        if (miss == 1) {
            numOfMisses++;
            increaseAgeMiss();
        } else {
            numOfHits++;
        }
        unsigned short maxAge = -1;
        struct page *olderPage;
        for (int i = 0; i < n; i++) {
            if (maxAge > pages[i].age) {
                maxAge=pages[i].age;
                olderPage = &pages[i];
            }
        }
        olderPage->age = 0x8000;
        olderPage->id = id;
    }
    
    printf("Hit/Miss ratio:\t %f\nNumber of hits: %f,\t Number of misses:\t%f", numOfHits / numOfMisses, numOfHits,numOfMisses);
}
