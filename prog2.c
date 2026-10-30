#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *name = malloc(8);
    strcpy(name, "Student");
    free(name);
    printf("Name: %s\n", name);            // use-after-free

    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i <= 5; i++)           // i == 5 sərhəddən kənardır
        arr[i] = i * 10;                   // heap-buffer-overflow
    printf("arr[2] = %d\n", arr[2]);
    free(arr);
    return 0;
}
