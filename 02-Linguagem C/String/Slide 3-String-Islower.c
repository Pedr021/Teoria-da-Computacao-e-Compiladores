/*FA função ‘islower’, por sua vez, ao contrário do exemplo anterior, é utilizada para verificarmos 
se em determinada string, algum caractere é minúsculo. Essa função é importante para 
verificarmos entradas em que desejamos que ter caracteres minúsculos, seja de forma parcial 
ou total, como verificação das letras em um endereço de e-mail. 
*/ 


# include <ctype.h> 
#include <stdio.h> 
int main() { 
 
 int contador = 0; 
 char nome[50]; 
 
 printf("Digite seu primeiro nome para inserção no banco de dados(Apenas letras 
minúsculas): "); 
 scanf("%s", nome); 
 for (int i = 0; nome[i] != '\0'; i++) { 
 if (islower(nome[i])) { 
 printf("%c é uma letra minúscula do nome.\n", nome[i]); 
 contador++; 
 
 } else { 
 contador = 0; 
 printf("%c não é uma letra minúscula. Insira o nome de acordo com o padrão da 
empresa.", nome[i]); 
 printf("\nFormato de nome inválido."); 
 break; 
 } 
 } 
 if(contador > 0){ 
 printf("O nome inserido é válido."); 
 } 
 return 0; 
}