#include <stdio.h>
#include <string.h>

// Definindo os estados do AFD
enum States {
    q0,  // Estado inicial
    q1,  // Após ler o primeiro "0"
    q2,  // Após ler "11"
    q3   // Estado final de aceitação
};

// Função de transição do AFD
enum States transition(enum States currentState, char input) {
    switch (currentState) {
        case q0:
            return (input == '0') ? q1 : q0;
        case q1:
            return (input == '0') ? q1 : (input == '1') ? q2 : q0;
        case q2:
            return (input == '0') ? q3 : (input == '1') ? q2 : q0;
        case q3:
            return q0; // Estado final, não há transições adicionais
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

    return (currentState == q3); // Verifica se a palavra termina no estado final q3
}

int main() {
    // Exemplos de uso
    char word1[] = "pedro";      // Palavra vazia
    char word2[] = "0110";  // Aceita
    char word3[] = "00110"; // Aceita
    char word4[] = "000";   // Rejeitada
    char word5[] = "111";   // Rejeitada

    // Verifica se cada palavra é aceita pelo AFD
    printf("Palavra vazia: %s\n", isAccepted(word1) ? "Aceita" : "Rejeitada");
    printf("0110: %s\n", isAccepted(word2) ? "Aceita" : "Rejeitada");
    printf("00110: %s\n", isAccepted(word3) ? "Aceita" : "Rejeitada");
    printf("000: %s\n", isAccepted(word4) ? "Aceita" : "Rejeitada");
    printf("111: %s\n", isAccepted(word5) ? "Aceita" : "Rejeitada");

    return 0;
}
