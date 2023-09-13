#include <stdio.h>

int main() {
    int anoNascimento, anoAtual, idadeAtual, idade2050;

    // Solicita o ano de nascimento e o ano atual ao usuário
    printf("Digite o ano de nascimento: ");
    scanf("%d", &anoNascimento);

    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    // Calcula a idade da pessoa no ano atual
    idadeAtual = anoAtual - anoNascimento;

    // Calcula a idade que a pessoa terá em 2050
    idade2050 = 2050 - anoNascimento;

    // Apresenta as idades calculadas
    printf("A idade da pessoa no ano atual é: %d anos\n", idadeAtual);
    printf("A idade da pessoa em 2050 será: %d anos\n", idade2050);

    return 0;
}
