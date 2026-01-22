#include <stdio.h>
#include <stdlib.h>

#define MaxF1 1000
#define MaxF2 1000
#define MaxF3 2000

typedef struct {
    int valor;
} Item;

typedef struct {
    Item itens[MaxF3]; 
    int Frente;
    int Tras;
    int MaxTam;
} Fila;

void InicializaFila(Fila *f, int max) {
    f->Frente = 0;
    f->Tras = 0;
    f->MaxTam = max;
}

int FilaVazia(Fila *f) {
    return f->Frente == f->Tras;
}

void Enfileira(Fila *f, Item x) {
    if (FilaCheia(f)) {
        printf("Fila cheia!\n");
    } else {
        f->itens[f->Tras] = x;
        f->Tras++;
    }
}

Item Desenfileira(Fila *f) {
    Item x;
    x.valor = -1;

    if (FilaVazia(f)) {
        printf("Fila vazia!\n");
    } else {
        x = f->itens[f->Frente];
        f->Frente++;
    }

    return x;
}

void IntercalaFilas(Fila *f1, Fila *f2, Fila *f3) {
    while (!FilaVazia(f1) || !FilaVazia(f2)) {

        if (!FilaVazia(f1)) {
            Enfileira(f3, Desenfileira(f1));
        }

        if (!FilaVazia(f2)) {
            Enfileira(f3, Desenfileira(f2));
        }
    }
}

int main() {
    Fila f1, f2, f3;
    Item x;
  
    InicializaFila(&f1, MaxF1);
    InicializaFila(&f2, MaxF2);
    InicializaFila(&f3, MaxF3);

  printf("Digite os valores da fila 1 (-1 para encerrar):\n");

    while (1) {
    scanf("%d", &x.valor);

    if (x.valor == -1)
        break;

    Enfileira(&f1, x);
}

  printf("\nDigite os valores da fila 2 (-1 para encerrar):\n");

while (1) {
    scanf("%d", &x.valor);

    if (x.valor == -1)
        break;

    Enfileira(&f2, x);
}

    IntercalaFilas(&f1, &f2, &f3);

    printf("\nFila intercalada:\n");
    while (!FilaVazia(&f3)) {
        x = Desenfileira(&f3);
        printf("%d ", x.valor);
    }

    return 0;
}
