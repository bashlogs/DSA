/*
 * free method in C is used to dynamically de-allocate the memory
 * The memory allocated using functions malloc() and calloc() is not de-allocated on their own. Hence the free() method is used
 */

// free - free(ptr)

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr, *ptr1;
    int n, i;
    n = 5;
    printf("Enter number of elements: %d\n", n);
    ptr = (int*)malloc(n * sizeof(int));
    ptr1 = (int*)calloc(n, sizeof(int));
    if (ptr == NULL || ptr1 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        for(i=0;i<n;i++){
          ptr[i] = i+1;
          printf("%d, ",ptr[i]);
        }
        printf("Memory successfully allocated using malloc.\n");
        free(ptr);
        printf("Malloc Memory successfully freed.\n");
        for(i=0;i<n;i++){
          ptr1[i] = i+1;
          printf("%d, ",ptr1[i]);
        }
        printf("\nMemory successfully allocated using calloc.\n");
        free(ptr1);
        printf("Calloc Memory successfully freed.\n");
    }
    return 0;
}
