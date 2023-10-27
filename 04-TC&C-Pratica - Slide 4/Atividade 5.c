/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int cidade1;
    int cidade2;
    int distancia;
} Aresta;


typedef struct {
    int vertices[4]; 
    int r[10];       
    Aresta arestas[10];
    int numVertices;
    int numArestas;
} GrafoRotulado;


void inserirDistancia(GrafoRotulado* grafo, int cidade1, int cidade2, int distancia) {
    if (grafo->numVertices == 4 && grafo->numArestas < 10) {
        grafo->arestas[grafo->numArestas].cidade1 = cidade1;
        grafo->arestas[grafo->numArestas].cidade2 = cidade2;
        grafo->arestas[grafo->numArestas].distancia = distancia;
        grafo->r[grafo->numArestas] = distancia;
        grafo->numArestas++;
    }
}


int contarEstradas(GrafoRotulado* grafo) {
    return grafo->numArestas;
}


int encontrarDistanciaRecursiva(GrafoRotulado* grafo, int cidade1, int cidade2, int indice) {
    if (indice >= grafo->numArestas) {
        return 0; // Não foi encontrada uma estrada entre as cidades
    }

    if ((grafo->arestas[indice].cidade1 == cidade1 && grafo->arestas[indice].cidade2 == cidade2) ||
        (grafo->arestas[indice].cidade1 == cidade2 && grafo->arestas[indice].cidade2 == cidade1)) {
        return grafo->arestas[indice].distancia;
    }

    return encontrarDistanciaRecursiva(grafo, cidade1, cidade2, indice + 1);
}


void imprimirMatriz(GrafoRotulado* grafo) {
    printf("Matriz de Distâncias:\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        for (int j = 0; j < grafo->numVertices; j++) {
            int distancia = 0;
            for (int k = 0; k < grafo->numArestas; k++) {
                if ((grafo->arestas[k].cidade1 == grafo->vertices[i] && grafo->arestas[k].cidade2 == grafo->vertices[j]) ||
                    (grafo->arestas[k].cidade1 == grafo->vertices[j] && grafo->arestas[k].cidade2 == grafo->vertices[i])) {
                    distancia = grafo->arestas[k].distancia;
                    break;
                }
            }
            printf("Distância entre Cidade%d e Cidade%d: %d km\n", grafo->vertices[i], grafo->vertices[j], distancia);
        }
    }
}

    
int main() {
    GrafoRotulado grafo;
    grafo.numVertices = 4;
    grafo.numArestas = 0;
    grafo.vertices[0] = 0;
    grafo.vertices[1] = 1;
    grafo.vertices[2] = 2;
    grafo.vertices[3] = 3;

    // Insira as distâncias entre as cidades
    inserirDistancia(&grafo, 0, 1, 4);
    inserirDistancia(&grafo, 0, 3, 5);
    inserirDistancia(&grafo, 1, 2, 2);
    inserirDistancia(&grafo, 1, 3, 4);
    inserirDistancia(&grafo, 3, 2, 3);

    printf("Total de estradas: %d\n", contarEstradas(&grafo));

    imprimirMatriz(&grafo);

    // Teste de encontrar distância entre cidades
    int cidade1 = 0;
    int cidade2 = 1;
    int distancia = encontrarDistanciaRecursiva(&grafo, cidade1, cidade2, 0);

    if (distancia > 0) {
        printf("\nA Distância entre Cidade%d e Cidade%d: %d km\n", cidade1, cidade2, distancia);
    } else {
        printf("\nNão há estrada ligando Cidade%d e Cidade%d.\n", cidade1, cidade2);
    }

    return 0;
}