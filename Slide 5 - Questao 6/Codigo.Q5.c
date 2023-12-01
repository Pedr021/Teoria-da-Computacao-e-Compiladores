#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Definição dos estados
enum Estados {
    Q0,
    Q1,
    Q2,
    Q3
};

// Função para verificar se a palavra é aceita pelo AFD
bool verificaPalavra(char *palavra) {
    int estado = Q0;

    for (int i = 0; i < strlen(palavra); i++) {
        char simbolo = palavra[i];

        switch (estado) {
        case Q0:
            estado = (simbolo == '0') ? Q1 : Q2;
            break;
        case Q1:
            estado = (simbolo == '0') ? Q0 : Q3;
            break;
        case Q2:
            estado = (simbolo == '0') ? Q3 : Q0;
            break;
        case Q3:
            estado = (simbolo == '0') ? Q2 : Q1;
            break;
        }
    }

    return estado == Q0;
}

int main() {
    char palavra[100];

    printf("Digite uma palavra (composta por '0' e '1'): ");
    scanf("%s", palavra);

    if (verificaPalavra(palavra)) {
        printf("A palavra '%s' é aceita pelo AFD.\n", palavra);
    } else {
        printf("A palavra '%s' não é aceita pelo AFD.\n", palavra);
    }

    return 0;
}

