#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void lerEApresentarSequenciasDoArquivo() {
FILE *arquivo = fopen("sequencias1.txt", "r");
if (arquivo == NULL) {
printf("Erro ao abrir o arquivo.\n");
return;
}
unsigned int sequencia1[100];
unsigned int sequencia2[100];
int tamanho1 = 0;
int tamanho2 = 0;
char linha[100];
int sequenciaAtual = 0;
while (fgets(linha, sizeof(linha), arquivo) != NULL) {
if (strstr(linha, "Primeira sequência:") != NULL) {
sequenciaAtual = 1;
} else if (strstr(linha, "Segunda sequência:") != NULL) {
sequenciaAtual = 2;
} else {
if (sequenciaAtual == 1) {
if (sscanf(linha, "%u", &sequencia1[tamanho1]) == 1) {
tamanho1++;
}
} else if (sequenciaAtual == 2) {
if (sscanf(linha, "%u", &sequencia2[tamanho2]) == 1) {
tamanho2++;
}
}
}
}
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
fclose(arquivo);
}
int main() {
lerEApresentarSequenciasDoArquivo();
return 0;
}