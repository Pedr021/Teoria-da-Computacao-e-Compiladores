#include <stdio.h>
// Função para imprimir um conjunto
void printSet(int *set, int size) {
printf("{ ");
for (int i = 0; i < size; i++) {
printf("%d ", set[i]);
}
printf("}\n");
}
// Função para calcular a união de dois conjuntos
void unionSets(int *setA, int sizeA, int *setB, int sizeB, int *result, int *resultSize) {
int i, j, k;
i = j = k = 0;
while (i < sizeA && j < sizeB) {
if (setA[i] < setB[j]) {
result[k++] = setA[i++];
} else if (setB[j] < setA[i]) {
result[k++] = setB[j++];
} else {
result[k++] = setA[i++];
j++;
}
}
while (i < sizeA) {
result[k++] = setA[i++];
}
while (j < sizeB) {
result[k++] = setB[j++];
}
*resultSize = k;
}
int main() {
int setA[] = {1, 2, 3};
int sizeA = 3;
int setB[] = {3, 4, 5};
int sizeB = 3;
int result[100]; // Um tamanho razoável para o conjunto união
int resultSize;
unionSets(setA, sizeA, setB, sizeB, result, &resultSize);
printf("União de A e B: ");
printSet(result, resultSize);
FILE *file = fopen("uniao_conjuntos.txt", "w");
if (file == NULL) {
perror("Erro ao abrir o arquivo");
return 1;
}
fprintf(file, "União de A e B: ");
for (int i = 0; i < resultSize; i++) {
fprintf(file, "%d ", result[i]);
}
fclose(file);
return 0;
}