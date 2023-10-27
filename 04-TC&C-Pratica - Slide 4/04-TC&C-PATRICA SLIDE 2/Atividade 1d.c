#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Função para imprimir um conjunto
void printSet(int *set, int size) {
printf("{ ");
for (int i = 0; i < size; i++) {
printf("%d ", set[i]);
}
printf("}\n");
}
// Função para gerar o conjunto potência
void powerSet(int *originalSet, int size, FILE *file) {
int powerSetSize = pow(2, size);
for (int i = 0; i < powerSetSize; i++) {
int subsetSize = 0;
int subset[size];
for (int j = 0; j < size; j++) {
if (i & (1 << j)) {
subset[subsetSize++] = originalSet[j];
}
}
// Imprime o conjunto na tela
printSet(subset, subsetSize);
// Armazena o conjunto no arquivo
for (int j = 0; j < subsetSize; j++) {
fprintf(file, "%d ", subset[j]);
}
fprintf(file, "\n");
}
}
int main() {
int setA[] = {1, 2, 3};
int sizeA = 3;
int setB[] = {4, 5};
int sizeB = 2;
FILE *file = fopen("conjuntos.txt", "w");
if (file == NULL) {
perror("Erro ao abrir o arquivo");
exit(1);
}
fprintf(file, "Conjunto Potência de A:\n");
powerSet(setA, sizeA, file);
fprintf(file, "\nConjunto Potência de B:\n");
powerSet(setB, sizeB, file);
fclose(file);
return 0;
}
