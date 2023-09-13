#include <stdio.h>
#include <math.h> // Incluímos a biblioteca math para usar o valor de π (pi)

int main() {
    float raio, comprimento, area, volume;

    // Solicita o valor do raio da esfera ao usuário
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    // Calcula o comprimento da esfera
    comprimento = 2 * M_PI * raio;

    // Calcula a área da esfera
    area = M_PI * raio * raio;

    // Calcula o volume da esfera
    volume = (3.0 / 4.0) * M_PI * pow(raio, 3);

    // Apresenta os resultados
    printf("Comprimento da esfera: %.2f\n", comprimento);
    printf("Área da esfera: %.2f\n", area);
    printf("Volume da esfera: %.2f\n", volume);

    return 0;
}
