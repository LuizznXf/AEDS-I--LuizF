#include <stdio.h>
#include <stdlib.h>
#define MaxTam 1000

typedef struct {
    float itens[MaxTam];
    int tamanho;
} Lista;

void InicializaLista(Lista *l) {
    l->tamanho = 0;
}

void Inserir(Lista *l, int x) {
    if (l->tamanho == MaxTam) {
        printf("Lista cheia!\n");
        return;
    }

    l->itens[l->tamanho] = x;
    l->tamanho++;
}

void MaiorMenorMedia(Lista *l, int *maior, int *menor, float *media) {
    int i, soma = 0;

    if (l->tamanho == 0) {
        *maior = *menor = 0;
        *media = 0;
        return;
    }

    *maior = *menor = l->itens[0];

    for (i = 0; i < l->tamanho; i++) {
        soma += l->itens[i];

        if (l->itens[i] > *maior)
            *maior = l->itens[i];

        if (l->itens[i] < *menor)
            *menor = l->itens[i];
    }

    *media = (float)soma / l->tamanho;
}

int main() {
    Lista lista;
    int valor, maior, menor;
    float media;

    InicializaLista(&lista);

    printf("Digite valores inteiros (-1 para encerrar):\n");

    while (1) {
        scanf("%d", &valor);

        if (valor == -1)
            break;

        Inserir(&lista, valor);
    }

    MaiorMenorMedia(&lista, &maior, &menor, &media);

    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Media aritmetica: %.2f\n", media);

    return 0;
}