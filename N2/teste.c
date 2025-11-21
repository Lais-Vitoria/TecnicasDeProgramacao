#include <stdio.h>

int particoes(int n, int k) {
    if (n == 0) return 1;
    if (n < 0 || k == 0) return 0;
    return particoes(n - k, k) + particoes(n, k - 1);
}

int main() {
    printf("Número de partições de 5 = %d\n", particoes(5, 5));
    return 0;
}
