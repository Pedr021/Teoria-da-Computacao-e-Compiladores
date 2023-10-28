#include <stdio.h>

void MQ(int n, int m) {
    printf("[%d, %d] ", n, m);
}

void generateMQ(int i, int n, int m) {
    if (i == 0) {
        MQ(n, m);
    } else {
        generateMQ(i - 1, n, m + 1);
        for (int j = 0; j <= n; j++) {
            MQ(j, m);
        }
    }
}

int main() {
    int i;
    printf("Informe o valor de 'i': ");
    scanf("%d", &i);

    if (i < 0) {
        printf("O valor de 'i' deve ser não negativo.\n");
    } else {
        printf("Conjunto MQ%d: ", i);
        generateMQ(i, 0, 1);
        printf("\n");
    }

    return 0;
}
