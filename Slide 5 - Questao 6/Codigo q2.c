#include <stdio.h> #include <stdbool.h> #include <string.h>

bool verificaPalavra(char *palavra) { int estado = 0;

for (int i = 0; i < strlen(palavra); i++) { char simbolo = palavra[i];

if (estado == 0 && simbolo == 'a') { estado = 1;
} else if (estado == 1 && simbolo == 'a') { estado = 2;
} else if (estado == 2 && simbolo == 'a') { estado = 2;
} else if (simbolo == 'b') { estado = 0;
}
}


return (estado == 0 || estado == 1 || estado == 3);
}


int main() {
char palavra[100];


printf("Digite uma palavra (composta por 'a' e 'b'): "); scanf("%s", palavra);
 
if (verificaPalavra(palavra)) {
printf("A palavra '%s' é aceita pelo AFD.\n", palavra);
} else {
printf("A palavra '%s' não é aceita pelo AFD.\n", palavra);
}


return 0;
}
