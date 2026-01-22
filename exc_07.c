#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *itens;     
    int Frente;
    int Tras;
    int MaxTam;     
} Fila;

void InicializaFila(Fila *f, int tamanhoInicial) {
    f->itens = (int *) malloc(tamanhoInicial * sizeof(int));
    f->Frente = 0;
    f->Tras = 0;
    f->MaxTam = tamanhoInicial;
}

int FilaCheia(Fila *f) {
    return f->Tras == f->MaxTam;
}

void DobraFila(Fila *f) {
    f->MaxTam *= 2;
    f->itens = (int *) realloc(f->itens, f->MaxTam * sizeof(int));
}

void Enfileira(Fila *f, int x) {
    if (FilaCheia(f)) {
        DobraFila(f);
    }

    f->itens[f->Tras] = x;
    f->Tras++;
}

int Desenfileira(Fila *f) {
    int x;

    if (f->Frente == f->Tras) {
        printf("Fila vazia!\n");
        return -1;
    }

    x = f->itens[f->Frente];
    f->Frente++;
    return x;
}

int main() {
    Fila fila;
    int x;

    InicializaFila(&fila, 5);

    printf("Digite valores (-1 para encerrar):\n");

    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        Enfileira(&fila, x);
    }

    printf("\nValores da fila:\n");
    while (fila.Frente != fila.Tras) {
        printf("%d ", Desenfileira(&fila));
    }

    free(fila.itens);
    return 0;
}
