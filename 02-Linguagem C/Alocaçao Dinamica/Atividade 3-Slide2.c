/*) O exemplo abaixo usa realloc para redimensionar dinamicamente um array alocado
anteriormente. Observe que a realocação pode falhar, então é importante verificar se o
ponteiro retornado por realloc não é nulo após a operação. Igualmente importante é a
liberação de memória ao final do algoritmo.
Altere o exemplo para que seja um vetor de estrutura Veículo. A estrutura Veículo deve possuir
os campos: número do chassi, marca, modelo e preço. Os trechos de código para alocação de
memória, preenchimento do vetor, impressão do vetor e realocação de memória devem ser
realizados por funções
 
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Veiculo {
 char chassi[17];
 char marca[50];
 char modelo[50];
 float preco;
};
struct Veiculo *alocarMemoria(int n) {
 struct Veiculo *array = (struct Veiculo *)malloc(n * sizeof(struct Veiculo));
 if (array == NULL) {
 printf("Falha na alocação de memória.\n");
 exit(1);
 }
 return array;
}
struct Veiculo *realocarMemoria(struct Veiculo *array, int *n, int novo_tamanho) {
 struct Veiculo *novo_array = (struct Veiculo *)realloc(array, novo_tamanho * sizeof(struct 
Veiculo));
 if (novo_array == NULL) {
 printf("Falha na realocação de memória.\n");
 exit(1);
 }
 *n = novo_tamanho;
 return novo_array;
}
void preencherVetor(struct Veiculo *array, int n) {
 for (int i = 0; i < n; i++) {
 printf("Digite o número do chassi do veículo %d: ", i + 1);
 scanf("%s", array[i].chassi);
 printf("Digite a marca do veículo %d: ", i + 1);
 scanf(" %[^\n]", array[i].marca);
 printf("Digite o modelo do veículo %d: ", i + 1);
 scanf(" %[^\n]", array[i].modelo);
 printf("Digite o preço do veículo %d: ", i + 1);
 scanf("%f", &array[i].preco);
 }
}
void imprimirVetor(struct Veiculo *array, int n) {
 printf("Array:\n");
 for (int i = 0; i < n; i++) {
 printf("Veículo %d:\n", i + 1);
 printf("Número do Chassi: %s\n", array[i].chassi);
 printf("Marca: %s\n", array[i].marca);
 printf("Modelo: %s\n", array[i].modelo);
 printf("Preço: %.2f\n", array[i].preco);
 }
}
int main() {
 int n;
 printf("Digite o tamanho inicial do array: ");
 scanf("%d", &n);
 struct Veiculo *array = alocarMemoria(n);
 preencherVetor(array, n);
 imprimirVetor(array, n);
 int novo_tamanho = n + 5;
 array = realocarMemoria(array, &n, novo_tamanho);
 for (int i = n - 5; i < n; i++) {
 printf("Digite o número do chassi do veículo %d: ", i + 1);
 scanf("%s", array[i].chassi);
 printf("Digite a marca do veículo %d: ", i + 1);
 scanf(" %[^\n]", array[i].marca);
 printf("Digite o modelo do veículo %d: ", i + 1);
 scanf(" %[^\n]", array[i].modelo);
 printf("Digite o preço do veículo %d: ", i + 1);
 scanf("%f", &array[i].preco);
 }
 imprimirVetor(array, n);
 
 free(array);
 return 0;
}