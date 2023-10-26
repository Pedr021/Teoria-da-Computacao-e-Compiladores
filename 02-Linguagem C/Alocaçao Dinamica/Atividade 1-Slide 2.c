/*O exemplo abaixo usa malloc para alocar dinamicamente um array de inteiros de acordo
com o tamanho especificado pelo usuário. Ele verifica se a alocação foi bem-sucedida,
assegurando que o ponteiro retornado por malloc não seja nulo. Além disso, a memória
alocada é liberada com free quando não for mais necessária para evitar vazamentos de
memória.
Altere o programa para que os trechos de código para alocação de memória, preenchimento
do vetor e impressão do vetor seja realizado por funções
 
*/ 



#include <stdio.h>
#include <stdlib.h>
int *alocarMemoria(int n) {
 int *array = (int *)malloc(n * sizeof(int));
 if (array == NULL) {
 printf("Falha na alocação de memória.\n");
 exit(1);
 }
 return array;
}
void preencherVetor(int *array, int n) {
 for (int i = 0; i < n; i++) {
 array[i] = i * 10;
 }
}
void imprimirVetor(int *array, int n) {
 printf("Array: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", array[i]);
 }
 printf("\n");
}
int main() {
 int *array, n;
 printf("Digite o tamanho do array: ");
 scanf("%d", &n);
 array = alocarMemoria(n);
 preencherVetor(array, n);
 imprimirVetor(array, n);
 free(array);
 return 0;
}