#include <stdio.h>

int main() {
    float salarioAtual, novoSalario;

    // Solicita o salário atual ao usuário
    printf("Digite o salário atual do funcionário: ");
    scanf("%f", &salarioAtual);

    // Calcula o novo salário com aumento de 25%
    novoSalario = salarioAtual * 1.25; // 1.25 representa um aumento de 25%

    // Apresenta o novo salário
    printf("O novo salário do funcionário é: R$ %.2f\n", novoSalario);

    return 0;
}
