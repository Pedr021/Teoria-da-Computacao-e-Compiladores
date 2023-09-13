#include <stdio.h>

int main() {
    float temperaturaCelsius, temperaturaFahrenheit;

    // Solicita a temperatura em Celsius ao usuário
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &temperaturaCelsius);

    // Calcula a temperatura em Fahrenheit
    temperaturaFahrenheit = (temperaturaCelsius * 1.8) + 32;

    // Apresenta a temperatura em Fahrenheit
    printf("A temperatura em graus Fahrenheit é: %.2f\n", temperaturaFahrenheit);

    return 0;
}
