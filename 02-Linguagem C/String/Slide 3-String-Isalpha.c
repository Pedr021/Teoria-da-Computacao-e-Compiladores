
/*Função 'isalpha': 
É uma função dentro da linguagem C que recebe um caractere como parâmetro e retorna 1 se 
ele é uma letra e 0 no caso de não ser. Nesse sentido, podemos utilizar essa estrutura para 
verificação de um nome inserido pelo usuário, de modo a constatar se todos os caracteres que 
ele inseriu são, de fato, caracteres, não englobando, por exemplo, números*/

#include <stdio.h> 
#include <ctype.h> 
int main() 
{ 

 char nome[10]; 
 printf("Digite seu primeiro nome: "); 
 scanf("%s", nome); 

    for (int i = 0; nome[i] != '\0'; i++) { 
    if (isalpha(nome[i])) { 
    printf("%c é uma letra válida.\n", nome[i]); 
    } else { 
    printf("%c não é uma letra.\n", nome[i]); 
    printf("O nome %s inserido não é válido, tente novamente.", nome); 
    break; 
    } 
 } 
 return 0; 
}