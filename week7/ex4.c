clude <stdio.h>
#include <malloc.h>

#define type

void *myRealloc(void *ptr, int size) {
    void *newPtr = malloc(size);
    int oldSize = malloc_usable_size(ptr);
    if (size >= oldSize) {
        // Relocate old bytes
        for (int i = 0; i < oldSize; i++) {
            ((char *) newPtr)[i] = (char) ((char *) ptr)[i];
        }
    } else if (size == 0) {
        free(ptr);
    } else {
        for (int i = 0; i < oldSize; i++) {
            ((char *) newPtr)[i] = (char) ((char *) ptr)[i];
        }
    }
    return newPtr;
}

int main() {
    int *arr1 = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        arr1[i] = i;
    }

    arr1 = myRealloc(arr1, sizeof(int) * 20);
    for (int i = 0; i < 20; i++) {
        printf("%d\t", arr1[i]);
    }
    printf("\n");

    return 0;
}
//Exercise 4
//Write your own realloc() function using malloc() and free()
//realloc() changes the size of the memory block pointed to by ptr to
//size bytes. The contents will be unchanged in the range from the
//start of the region up to the minimum of the old and new sizes.
//Newly allocated memory will be uninitialized
//If ptr is NULL, the call is equivalent to malloc(size)
//If size is equal to zero, the call is equivalent to free(ptr)
//Unless ptr is NULL, it must have been returned by an earlier call to
//malloc(), calloc() or realloc()
