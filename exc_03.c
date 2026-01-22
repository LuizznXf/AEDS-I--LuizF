#include <stdio.h>
#include <stdlib.h>
#define MaxTam 1000

typedef struct {
    int itens[MaxTam];
    int tamanho;
} Lista;

void InicializaLista(Lista *l) {
    l->tamanho = 0;
}

int ListaVazia(Lista *l) {
    return l->tamanho == 0;
}

int ListaCheia(Lista *l) {
    return l->tamanho == MaxTam;
}

void InsereOrdenado(Lista *l, int x) {
    int i;

    if (ListaCheia(l)) {
        printf("Lista cheia!\n");
        return;
    }

    i = l->tamanho - 1;

    while (i >= 0 && l->itens[i] > x) {
        l->itens[i + 1] = l->itens[i];
        i--;
    }

    l->itens[i + 1] = x;
    l->tamanho++;
}

void ImprimeLista(Lista *l) {
    int i;

    for (i = 0; i < l->tamanho; i++) {
        printf("%d ", l->itens[i]);
    }
    printf("\n");
}

int main() {
    Lista lista;
    int valor;

    InicializaLista(&lista);

    printf("Digite valores inteiros (-1 para encerrar):\n");

    while (1) {
        scanf("%d", &valor);

        if (valor == -1)
            break;

        InsereOrdenado(&lista, valor);
    }
 
    printf("\nLista ordenada:\n");
    ImprimeLista(&lista);

    return 0;
}