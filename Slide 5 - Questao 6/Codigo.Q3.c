#include <stdio.h>

// Estados do AFD
typedef enum {
    Q0,
    Q1
} Estado;

// Função de transição
Estado transicao(Estado estadoAtual, char input) {
    switch (estadoAtual) {
        case Q0:
            return (input == '0') ? Q1 : Q0;
        case Q1:
            return (input == '0') ? Q0 : Q1;
    }
    return estadoAtual;
}

// Função para verificar se uma palavra é aceita ou rejeitada
int Aceito(char * palavra) {
    Estado estadoAtual = Q0;

    for (int i = 0; palavra[i] != '\0'; ++i) {
        estadoAtual = transicao(estadoAtual, palavra[i]);
    }

    // Verificando se o estado final é um estado de aceitação (Q0)
    return estadoAtual == Q0;
}

int main() {
    char palavra[100];

    printf("Digite uma palavra sobre o alfabeto {0, 1}: ");
    scanf("%s", palavra);

    if (Aceito(palavra)) {
        printf("Palavra informada aceita :)\n");
    } else {
        printf("Palavra informada rejeitada :(\n");
    }

    return 0;
}
