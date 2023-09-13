#include <stdio.h>

int main() {
    int numero, i;

    // Solicita um número ao usuário
    printf("Informe um número: ");
    scanf("%d", &numero);

    // Calcula e exibe a tabuada de multiplicação
    for (i = 0; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}
