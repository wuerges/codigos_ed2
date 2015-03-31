#include <sys/time.h>
#include <stdio.h>
#include <time.h>

int main() {
    int i;
    
    clock_t start = clock();
    for (i = 0; i < 1000000; ++i) {
        printf("%d", i);
    }
    clock_t end = clock();

    unsigned long micros = (end - start) * (1000000 / CLOCKS_PER_SEC);
    printf("\n\ntime %lu\n", micros);
    return 0;
}
