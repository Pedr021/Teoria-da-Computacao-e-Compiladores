#include <stdio.h>

int main() {
    float cotacaoDolar, valorDolar, valorReais;

    // Solicita a cotação do dólar e o valor em dólares ao usuário
    printf("Digite a cotação do dólar em reais: ");
    scanf("%f", &cotacaoDolar);

    printf("Digite o valor em dólares: ");
    scanf("%f", &valorDolar);

    // Converte o valor em dólares para reais usando a cotação
    valorReais = valorDolar * cotacaoDolar;

    // Apresenta o valor em reais
    printf("O valor em reais é: R$ %.2f\n", valorReais);

    return 0;
}
