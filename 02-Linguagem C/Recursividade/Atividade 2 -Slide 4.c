/*Nessa questão, devemos criar uma função que soma os números naturais até um índice indicado 
pelo usuário. Por exemplo, se ele digitar 4, a conta que devemos fazer é (1 + 2 + 3+ 4 = 10).
 
*/ 

#include <stdio.h> 
int SomaNaturais(int indice, int contador) { 
 if (indice == 0) { 
 return 0; 
 } 
 
 else { 
 contador++; 
 return contador + SomaNaturais(indice -1, contador); 
 } 
 
} 
int main() { 
 
 int indice; 
 int contador = 0; 
 printf("Digite o número de inteiros subsequentes você deseja somar: "); 
 scanf("%d", &indice); 
 
 int resultado = SomaNaturais(indice, contador); 
 printf("A somatório dos %d primeiros números inteiros é %d", indice, resultado); 
 return 0; 
}