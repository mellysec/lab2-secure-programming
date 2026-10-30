#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *data = malloc(5 * sizeof(int));   // ilkin qiymət verilmir
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += data[i];                    // başlanmamış yaddaşın oxunması
    if (sum > 0)                           // Valgrind burada xəbərdarlıq verəcək
        printf("Sum is positive\n");
    else
        printf("Sum = %d\n", sum);

    char *buf = malloc(100);               // heç vaxt free() edilmir
    snprintf(buf, 100, "leak test");
    printf("%s\n", buf);
    return 0;                              // yaddaş sızması: data və buf
}
