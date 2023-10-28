#include <stdio.h>

int f(int n) {
    if (n == 0) {
        return 0;
    } else if (n % 2 == 0) {
        return -f(n / 2);
    } else {
        return f((n - 1) / 2) + 1;
    }
}

void printResult(int i, int limite) {
    if (i > limite) {
        printf("\n");
        return;
    }

    int result = f(i);
    printf("[%d, %d], ", i, result);
    printResult(i + 1, limite);
}

int main() {
    int limite;
    printf("Informe o limite: ");
    scanf("%d", &limite);

    printf("Resultado:\n");
    printResult(0, limite);

    return 0;
}
