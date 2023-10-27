#include <stdio.h>

// Função para calcular e armazenar o produto cartesiano em um arquivo
void produtoCartesiano(int A[], int m, int B[], int n, FILE *arquivo) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(arquivo, "(%d, %d) ", A[i], B[j]);
        }
    }
}

int main() {
    // Defina os conjuntos A e B
    int A[] = {1, 2, 3};
    int B[] = {4, 5};

    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0);

    // Abra o arquivo original para escrita (substituir 'seuarquivo.txt' pelo nome do arquivo desejado)
    FILE *arquivo = fopen("seuarquivo.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Chame a função para calcular e armazenar o produto cartesiano
    produtoCartesiano(A, m, B, n, arquivo);

    // Feche o arquivo
    fclose(arquivo);

    printf("Produto cartesiano calculado e armazenado no arquivo.\n");

    return 0;
}
