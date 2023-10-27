#include <stdio.h>

void lerEArmazenarSequencias() {
// Variáveis para armazenar as sequências
unsigned int sequencia1[100], sequencia2[100];
int tamanho1, tamanho2;
// Ler a primeira sequência
printf("Digite o tamanho da primeira sequência: ");
scanf("%d", &tamanho1);
printf("Digite os elementos da primeira sequência:\n");
for (int i = 0; i < tamanho1; i++) {
scanf("%u", &sequencia1[i]);
}
// Ler a segunda sequência
printf("Digite o tamanho da segunda sequência: ");
scanf("%d", &tamanho2);
printf("Digite os elementos da segunda sequência:\n");
for (int i = 0; i < tamanho2; i++) {
scanf("%u", &sequencia2[i]);
}
// Exibir as sequências na tela
printf("Primeira sequência: ");
for (int i = 0; i < tamanho1; i++) {
printf("%u ", sequencia1[i]);
}
printf("\n");
printf("Segunda sequência: ");
for (int i = 0; i < tamanho2; i++) {
printf("%u ", sequencia2[i]);
}
printf("\n");
// Armazenar as sequências em um arquivo de texto
FILE *arquivo = fopen("sequencias.txt", "w");
if (arquivo == NULL) {
printf("Erro ao abrir o arquivo.\n");
return;
}
fprintf(arquivo, "Primeira sequência: ");
for (int i = 0; i < tamanho1; i++) {
fprintf(arquivo, "%u ", sequencia1[i]);
}
fprintf(arquivo, "\n");
fprintf(arquivo, "Segunda sequência: ");
for (int i = 0; i < tamanho2; i++) {
fprintf(arquivo, "%u ", sequencia2[i]);
}
fprintf(arquivo, "\n");
fclose(arquivo);
}
int main() {
lerEArmazenarSequencias();
return 0;
}
