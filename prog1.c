#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *data = calloc(5, sizeof(int));    /* calloc yaddaşı sıfırlayır */
    if (data == NULL) {
        fprintf(stderr, "Yaddas ayrilmadi\n");
        return 1;
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += data[i];
    if (sum > 0)
        printf("Sum is positive\n");
    else
        printf("Sum = %d\n", sum);

    char *buf = malloc(100);
    if (buf == NULL) {
        free(data);
        return 1;
    }
    snprintf(buf, 100, "leak test");
    printf("%s\n", buf);

    free(buf);                             /* sızma aradan qaldırıldı */
    free(data);
    return 0;
}
