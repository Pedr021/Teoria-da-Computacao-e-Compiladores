#include <stdio.h>
#include <math.h> // Incluímos a biblioteca math para usar a função sqrt (raiz quadrada)

int main() {
    float cateto1, cateto2, hipotenusa;

    // Solicita os valores dos catetos ao usuário
    printf("Digite o valor do primeiro cateto: ");
    scanf("%f", &cateto1);

    printf("Digite o valor do segundo cateto: ");
    scanf("%f", &cateto2);

    // Calcula o valor da hipotenusa usando o Teorema de Pitágoras
    hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);

    // Apresenta o valor da hipotenusa
    printf("O valor da hipotenusa é: %.2f\n", hipotenusa);

    return 0;
}
