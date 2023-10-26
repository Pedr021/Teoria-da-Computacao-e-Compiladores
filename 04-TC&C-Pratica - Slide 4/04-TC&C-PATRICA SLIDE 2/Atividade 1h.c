#include <stdio.h>
#include <stdlib.h>
void encontrarDiferenca(int A[], int tamanhoA, int B[], int tamanhoB) {
 int *diferenca = NULL;
 int tamanhoDiferenca = 0;
 for (int i = 0; i < tamanhoA; i++) {
 int estaNaB = 0;
 for (int j = 0; j < tamanhoB; j++) {
 if (A[i] == B[j]) {
 estaNaB = 1;
 break;
 }
 }
 if (!estaNaB) {

 tamanhoDiferenca++;
 diferenca = (int *)realloc(diferenca, tamanhoDiferenca * sizeof(int));
 diferenca[tamanhoDiferenca - 1] = A[i];
 }
 }
 printf("Diferença entre A e B: ");
 for (int i = 0; i < tamanhoDiferenca; i++) {
 printf("%d ", diferenca[i]);
 }
 printf("\n");
 FILE *arquivo = fopen("conjunto.txt", "w");
 if (arquivo == NULL) {
 printf("Erro ao abrir o arquivo para escrita.\n");
 exit(1);
 }
 for (int i = 0; i < tamanhoDiferenca; i++) {
 fprintf(arquivo, "%d ", diferenca[i]);
 }
 fclose(arquivo);
 free(diferenca);
}
int main() {
 int A[] = {1, 2, 3, 4, 5};
 int tamanhoA = 5;
 int B[] = {3, 4, 5, 6, 7};
 int tamanhoB = 5;
 encontrarDiferenca(A, tamanhoA, B, tamanhoB);
 return 0;
}
