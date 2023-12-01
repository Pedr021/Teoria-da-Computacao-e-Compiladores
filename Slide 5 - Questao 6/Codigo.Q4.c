#include <stdio.h>

// Definindo os estados do AFD
typedef enum {
    q0, q1, q2, q3, q4
} Estado;

// Função para verificar se um caractere pertence ao conjunto {a, b}
int isAorB(char c) {
    return (c == 'a' || c == 'b');
}

// Função principal para verificar se uma string pertence à linguagem
int pertenceLinguagem(char *str) {
    Estado estadoAtual = q0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        switch (estadoAtual) {
            case q0:
                if (c == 'a') estadoAtual = q1;
                else if (c == 'b') estadoAtual = q3;
                else return 0;  // Se não é 'a' nem 'b', palavra não pertence à linguagem
                break;

            case q1:
                if (isAorB(c)) estadoAtual = q2;
                else return 0;
                break;

            case q2:
                if (isAorB(c)) estadoAtual = q2;
                else return 0;
                break;

            case q3:
                if (c == 'b') estadoAtual = q4;
                else return 0;
                break;

            case q4:
                if (isAorB(c)) estadoAtual = q2;
                else return 0;
                break;
        }
    }

    // Verificando se o estado final é aceitação
    return (estadoAtual == q2 || estadoAtual == q4);
}

int main() {
    char palavra1[] = "aaa";      // Exemplo de palavra aceita
    char palavra2[] = "babab";    // Exemplo de palavra aceita
    char palavra3[] = "bb";       // Exemplo de palavra aceita
    char palavra4[] = "abc";      // Exemplo de palavra rejeitada

    printf("%s: %s\n", palavra1, pertenceLinguagem(palavra1) ? "Aceita" : "Rejeitada");
    printf("%s: %s\n", palavra2, pertenceLinguagem(palavra2) ? "Aceita" : "Rejeitada");
    printf("%s: %s\n", palavra3, pertenceLinguagem(palavra3) ? "Aceita" : "Rejeitada");
    printf("%s: %s\n", palavra4, pertenceLinguagem(palavra4) ? "Aceita" : "Rejeitada");

    return 0;
}