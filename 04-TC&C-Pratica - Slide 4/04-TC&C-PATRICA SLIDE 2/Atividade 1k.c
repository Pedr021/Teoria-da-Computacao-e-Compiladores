#include <stdio.h>

// Função para calcular e apresentar o produto cartesiano na tela
void calcularEApresentarProdutoCartesiano(int B[], int m, int A[], int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d) ", B[i], A[j]);
        }
    }
    printf("\n");
}

// Função para armazenar o produto cartesiano em um arquivo
void armazenarProdutoCartesianoEmArquivo(int B[], int m, int A[], int n, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a"); // Abre o arquivo em modo de adição (append)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(arquivo, "(%d, %d) ", B[i], A[j]);
        }
    }

    fprintf(arquivo, "\n"); // Inclui uma quebra de linha após o produto cartesiano

    fclose(arquivo);
}

int main() {
    // Defina os conjuntos A e B
    int A[] = {1, 2, 3};
    int B[] = {4, 5};

    int m = sizeof(B) / sizeof(B[0]);
    int n = sizeof(A) / sizeof(A[0]);

    // Nome do arquivo original
    const char *nomeArquivo = "seuarquivo.txt";

    // Chame a função para calcular e apresentar o produto cartesiano
    calcularEApresentarProdutoCartesiano(B, m, A, n);

    // Chame a função para armazenar o produto cartesiano no arquivo
    armazenarProdutoCartesianoEmArquivo(B, m, A, n, nomeArquivo);

    printf("Produto cartesiano calculado e armazenado no arquivo.\n");

    return 0;
}
