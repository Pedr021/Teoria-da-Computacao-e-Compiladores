#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 3

// Estrutura para representar o grafo
typedef struct {
    char cidades[MAX_CIDADES][20];
    int r[MAX_CIDADES];
    int a[MAX_CIDADES][MAX_CIDADES];
    int numCidades;
    int numEstradas;
} GrafoRotulado;

// Função para inicializar o grafo
void inicializarGrafo(GrafoRotulado* grafo) {
    grafo->numCidades = 0;
    grafo->numEstradas = 0;

    strcpy(grafo->cidades[grafo->numCidades++], "Rio");
    strcpy(grafo->cidades[grafo->numCidades++], "SP");
    strcpy(grafo->cidades[grafo->numCidades++], "BH");

    // Inserir distâncias
    grafo->a[0][1] = 450;
    grafo->a[0][2] = 500;
    grafo->a[2][1] = 600;

    grafo->r[grafo->numEstradas++] = 450;
    grafo->r[grafo->numEstradas++] = 500;
    grafo->r[grafo->numEstradas++] = 600;
}

// Função para inserir distância entre cidades
void inserirDistancia(GrafoRotulado* grafo, const char cidade1[20], const char cidade2[20], int distancia) {
    int i = -1;
    int j = -1;

    for (int k = 0; k < grafo->numCidades; k++) {
        if (strcmp(grafo->cidades[k], cidade1) == 0) {
            i = k;
        }
        if (strcmp(grafo->cidades[k], cidade2) == 0) {
            j = k;
        }
    }

    if (i != -1 && j != -1) {
        grafo->a[i][j] = distancia;
        grafo->r[grafo->numEstradas++] = distancia;
    } else {
        printf("Cidade(s) não existem no conjunto de vértices.\n");
    }
}

// Função para encontrar a distância entre cidades
int encontrarDistanciaEntreCidades(GrafoRotulado* grafo, const char cidade1[20], const char cidade2[20]) {
    int i = -1;
    int j = -1;

    for (int k = 0; k < grafo->numCidades; k++) {
        if (strcmp(grafo->cidades[k], cidade1) == 0) {
            i = k;
        }
        if (strcmp(grafo->cidades[k], cidade2) == 0) {
            j = k;
        }
    }

    if (i != -1 && j != -1) {
        return grafo->a[i][j];
    }

    return 0;
}

// Função para contar estradas
int contarEstradas(GrafoRotulado* grafo) {
    return grafo->numEstradas;
}

// Função para imprimir a matriz
void imprimirMatriz(GrafoRotulado* grafo) {
    printf("Matriz de Distâncias:\n");
    for (int i = 0; i < grafo->numCidades; i++) {
        for (int j = 0; j < grafo->numCidades; j++) {
            int distancia = grafo->a[i][j];
            printf("Distância entre %s e %s: %d km\n", grafo->cidades[i], grafo->cidades[j], distancia);
        }
    }
}

// Função para calcular o comprimento do caminho de forma recursiva
int calcularComprimentoCaminhoRecursivo(GrafoRotulado* grafo, int origem, int destino, int visitados[]) {
    if (origem == destino) {
        return 0;
    }

    visitados[origem] = 1;
    int menorComprimento = __INT_MAX__;

    for (int i = 0; i < grafo->numCidades; i++) {
        if (grafo->a[origem][i] > 0 && !visitados[i]) {
            int comprimento = grafo->a[origem][i] + calcularComprimentoCaminhoRecursivo(grafo, i, destino, visitados);
            if (comprimento < menorComprimento && comprimento > 0) {
                menorComprimento = comprimento;
            }
        }
    }

    visitados[origem] = 0;

    return menorComprimento;
}

// Função para calcular o comprimento do caminho
int calcularComprimentoCaminho(GrafoRotulado* grafo, const char cidadeOrigem[20], const char cidadeDestino[20]) {
    int origem = -1;
    int destino = -1;

    for (int i = 0; i < grafo->numCidades; i++) {
        if (strcmp(grafo->cidades[i], cidadeOrigem) == 0) {
            origem = i;
        }
        if (strcmp(grafo->cidades[i], cidadeDestino) == 0) {
            destino = i;
        }
    }

    if (origem == -1 || destino == -1) {
        return 0;
    }

    return calcularComprimentoCaminhoRecursivo(grafo, origem, destino, (int[MAX_CIDADES]) {0});
}

// Função para verificar se há ciclos no grafo
int haCiclosRecursivo(GrafoRotulado* grafo, int vertice, int visitados[], int pai) {
    visitados[vertice] = 1;

    for (int i = 0; i < grafo->numCidades; i++) {
        if (grafo->a[vertice][i] != 0) {
            if (!visitados[i]) {
                if (haCiclosRecursivo(grafo, i, visitados, vertice)) {
                    return 1;
                }
            } else if (i != pai) {
                return 1;
            }
        }
    }

    return 0;
}

// Função para verificar se há ciclos no grafo
int haCiclos(GrafoRotulado* grafo) {
    for (int i = 0; i < grafo->numCidades; i++) {
        int visitados[MAX_CIDADES] = {0};
        if (haCiclosRecursivo(grafo, i, visitados, -1)) {
            return 1;
        }
    }

    return 0;
}

// Função para calcular o grau de entrada de uma cidade
int grauEntrada(GrafoRotulado* grafo, const char cidade[20]) {
    int j = -1;

    for (int i = 0; i < grafo->numCidades; i++) {
        if (strcmp(grafo->cidades[i], cidade) == 0) {
            j = i;
        }
    }

    if (j != -1) {
        int grau = 0;
        for (int i = 0; i < grafo->numCidades; i++) {
            if (grafo->a[i][j] != 0) {
                grau++;
            }
        }
        return grau;
    }

    return -1;
}

// Função para calcular o grau de saída de uma cidade
int grauSaida(GrafoRotulado* grafo, const char cidade[20]) {
    int i = -1;

    for (int j = 0; j < grafo->numCidades; j++) {
        if (strcmp(grafo->cidades[j], cidade) == 0) {
            i = j;
        }
    }

    if (i != -1) {
        int grau = 0;
        for (int j = 0; j < grafo->numCidades; j++) {
            if (grafo->a[i][j] != 0) {
                grau++;
            }
        }
        return grau;
    }

    return -1;
}

int main() {
    GrafoRotulado grafo;
    inicializarGrafo(&grafo);

    printf("Total de estradas: %d\n", contarEstradas(&grafo));
    imprimirMatriz(&grafo);

    char cidadeOrigem[20];
    char cidadeDestino[20];

    printf("Digite a cidade de origem: ");
    scanf("%s", cidadeOrigem);
    printf("Digite a cidade de destino: ");
    scanf("%s", cidadeDestino);

    int comprimentoCaminho = calcularComprimentoCaminho(&grafo, cidadeOrigem, cidadeDestino);
    if (comprimentoCaminho > 0) {
        printf("Comprimento do caminho entre %s e %s: %d km\n", cidadeOrigem, cidadeDestino, comprimentoCaminho);
    } else {
        printf("Não há caminho entre %s e %s.\n", cidadeOrigem, cidadeDestino);
    }

    if (haCiclos(&grafo)) {
        printf("O grafo possui ciclos.\n");
    } else {
        printf("O grafo não possui ciclos.\n");
    }

    for (int i = 0; i < grafo.numCidades; i++) {
        int grauE = grauEntrada(&grafo, grafo.cidades[i]);
        if (grauE >= 0) {
            printf("Grau de entrada de %s: %d\n", grafo.cidades[i], grauE);
        } else {
            printf("A cidade %s não existe no conjunto de vértices.\n", grafo.cidades[i]);
        }

        int grauS = grauSaida(&grafo, grafo.cidades[i]);
        if (grauS >= 0) {
            printf("Grau de saída de %s: %d\n", grafo.cidades[i], grauS);
        } else {
            printf("A cidade %s não existe no conjunto de vértices.\n", grafo.cidades[i]);
        }
    }

    return 0;
}