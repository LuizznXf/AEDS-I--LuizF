#include <stdio.h>

void dividirVetor(int vetor[4])
{
    for(int i = 0; i < 4; i++) {
        vetor[i] = vetor[i] / 2;
    }
    for(int i = 0; i < 4; i++) {
        printf("%d\n", vetor[i]);
    }
}

int main()
{
    int vetor[4];
    printf("INFORME OS VALORES DO VETOR:\n");
    for(int i = 0; i < 4; i++) {
        scanf("%d", &vetor[i]);  
    }
    printf("VALORES MODIFICADOS:\n");
    dividirVetor(vetor);

    return 0;
}
