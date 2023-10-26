/*A última função desse exercício, ‘isalnum’, é responsável por validar se os caracteres de uma 
string são do tipo alfanuméricos, retornando 1 caso o caractere seja um dígito ou um número, 
e 0 se não for alfanumérico. 
Há diversos cenários que podemos aplicar esta função, como validar se todos os caracteres são 
alfanuméricos em um código de acesso, ou se um título apenas possui caracteres desse tipo. 
 
*/ 

#include <stdio.h> 
#include <ctype.h> 
int main() { 
 
 char codigo[20]; 
 int contador = 0; 
 
 printf("Digite seu código de identificação: "); 
 scanf("%s", codigo); 
 for (int i = 0; codigo[i] != '\0'; i++) { 
 if (isalnum(codigo[i])) { 
 printf("%c é um caractere alfanumérico no código de identificação.\n", codigo[i]); 
 contador++; 
 
 } else { 
 contador = 0; 
 printf("%c não é um caractere alfanumérico e, portanto, este código não é válido.", 
codigo[i]); 
 printf("Gentileza procurar os responsáveis para geração de uma nova identificação."); 
 break; 
 } 
 } 
 if (contador > 0){ 
 printf("O identificador é válido."); 
 } 
 return 0; }