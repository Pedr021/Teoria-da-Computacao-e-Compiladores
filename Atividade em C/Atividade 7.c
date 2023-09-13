#include <stdio.h>

int main() {
    float salarioMinimo, salarioFuncionario, quantidadeSalariosMinimos;

    // Solicita o valor do salário mínimo e o salário do funcionário ao usuário
    printf("Digite o valor do salário mínimo: R$ ");
    scanf("%f", &salarioMinimo);

    printf("Digite o salário do funcionário: R$ ");
    scanf("%f", &salarioFuncionario);

    // Calcula a quantidade de salários mínimos que o funcionário recebe
    quantidadeSalariosMinimos = salarioFuncionario / salarioMinimo;

    // Apresenta a quantidade de salários mínimos
    printf("O funcionário recebe %.2f salários mínimos.\n", quantidadeSalariosMinimos);

    return 0;
}
