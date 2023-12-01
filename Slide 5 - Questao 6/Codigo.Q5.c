#include <stdio.h>
#include <string.h>

// Definindo os estados do AFD
enum States {
    q0,  // Estado inicial e de aceitação
    q1   // Estado alternativo
};

// Função de transição do AFD
enum States transition(enum States currentState, char input) {
    switch (currentState) {
        case q0:
            return (input == '0') ? q1 : q0;
        case q1:
            return (input == '0') ? q0 : q1;
    }
    return currentState; // Caso de erro
}

// Função principal para verificar se uma palavra é aceita pelo AFD
int isAccepted(char *input) {
    enum States currentState = q0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        currentState = transition(currentState, input[i]);
    }

    return (currentState == q0); // Verifica se a palavra termina no estado de aceitação q0
}

int main() {
    // Exemplos de uso
    char palavraExemplo[] = "teste";
    printf("Palavra exemplo: %s\n", isAccepted(palavraExemplo) ? "Aceita" : "Rejeitada");

    return 0;
}
