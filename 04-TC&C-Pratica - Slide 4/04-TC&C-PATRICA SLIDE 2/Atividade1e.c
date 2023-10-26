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
// Função para verificar se dois conjuntos são iguais
int areSetsEqual(int *set1, int size1, int *set2, int size2) {
if (size1 != size2) {
return 0; // Os conjuntos têm tamanhos diferentes
}
for (int i = 0; i < size1; i++) {
int found = 0;
for (int j = 0; j < size2; j++) {
if (set1[i] == set2[j]) {
found = 1;
break;
}
}
if (!found) {
return 0; // Os conjuntos têm elementos diferentes
}
}
return 1; // Os conjuntos são iguais
}
// Função para gerar e armazenar conjuntos próprios
void generateAndStoreProperSets(int *originalSet, int size, FILE *file) {
int powerSetSize = pow(2, size);
for (int i = 1; i < powerSetSize; i++) {
int subsetSize = 0;
int subset[size];
for (int j = 0; j < size; j++) {
if (i & (1 << j)) {
subset[subsetSize++] = originalSet[j];
}
}
// Verificar se o conjunto gerado é próprio
int isProper = !areSetsEqual(originalSet, size, subset, subsetSize);
// Se for um conjunto próprio, imprime na tela e armazena no arquivo
if (isProper) {
printSet(subset, subsetSize);
for (int j = 0; j < subsetSize; j++) {
fprintf(file, "%d ", subset[j]);
}
fprintf(file, "\n");
}
}
}
int main() {
int setA[] = {1, 2, 3};
int sizeA = 3;
int setB[] = {4, 5};
int sizeB = 2;
FILE *file = fopen("conjuntos_proprios.txt", "w");
if (file == NULL) {
perror("Erro ao abrir o arquivo");
exit(1);
}
fprintf(file, "Conjuntos Próprios de A:\n");
generateAndStoreProperSets(setA, sizeA, file);
fprintf(file, "\nConjuntos Próprios de B:\n");
generateAndStoreProperSets(setB, sizeB, file);
fclose(file);
return 0;
}