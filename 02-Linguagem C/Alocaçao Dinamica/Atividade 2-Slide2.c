/*) O exemplo abaixo usa calloc para alocar dinamicamente um array de inteiros e inicializar
todos os elementos com zero. A abordagem para verificar a alocação e liberar a memória é
a mesma do exercício anterior.
Altere o exemplo para que seja um vetor de estrutura Pessoa. A estrutura Pessoa deve possuir
os campos: CPF, nome e salário. Os trechos de código para alocação de memória,
preenchimento do vetor e impressão do vetor devem ser realizados por funções.
 
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Pessoa {
 char cpf[12];
 char nome[50];
 float salario;
};
struct Pessoa *alocarMemoria(int n) {
 struct Pessoa *array = (struct Pessoa *)calloc(n, sizeof(struct Pessoa));
 if (array == NULL) {
 printf("Falha na alocação de memória.\n");
 exit(1);
 }
 return array;
}
void preencherVetor(struct Pessoa *array, int n) {
 for (int i = 0; i < n; i++) {
 printf("Digite o CPF da pessoa %d: ", i + 1);
 scanf("%s", array[i].cpf);
 printf("Digite o nome da pessoa %d: ", i + 1);
 scanf(" %[^\n]", array[i].nome);
 printf("Digite o salário da pessoa %d: ", i + 1);
 scanf("%f", &array[i].salario);
 }
}
void imprimirVetor(struct Pessoa *array, int n) {
 printf("Array:\n");
 for (int i = 0; i < n; i++) {
 printf("Pessoa %d:\n", i + 1);
 printf("CPF: %s\n", array[i].cpf);
 printf("Nome: %s\n", array[i].nome);
 printf("Salário: %.2f\n", array[i].salario);
 }
}
int main() {
 int n;
 printf("Digite o tamanho do array: ");
 scanf("%d", &n);
 struct Pessoa *array = alocarMemoria(n);
 preencherVetor(array, n);
 imprimirVetor(array, n);
 free(array);
 return 0;
}