#include <stdio.h>

int f(int n) {
    if (n % 2 == 0) {
        return -n / 2;
    } else {
        return n / 2 + 1;
    }
}

void print_f_series(int limite, int i) {
    if (i > limite) {
        return;
    }
    int result = f(i);
    printf("[%d, %d], ", i, result);
    print_f_series(limite, i + 1);
}

int main() {
    int limite;
    printf("Informe o límite: ");
    scanf("%d", &limite);
    print_f_series(limite, 0);
    printf("\n");
    return 0;
}
