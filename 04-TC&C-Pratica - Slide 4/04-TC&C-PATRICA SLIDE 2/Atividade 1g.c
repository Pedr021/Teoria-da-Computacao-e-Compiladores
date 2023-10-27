#include <stdio.h>
#include <stdlib.h>
void encontrarIntersecao(int A[], int tamanhoA, int B[], int tamanhoB) {
 int *intersecao = NULL;
 int tamanhoIntersecao = 0;
 for (int i = 0; i < tamanhoA; i++) {
 for (int j = 0; j < tamanhoB; j++) {
 if (A[i] == B[j]) {

 tamanhoIntersecao++;
 intersecao = (int *)realloc(intersecao, tamanhoIntersecao * sizeof(int));
 intersecao[tamanhoIntersecao - 1] = A[i];
 }
 }
 }
 printf("Interseção dos conjuntos A e B: ");
 for (int i = 0; i < tamanhoIntersecao; i++) {
 printf("%d ", intersecao[i]);
 }
 printf("\n");
 FILE *arquivo = fopen("conjunto.txt", "w");
 if (arquivo == NULL) {
 printf("Erro ao abrir o arquivo para escrita.\n");
 exit(1);
 }
 for (int i = 0; i < tamanhoIntersecao; i++) {
 fprintf(arquivo, "%d ", intersecao[i]);
 }
 fclose(arquivo);
 free(intersecao);
}
int main() {
 int A[] = {1, 2, 3, 4, 5};
 int tamanhoA = 5;
 int B[] = {3, 4, 5, 6, 7};
 int tamanhoB = 5;
 encontrarIntersecao(A, tamanhoA, B, tamanhoB);
 return 0;
}
