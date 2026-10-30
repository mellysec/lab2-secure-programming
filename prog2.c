#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *name = malloc(8);
    if (name == NULL)
        return 1;
    snprintf(name, 8, "%s", "Student");    /* ölçü məhdudlaşdırılıb */
    printf("Name: %s\n", name);            /* free-dən ƏVVƏL istifadə */
    free(name);
    name = NULL;                           /* dangling pointer yoxdur */

    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL)
        return 1;
    for (int i = 0; i < 5; i++)            /* i < 5: sərhəd düzəldildi */
        arr[i] = i * 10;
    printf("arr[2] = %d\n", arr[2]);
    free(arr);
    return 0;
}
