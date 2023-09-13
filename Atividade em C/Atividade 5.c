#include <stdio.h>

int main() {
    float diagonalMaior, diagonalMenor, area;

    // Solicita as diagonais ao usuário
    printf("Digite o valor da diagonal maior do losango: ");
    scanf("%f", &diagonalMaior);

    printf("Digite o valor da diagonal menor do losango: ");
    scanf("%f", &diagonalMenor);

    // Calcula a área do losango
    area = (diagonalMaior * diagonalMenor) / 2.0;

    // Apresenta a área
    printf("A área do losango é: %.2f\n", area);

    return 0;
}
